/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:43:30 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/11 11:33:48 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <cstddef>
# include <algorithm>
# include <limits>

# include "Iterator.hpp"
# include "../utils.hpp"

namespace ft
{
	template<typename T, typename Alloc = std::allocator<T> >
	class Vector
	{
		public:
			typedef T								value_type;
			typedef Alloc							allocator_type;

			typedef size_t							size_type; 
			typedef std::ptrdiff_t					difference_type;
			typedef value_type&						reference;
			typedef const value_type&				const_reference;
			typedef value_type*						pointer;
			typedef const value_type*				const_pointer;

			typedef normal_iterator<value_type>				iterator;
			typedef normal_iterator<const value_type>		const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			

			explicit Vector(const allocator_type& alloc = allocator_type()) :
			_alloc(alloc),
			_size(0),
			_capacity(0),
			_container(NULL)
			{
				return ;
			}

			explicit Vector(size_type n, const value_type& val = value_type(),	//Constructor fill
							const allocator_type& alloc = allocator_type()) :
			_alloc(alloc),
			_size(n),
			_capacity(n),
			_container(_alloc.allocate(n))
			{
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_container + i, val);
			}

			template <class InputIterator>
			Vector(InputIterator begin, InputIterator end,
					const allocator_type &alloc = allocator_type()) :			//Constructor range
			_alloc(alloc),
			_size(0),
			_capacity(0),
			_container(0)
			{
				_container = _alloc.allocate(0);
				assign(begin, end);
			};

			Vector(const Vector& x) :											//Copy constructor
			_alloc(x._alloc),
			_size(x._size),
			_capacity(x._size),
			_container(_alloc.allocate(x._size))
			{
				for (size_type i = 0; i < x._size; i++)
					_alloc.construct(_container + i, x._container[i]);
			}

			~Vector(void)														//Destructor
			{
				clear();
				_alloc.deallocate(_container, _capacity);
			}

			Vector& operator=(const Vector& src)								//Assignation operator
			{
				if (this != &src)
				{
					clear();
					_alloc.deallocate(_container, _capacity);
					_alloc = src._alloc;
					_size = src._size;
					_capacity = src._size;
					_container = _alloc.allocate(src._size);
					for (size_type i = 0; i < src._size; i++)
						_alloc.construct(_container + i, src._container[i]);
				}
				return *this;
			}

		/********************************************************************************/

			iterator begin(void)									// return iterator to beginning
			{
				return iterator(_container);
			}

			const_iterator begin(void) const						// return const iterator to beginning
			{
				return const_iterator(_container);
			}

			// position

			iterator end(void)										// return iterator to end
			{
				return iterator(_container + _size);
			}

			const_iterator end(void) const							// return const iterator to end
			{
				return const_iterator(_container + _size);
			}

			reverse_iterator rbegin(void)							// return reverse iterator to reverse beginning
			{
				return reverse_iterator(end());
			}

			const_reverse_iterator rbegin(void) const				// return const reverse iterator to reverse beginning
			{
				return const_reverse_iterator(end());
			}

			reverse_iterator rend(void)								// return reverse iterator to reverse end
			{
				return reverse_iterator(begin());
			}

			const_reverse_iterator rend(void) const					// return const reverse iterator to reverse end
			{
				return const_reverse_iterator(begin());
			}

		/********************************************************************************/

			size_type size(void) const												// return size
			{
				return _size;
			}

			size_type max_size(void) const											// return max-size
			{
				return std::numeric_limits<size_type>::max() / sizeof(value_type);
			}

			void	resize(size_type n, value_type val = value_type())				// change size
			{
				if (n > _size)
				{
					if (n > _capacity)
						reserve(n);
					for (size_type i = _size; i < n; i++)
						_alloc.construct(_container + i, val);
				}
				else if (n < _size)
				{
					for (size_type i = n; i < _size; i++)
						_alloc.destroy(_container + i);
				}
				_size = n;
			}

			size_type capacity(void) const					// return size of allocated storage capacity
			{
				return _capacity;
			}

			bool	empty(void) const						// test whether vector is empty
			{
				return (_size == 0);
			}

			void	reserve(size_type n)					// request a change in capacity
			{
				if (n > _capacity)
				{
					pointer tmp = _alloc.allocate(n);
					for (size_type i = 0; i < _size; i++)
					{
						_alloc.construct(tmp + i, _container[i]);
						_alloc.destroy(_container + i);
					}
					_alloc.deallocate(_container, _capacity);
					_container = tmp;
					_capacity = n;
				}
			}

		/********************************************************************************/

			reference operator[](size_type n)					// access element
			{
				return _container[n];
			}

			const_reference operator[](size_type n) const		// access element
			{
				return _container[n];
			}

			reference at(size_type n)							// access element
			{
				if (n >= _size)
					throw std::out_of_range("Vector::at");
				return _container[n];
			}

			const_reference at(size_type n) const				// access element
			{
				if (n >= _size)
					throw std::out_of_range("Vector::at");
				return _container[n];
			}

			reference front(void)								// access first element
			{
				return _container[0];
			}

			const_reference front(void) const					// access first element
			{
				return _container[0];
			}

			reference back(void)								// access last element
			{
				return _container[_size - 1];
			}

			const_reference back(void) const					// access last element
			{
				return _container[_size - 1];
			}
		
			void clear(void)									// clear content
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_container + i);
				_size = 0;
			}

			void	swap(Vector &x)								// swap content
			{
				pointer tmp = _container;
				_container = x._container;
				x._container = tmp;
				size_type tmp_size = _size;
				_size = x._size;
				x._size = tmp_size;
				size_type tmp_capacity = _capacity;
				_capacity = x._capacity;
				x._capacity = tmp_capacity;
			}
			
		/********************************************************************************/
			
			template <class InputIterator>
			void	insert(iterator position, size_type n, const value_type& val)	// insert elements
			{
				if (_size + n > _capacity)
					reserve(_capacity * 2);
				pointer tmp = _alloc.allocate(_capacity);
				for (size_type i = 0; i < position - begin(); i++)
				{
					_alloc.construct(tmp + i, _container[i]);
					_alloc.destroy(_container + i);
				}
				for (size_type i = 0; i < n; i++)
				{
					_alloc.construct(tmp + (position - begin()) + i, val);
				}
				for (size_type i = position - begin(); i < _size; i++)
				{
					_alloc.construct(tmp + i + n, _container[i]);
					_alloc.destroy(_container + i);
				}
				_alloc.deallocate(_container, _capacity);
				_container = tmp;
				_size += n;
			}

			void insert(iterator position, size_type n, const value_type &val)	// insert elements
			{
				if (_size + n > _capacity)
					reserve(_capacity * 2);
				pointer tmp = _alloc.allocate(_capacity);
				for (size_type i = 0; i < position - begin(); i++)
				{
					_alloc.construct(tmp + i, _container[i]);
					_alloc.destroy(_container + i);
				}
				for (size_type i = 0; i < n; i++)
				{
					_alloc.construct(tmp + (position - begin()) + i, val);
				}
				for (size_type i = position - begin(); i < _size; i++)
				{
					_alloc.construct(tmp + i + n, _container[i]);
					_alloc.destroy(_container + i);
				}
				_alloc.deallocate(_container, _capacity);
				_container = tmp;
				_size += n;
			}

			template <class InputIterator>
			iterator insert(iterator position, InputIterator first, InputIterator last)	// insert elements
			{
				size_type n = 0;
				for (InputIterator it = first; it != last; it++)
					n++;
				if (_size + n > _capacity)
					reserve(_capacity * 2);
				pointer tmp = _alloc.allocate(_capacity);
				for (size_type i = 0; i < position - begin(); i++)
				{
					_alloc.construct(tmp + i, _container[i]);
					_alloc.destroy(_container + i);
				}
				for (size_type i = 0; i < n; i++)
				{
					_alloc.construct(tmp + (position - begin()) + i, *first);
					first++;
				}
				for (size_type i = position - begin(); i < _size; i++)
				{
					_alloc.construct(tmp + i + n, _container[i]);
					_alloc.destroy(_container + i);
				}
				_alloc.deallocate(_container, _capacity);
				_container = tmp;
				_size += n;
				return position;
			}

			template <class InputIterator>
			void assign(InputIterator first, InputIterator last)			// assign content
			{
				clear();
				insert(begin(), first, last);
			}

			void	assign(size_type n, const value_type &val)				// assign contest
			{
				clear();
				insert(begin(), n, val);
			}

			void	push_back(const value_type &val)						// add element at the end
			{
				if (_size == _capacity)
					reserve(_capacity * 2);
				_alloc.construct(_container + _size, val);
				_size++;
			}

			void	pop_back(void)											// delete last element
			{
				_alloc.destroy(_container + _size - 1);
				_size--;
			}

			iterator erase (iterator position)								// erase element
			{
				pointer tmp = _alloc.allocate(_capacity);
				for (size_type i = 0; i < position - begin(); i++)
				{
					_alloc.construct(tmp + i, _container[i]);
					_alloc.destroy(_container + i);
				}
				_alloc.destroy(_container + (position - begin()));
				for (size_type i = position - begin() + 1; i < _size; i++)
				{
					_alloc.construct(tmp + i - 1, _container[i]);
					_alloc.destroy(_container + i);
				}
				_alloc.deallocate(_container, _capacity);
				_container = tmp;
				_size--;
				return position;
			}

			iterator erase (iterator first, iterator last)					// erase more than one element
			{
				pointer tmp = _alloc.allocate(_capacity);
				for (size_type i = 0; i < first - begin(); i++)
				{
					_alloc.construct(tmp + i, _container[i]);
					_alloc.destroy(_container + i);
				}
				for (size_type i = last - begin(); i < _size; i++)
				{
					_alloc.construct(tmp + i - (last - first), _container[i]);
					_alloc.destroy(_container + i);
				}
				_alloc.deallocate(_container, _capacity);
				_container = tmp;
				_size -= (last - first);
				return first;
			}

		/********************************************************************************/
			
			// template <class value_type, class allocator_type>
			// bool operator-(const Vector<value_type, allocator_type> &lhs, const Vector<value_type, allocator_type> &rhs)
			// {
			// 	if (lhs.size() != rhs.size())
			// 		return false;
			// 	for (size_t i = 0; i < lhs.size(); i++)
			// 	{
			// 		if (lhs[i] != rhs[i])
			// 			return false;
			// 	}
			// 	return true;
			// }

			// template <class T, class Alloc>
			// bool	operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
			// {
			// 	if (lhs.size() != rhs.size())
			// 		return false;
			// 	for (size_t i = 0; i < lhs.size(); i++)
			// 	{
			// 		if (lhs[i] != rhs[i])
			// 			return false;
			// 	}
			// 	return true;
			// }

			// template <class T, class Alloc>
			// bool	operator!=(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs)
			// {
			// 	return !(lhs == rhs);
			// }

			// template <class T, class Alloc>
			// bool	operator<(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs)
			// {
			// 	size_t i = 0;
			// 	while (i < lhs.size() && i < rhs.size())
			// 	{
			// 		if (lhs[i] < rhs[i])
			// 			return true;
			// 		else if (lhs[i] > rhs[i])
			// 			return false;
			// 		i++;
			// 	}
			// 	if (i == lhs.size() && i != rhs.size())
			// 		return true;
			// 	return false;
			// }

			// template <class T, class Alloc>
			// bool	operator<=(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs)
			// {
			// 	return !(rhs < lhs);
			// }

			// template <class T, class Alloc>
			// bool	operator>(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs)
			// {
			// 	return rhs < lhs;
			// }
			
			// template <class T, class Alloc>
			// bool	operator>=(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs)
			// {
			// 	return !(lhs < rhs);
			// }

			// template <class T, class Alloc>
			// void	swap(Vector<T, Alloc> &x, Vector<T, Alloc> &y)
			// {
			// 	x.swap(y);
			// }

		private:
			allocator_type  _alloc;
			size_type       _size;
			size_type       _capacity; // Lenght
			pointer         _container;
			// pointer			_start;
			// pointer			_end;
			
	};
};

#endif
