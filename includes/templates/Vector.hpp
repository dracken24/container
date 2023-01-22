/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:43:30 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/22 12:02:59 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "../container.hpp"

namespace ft
{
	template<typename Iterator>
	std::ptrdiff_t distance(Iterator first, Iterator last)
	{
		std::ptrdiff_t dist = 0;
		while (first != last)
		{
			dist++;
			first++;
		}
		
		return (dist);
	}	

	template < typename T, typename Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T															value_type;
			typedef Alloc														allocator_type;
			
			typedef typename allocator_type::reference							reference;                // T&
			typedef typename allocator_type::const_reference					const_reference;          // const T&
			typedef typename allocator_type::pointer							pointer;                  // T*
			typedef typename allocator_type::const_pointer						const_pointer;            // const T*
			
			typedef ft::random_access_iterator<value_type>						iterator;
			typedef ft::random_access_iterator<const value_type>				const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			
			typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;          // ptrdiff_t
			typedef typename allocator_type::size_type							size_type;                // size_t

		public:
		
			explicit vector(const allocator_type &alloc = allocator_type()) :
			_allocator(alloc),
			_array(NULL),
			_capacity(0),
			_size(0)
			{
				return ;
			}
			
			// Range constructor, fill with default values
			explicit vector(size_type n, const value_type &val = value_type(),
							const allocator_type &alloc = allocator_type()) :
			_array(NULL),
			_size(0),
			_capacity(n),
			_allocator(alloc)
			{
				assign(n, val);
				
				return ;
			}

			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) :
			_allocator(alloc),
			_size(0)
			{
				difference_type n = ft::distance(first, last);
				
				_array = _allocator.allocate(n);
				_capacity = n;
				for (; first != last; first++)
					push_back(*first);

				return ;
			}
			

			vector(const vector &src) :
			_allocator(allocator_type()),
			_array(NULL),
			_capacity(0),
			_size(0)
			{
				assign(src.begin(), src.end());
				
				return ;
			}
			
			~vector()
			{
				clear();
				_allocator.deallocate(_array, _capacity);
				
				return ;
			}

			vector& operator=(const vector &src)
			{
				if (this != &src)
				{
					clear();
					assign(src.begin(), src.end());
				}
				
				return (*this);
			}

			iterator begin()
			{
				return iterator(_array);
			}

			const_iterator begin() const
			{
				return const_iterator(_array);
			}

			iterator end()
			{
				return iterator(_array + _size);
			}

			const_iterator end() const
			{
				return const_iterator(_array + _size);
			}

			reverse_iterator rbegin()
			{
				return reverse_iterator(end());
			}
			
			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(end());
			}

			reverse_iterator rend()
			{
				return reverse_iterator(begin());
			}
			
			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(begin());
			}

			size_type size() const
			{
				return _size;
			}

			size_type max_size() const
			{
				return _allocator.max_size();
			}

			void resize (size_type n, value_type val = value_type())
			{
				if (n > _size)
				{
					if (n > _capacity)
						reserve(n);
					for (size_type i = _size; i < n; i++)
						_allocator.construct(_array + i, val);
				}
				else if (n < _size)
				{
					for (size_type i = n; i < _size; i++)
						_allocator.destroy(_array + i);
				}
				_size = n;
			}

			size_type capacity() const
			{
				return _capacity;
			}

			bool empty() const
			{
				return (_size == 0);
			}

			void reserve (size_type n)
			{
				if (n > _capacity)
				{
					pointer tmp = _allocator.allocate(n);
					for (size_type i = 0; i < _size; i++)
						_allocator.construct(tmp + i, _array[i]);
						
					for (size_type i = 0; i < _size; i++)
						_allocator.destroy(_array + i);
						
					_allocator.deallocate(_array, _capacity);
					_array = tmp;
					_capacity = n;
				}
			}

			reference operator[] (size_type n)
			{
				return _array[n];
			}
			
			const_reference operator[] (size_type n) const
			{
				return _array[n];
			}

			reference at (size_type n)
			{
				if (n >= _size)
					throw std::out_of_range("Vector::at");
					
				return _array[n];
			}
			
			const_reference at (size_type n) const
			{
				if (n >= _size)
					throw std::out_of_range("Vector::at");
					
				return _array[n];
			}
			
			reference front()
			{
				return _array[0];
			}
			
			const_reference front() const
			{
				return _array[0];
			}

			reference back()
			{
				return _array[_size - 1];
			}
			
			const_reference back() const
			{
				return _array[_size - 1];
			}

			template <class InputIterator> void assign (InputIterator first, InputIterator last,
						typename enable_if<!is_integral<InputIterator>::value>::type* = 0)
			{
				if (first == last)
					return ;
				if (_size)
					clear();
					
				for (; first != last; first++)
					push_back(*first);

				return ;
			}
			
			void assign (size_type n, const value_type &val)
			{
				if (_size)
					clear();
				while (n--)
					push_back(val);

				return ;
			}

			void push_back (const value_type &val)
			{
				if (_size == _capacity)
				{
					pointer tmp = _allocator.allocate(_capacity * 2);
					for (size_type i = 0; i < _size; i++)
						_allocator.construct(tmp + i, _array[i]);
						
					_allocator.deallocate(_array, _capacity);
					_array = tmp;
					_capacity *= 2;
				}
				_allocator.construct(_array + _size, val);
				_size++;

				return ;
			}

			void pop_back()
			{
				_allocator.destroy(_array + _size - 1);
				_size--;

				return ;
			}

			iterator insert (iterator position, const value_type &val)
			{
				size_type n = ft::distance(begin(), position);
				insert(position, 1, val);
				
				return (iterator(&_array[n]));
			}

			void insert (iterator position, size_type n, const value_type &val)
			{
				vector tmp(position, end());
				_size -= ft::distance(position, end());
				for (size_type i = 0; i < n; i++)
					push_back(val);
				
				for (iterator it = tmp.begin(); it != tmp.end(); it++)
					push_back(*it);

				return ;
			}
			
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
			{
				vector tmp(position, end());
				_size -= ft::distance(position, end());
				
				for (; first != last; first++)
					push_back(*first);

				for (iterator it = tmp.begin(); it != tmp.end(); it++)
					push_back(*it);
				
				return ;
			}

			iterator erase (iterator position)
			{
				if (empty())
					return (end());
				_allocator.destroy(&(*position));
				
				for (; position + 1 != end(); position++)
					_allocator.construct(&(*position), *(position + 1));
				pop_back();
				
				return (position);
			}
			
			iterator erase (iterator first, iterator last)
			{
				if (empty())
					return (end());
				iterator it = begin();
				iterator rtn = first;
				difference_type dist = last - first;
				while (it != first)
					it++;
				for (; first != last; first++)
					_allocator.destroy(&(*first));
				while (it + dist != end()) {
					_allocator.construct(&(*it), *(it + dist));
					it++;
				}
				while (dist-- > 0)
					pop_back();
				return (rtn);
			}

			void clear()
			{
				while (_size)
					pop_back();

				return ;
			}

			void swap(vector &x)
			{
				pointer tmp = _array;
				_array = x._array;
				x._array = tmp;
				
				size_type tmp2 = _size;
				_size = x._size;
				x._size = tmp2;
				tmp2 = _capacity;
				_capacity = x._capacity;
				x._capacity = tmp2;
				
				allocator_type tmp3 = _allocator;
				_allocator = x._allocator;
				x._allocator = tmp3;

				return ;
			}
			
		private:
			allocator_type	_allocator;		// allocator
			pointer			_array;		// pointer to the array
			size_type		_capacity;	// capacity of the array
			size_type		_size;		// size of the array
	};
	
/************************************ Not member functions **************************************/
	
	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	
	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	
	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	
	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		return (!(rhs < lhs));
	}
	
	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		return (rhs < lhs);
	}
	
	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}


	template <class T, class Alloc>
	void swap (vector<T,Alloc> &x, vector<T,Alloc> &y)
	{
		x.swap(y);
	}	
};

#endif
