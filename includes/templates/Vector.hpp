/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:43:30 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/12 23:40:25 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <cstddef>
# include <algorithm>
# include <limits>

// # include "Iterator.hpp"
# include "../utils.hpp"

namespace ft
{
	template < typename T, typename Alloc = std::allocator<T> >
	class Vector
	{
		public:
			typedef T		value_type;
			typedef Alloc	allocator_type;
			
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			
			typedef typename ft::Iterator<T>::difference_type	difference_type;
			typedef typename ft::Iterator<T>::size_type			size_type;
			typedef typename ft::ConstReverseIterator<T>		const_reverse_iterator;
			typedef typename ft::ReverseIterator<T>				reverse_iterator;
			typedef typename ft::ConstIterator<T>				const_iterator;
			typedef typename ft::Iterator<T>					iterator;

		public:
			explicit Vector(const allocator_type& alloc = allocator_type()) :
			_array(_alloc.allocate(0)),
			_end(_array),
			_size(0),
			_capacity(0),
			_alloc(alloc),
			_endOfContainer(_array)
			{
				return ;
			}
			explicit Vector(size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()) :
			_array(_alloc.allocate(n)),
			_end(_array + n),
			_size(n),
			_capacity(n),
			_alloc(alloc),
			_endOfContainer(_array + n)
			{
				return ;
			}

			template <class InputIterator>
			Vector(InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type()) :
			_array(_alloc.allocate(last - first)),
			_end(_array + (last - first)),
			_size(last - first),
			_capacity(last - first),
			_alloc(alloc),
			_endOfContainer(_array + (last - first))
			{
				for (size_type i = 0; i < _size; i++)
					_array[i] = *first++;

				return ;
			}

			Vector(const Vector& src) :
			_array(_alloc.allocate(x._size)),
			_end(_array + x._size),
			_size(x._size),
			_capacity(x._size),
			_alloc(x._alloc),
			_endOfContainer(_array + x._size)
			{
				for (size_type i = 0; i < _size; i++)
					_array[i] = x._array[i];

				return ;
			}
			
			~Vector()
			{
				_alloc.deallocate(_array, _capacity);

				return ;
			}

			Vector& operator=(const Vector& src)
			{
				if (this != &x)
				{
					clear();
					_alloc = src.allocate(src._size);
					_array = _alloc.allocate(x._size);
					_end = _array + x._size;
					_size = 0;
					_capacity = 0;
					_endOfContainer = _array + x._size;
					
					for (size_type i = 0; i < _size; i++)
						_array[i] = src._array[i];
				}
				
				return *this;
			}

			// iterator begin();

			// const_iterator begin() const;

			// iterator end();

			// const_iterator end() const;

			// reverse_iterator rbegin();
			
			// const_reverse_iterator rbegin() const;

			// reverse_iterator rend();
			
			// const_reverse_iterator rend() const;

			// size_type size() const;

			// size_type max_size() const;

			// void resize (size_type n, value_type val = value_type());

			// size_type capacity() const;

			// bool empty() const;

			// void reserve (size_type n);

			// reference operator[] (size_type n);
			
			// const_reference operator[] (size_type n) const;

			// reference at (size_type n);
			
			// const_reference at (size_type n) const;
			
			// reference front();
			
			// const_reference front() const;

			// reference back();
			
			// const_reference back() const;

			// template <class InputIterator> void assign (InputIterator first, InputIterator last);
			
			// void assign (size_type n, const value_type& val);

			// void push_back (const value_type& val);

			// void pop_back();

			// iterator insert (iterator position, const value_type& val);

			// void insert (iterator position, size_type n, const value_type& val);
			
			// template <class InputIterator>
			// void insert (iterator position, InputIterator first, InputIterator last);

			// iterator erase (iterator position);
			
			// iterator erase (iterator first, iterator last);

			// void clear();

			// void swap(Vector &x);

			// template <class T, class Alloc>
			// bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
			
			// template <class T, class Alloc>
			// bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
			
			// template <class T, class Alloc>
			// bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
			
			// template <class T, class Alloc>
			// bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
			
			// template <class T, class Alloc>
			// bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
			
			// template <class T, class Alloc>
			// bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

			// template <class T, class Alloc>
			// void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);

			
		private:
			allocator_type	_alloc; // object that allocates elements
			
			size_type       _capacity; // size of the storage space currently allocated for the array, expressed in terms of elements
			size_type		_size; // number of elements in the array
			
			pointer			_endOfContainer; // pointer to the end of the storage space currently allocated for the array
			pointer			_array; //  pointer to the first element in the array
			pointer			_end; // pointer to the last element in the array
	};  
};

#endif
