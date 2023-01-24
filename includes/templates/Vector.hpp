/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:43:30 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/23 15:04:04 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../functions/utils.hpp"

namespace ft
{
	template <typename T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			
			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef long int										difference_type;
			typedef size_t											size_type;

			typedef T&												reference;
			typedef const T&										const_reference;
			typedef T*												pointer;
			typedef const T*										const_pointer;
			
			typedef typename ft::random_access_iterator<T>			iterator;
			typedef typename ft::random_access_iterator<const T>	const_iterator;

			typedef typename ft::reverse_iterator<T>				reverse_iterator;
			typedef typename ft::reverse_iterator<const T>			const_reverse_iterator;


		public:
		
			explicit vector(const allocator_type& alloc = allocator_type()) :
			_allocator(alloc),
			_size(0),
			_capacity(0)
			{
				_vector = _allocator.allocate(_capacity);
			}

			explicit vector(size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type()) :
			_allocator(alloc),
			_size(n),
			_capacity(n)
			{
				_vector = _allocator.allocate(_capacity);
				
				for (size_type i = 0; i < _size; ++i)
					_allocator.construct(&_vector[i], val);
			}

			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0) :
			_allocator(alloc),
			_size(0)
			{
				InputIterator tmp(first);
				while (tmp++ != last)
					_size++;
				
				_capacity = _size;
				_vector = _allocator.allocate(_capacity);

				for (int i = 0; first != last; ++first, ++i)
					_allocator.construct(&_vector[i], *first);
			}
					
			vector(const vector &x) :
			_allocator(x._allocator),
			_size(x._size),
			_capacity(x._capacity)
			{
				_vector = _allocator.allocate(_capacity);
				
				for (ft::pair<int, const_iterator> i(0, x.begin());
						i.second != x.end(); ++i.first, ++i.second)
					_allocator.construct(&_vector[i.first], *i.second);
			}

			~vector()
			{
				for (iterator it = begin(); it != end(); ++it)
					_allocator.destroy(&(*it));
				_allocator.deallocate(_vector, _capacity);
			}
			
			vector &operator= (const vector &x)
			{
				vector tmp(x);
				swap(tmp);
				
				return *this;
			}

		/*************************************************************************************/
			// Iterators //
			iterator        begin()
			{
				return iterator(_vector);
			}
			
			const_iterator  begin() const
			{
				return const_iterator(_vector);
			}
			
			iterator		end()
			{
				return iterator(_vector + _size);
			}

			const_iterator  end() const
			{
				return const_iterator(_vector + _size);
			}

			reverse_iterator		rbegin()
			{
				return reverse_iterator(_vector + _size - 1);
			}

			const_reverse_iterator	rbegin() const
			{
				return const_reverse_iterator(_vector + _size - 1);
			}
			
			reverse_iterator		rend()
			{
				return reverse_iterator(_vector - 1);
			}
			
			const_reverse_iterator	rend() const
			{
				return const_reverse_iterator(_vector - 1);
			}
		
		/*************************************************************************************/
			// Capacity //
			size_type	size() const
			{
				return _size;
			}
			
			size_type	max_size(void) const
			{
				return allocator_type().max_size();
			}
			
			void resize (size_type n, value_type val = value_type())
			{
				if (n > _capacity)
					reallocateVec(n);
				while (n > _size)
					push_back(val);
				while (n < _size)
					pop_back();
			}

			size_type	capacity() const
			{
				return _capacity;
			}


			bool	empty() const
			{
				return _size == 0;
			}

			void	reserve (size_type n)
			{
				if (n > max_size())
					throw std::length_error("vector");
				if (n > _capacity)
					reallocateVec(n);
			}

		/*************************************************************************************/
			// Access elements //
			reference operator[] (size_type n)
			{
				return _vector[n];
			}
			
			const_reference operator[] (size_type n) const
			{
				return _vector[n];
			}
			
			reference at(size_type n)
			{
				if (!(n < _size))
					throw std::out_of_range("vector");
					
				return _vector[n];
			}

			const_reference at(size_type n) const
			{
				if (!(n < _size))
					throw std::out_of_range("vector");
					
				return _vector[n];
			}
			
			reference front()
			{
				return _vector[0];
			}
			
			const_reference front() const
			{
				return _vector[0];
			}
			
			reference back()
			{
				return _vector[_size - 1];
			}

			const_reference back() const
			{
				return _vector[_size - 1];
			}

		/*************************************************************************************/
			// Modifier //
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,
						typename enable_if<!is_integral<InputIterator>::value >::type* = 0)
			{
				clear();

				size_type n = static_cast<size_type>(last - first);
				if (n > _capacity)
				{
					_allocator.deallocate(_vector, _capacity);
					_vector = _allocator.allocate(n);
				}
				
				size_type i = 0;
				for (; first != last; ++i, ++first)
					_allocator.construct(&_vector[i], *first);
				_size = i;
			}

			void assign (size_type n, const value_type &val)
			{
				clear();

				if (n > _capacity)
				{
					_allocator.deallocate(_vector, _capacity);
					_vector = _allocator.allocate(n);
				}
				
				for (size_type i = 0; i < n; ++i)
					_allocator.construct(&_vector[i], val);
				_size = n;
			}

			void push_back (const value_type &val)
			{
				if (_size + 1 > _capacity)
					reallocateVec(!_capacity ? 1 : _capacity * 2);
				_allocator.construct(&_vector[_size++], val);
			}

			void pop_back()
			{
				if (_size)
					_allocator.destroy(&_vector[_size-- - 1]);
			}
			
			iterator insert (iterator position, const value_type &val)
			{
				difference_type index = position - begin();
				
				insert(position, 1, val);
				
				return iterator(&_vector[index]);
			}

			void insert (iterator position, size_type n, const value_type &val)
			{
				difference_type index = position - begin();
				if (_size + n > _capacity)
					reallocateVec(_capacity + n);

				iterator newPosition(&_vector[index]);
				if (newPosition != end())
					moveElementsToTheRight(newPosition, n);
				
				for (size_type i = 0; i < n; ++i)
					_allocator.construct(&(*newPosition++), val);
				_size += n;
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last, 
						typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
			{
				size_type n = 0;
				InputIterator tmp(first);
				while (tmp++ != last)
					++n;

				difference_type index = position - begin();
				if (_size + n > _capacity)
					reallocateVec(_capacity + n);

				iterator newPosition(&_vector[index]);
				if (newPosition != end())
					moveElementsToTheRight(newPosition, n);

				for (size_type i = 0; i < n; ++i)
					_allocator.construct(&(*newPosition++), *first++);
				_size += n;
			}

			iterator erase (iterator position)
			{
				return erase(position, position + 1);
			}
			
			iterator erase (iterator first, iterator last)
			{
				if (first == end() || first == last)
					return first;
				
				difference_type index = first - begin();
				
				if (last < end())
				{
					moveElementsToTheLeft(first, last);
					_size -= static_cast<size_type>(last - first);
				}
				else
				{
					size_type newSize = _size - static_cast<size_type>(last - first);
					while (_size != newSize)
						pop_back();
				}
				
				return iterator(&_vector[index]);
			}

			void swap (vector& x)
			{
				swap(_allocator, x._allocator);
				swap(_vector, x._vector);
				swap(_size, x._size);
				swap(_capacity, x._capacity);
			}

			void clear()
			{
				while (_size)
					pop_back();
			}
			
		/*************************************************************************************/
			// Overload operators //
			
			friend bool operator==(const vector &lhs, const vector &rhs)
			{
				if (lhs.size() != rhs.size())
					return false;

				for (ft::pair<const_iterator, const_iterator> it(lhs.begin(), rhs.begin());
						it.first != lhs.end(); ++it.first, ++it.second)
				{
					if (*(it.first) != *(it.second))
						return false;
				}
						
				return true;
			}

			friend bool operator!=(const vector &lhs, const vector &rhs)
			{
				return !(lhs == rhs);
			}
			
			friend bool operator<(const vector &lhs, const vector &rhs)
			{
				for (ft::pair<const_iterator, const_iterator> it(lhs.begin(), rhs.begin());
						it.first != lhs.end() && it.second != rhs.end(); ++it.first, ++it.second)
				{
					if (*(it.first) < *(it.second))
						return true;
				}
				
				return (lhs.size() < rhs.size());
			}

			friend bool operator>(const vector &lhs, const vector &rhs)
			{
				return rhs < lhs;
			}

			friend bool operator<=(const vector &lhs, const vector &rhs)
			{
				return !(rhs < lhs);
			}
			
			friend bool operator>=(const vector &lhs, const vector &rhs)
			{
				return !(lhs < rhs);
			}

			friend void swap (vector &x, vector &y)
			{
				 x.swap(y);
			}
			
		/*************************************************************************************/	
		// Private member functions //
		private:

			void reallocateVec(size_type newCapacity)
			{
				pointer tmp = _allocator.allocate(newCapacity);
				for (size_type i = 0; i < _size; ++i)
					_allocator.construct(&tmp[i], _vector[i]);

				this->~vector();
				_capacity = newCapacity;
				_vector = tmp;
			}

			template <typename U>
			void swap(U &a, U &b)
			{
				U tmp = a;
				a = b;
				b = tmp;
			}

			void moveElementsToTheRight(iterator position, size_type move)
			{
				for (ft::pair<iterator, iterator> it(end() - 1, end());
					it.second != position; --it.first, --it.second)
				{
					_allocator.construct(&(*(it.first + move)), *it.first);
					_allocator.destroy(&(*it.first));
				}
			}

			void moveElementsToTheLeft(iterator first, iterator last)
			{
				for (; first != end(); ++first, ++last)
				{
					_allocator.destroy(&(*first));
					
					if (last < end())
						_allocator.construct(&(*(first)), *last);
				}
			}
			
		/*************************************************************************************/	
		private:    
		
			Alloc               _allocator;     // Copy of allocator_type object
			pointer             _vector;        // Pointer on an array of T values
			size_type           _size;          // Number of T values inside the vector
			size_type           _capacity;      // Capacity allocated (can be greater than size)
	};

};