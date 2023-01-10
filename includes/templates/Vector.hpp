/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:43:30 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/10 00:25:44 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <cstddef>
# include <algorithm>
# include <limits>

namespace ft
{
	template<typename T, typename Alloc = std::allocator<T> >
	class Vector
	{
		public:
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename allocator_type::difference_type difference_type;
			typedef typename allocator_type::size_type size_type;

			typedef VectorIterator<T> iterator;
			typedef VectorIterator<const T> const_iterator;
			typedef std::reverse_iterator<iterator> reverse_iterator;
			typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

			explicit Vector(const allocator_type& alloc = allocator_type()) :
			_alloc(alloc),
			_size(0),
			_capacity(0),
			_container(NULL)
			{
				return ;
			}

			explicit Vector(size_type n, const value_type& val = value_type(),
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
					const allocator_type &alloc = allocator_type()) :
			_capacity(0),
			_size(0),
			_container(0),
			_alloc(alloc)
			{
				_container = _alloc.allocate(0);
				assign(begin, end);
			};

			Vector(const Vector& x) :
			_alloc(x._alloc),
			_size(x._size),
			_capacity(x._size),
			_container(_alloc.allocate(x._size))
			{
				for (size_type i = 0; i < x._size; i++)
					_alloc.construct(_container + i, x._container[i]);
			}

			~Vector(void)
			{
				clear();
				_alloc.deallocate(_container, _capacity);
			}

			Vector& operator=(const Vector& src)
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

			iterator begin(void)
			{
				return iterator(_container);
			}

			void	clear(void)
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_container + i);
				_size = 0;
			}

		private:
			allocator_type  _alloc;
			size_type       _size;
			size_type       _capacity; // Lenght
			pointer         _container;
			
	};
};

#endif
