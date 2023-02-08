/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:43:30 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/07 18:36:32 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils.hpp"
#include "vectorIterator.hpp"

#include <limits>

namespace ft
{

	template <class T, class Alloc = std::allocator<T>>
	class vector
	{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef typename Alloc::pointer pointer;
		typedef const typename Alloc::pointer const_pointer;
		typedef ft::vector_iterator<value_type> iterator;
		typedef ft::vector_iterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		explicit vector(const allocator_type &alloc = allocator_type())
			: _value(0), _size(0), _capacity(0), _alloc(alloc), _old_capacity(0)
		{
		}

		explicit vector(size_type n, const_reference val = value_type(),
						const allocator_type &alloc = allocator_type())
			: _value(0), _size(0), _capacity(0), _alloc(alloc), _old_capacity(0)
		{
			assign(n, val);
		}

		template <class InputIterator>
		vector(InputIterator first, typename ft::enable_if<!isIntegral<InputIterator>::value, InputIterator>::type last,
			   const allocator_type &alloc = allocator_type())
			: _value(0), _size(0), _capacity(0), _alloc(alloc), _old_capacity(0)
		{
			assign(first, last);
		}

		vector(const vector &rhs)
			: _value(0), _size(0), _capacity(0), _old_capacity(0)
		{
			*this = rhs;
		}

		virtual ~vector(void)
		{
			if (_capacity)
			{
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.destroy(&_value[i]);
				}
				_alloc.deallocate(&_value[-1], _capacity + 2);
			}
		}

		vector &operator=(const vector &rhs)
		{
			if (&rhs != this)
			{
				_alloc = rhs._alloc;
				assign(rhs.begin(), rhs.end());
			}
			return *this;
		}
		iterator begin(void)
		{
			return iterator(_value[0]);
		}
		const_iterator begin(void) const
		{
			return const_iterator(_value[0]);
		}
		iterator end(void)
		{
			return iterator(_value[_size]);
		}
		const_iterator end(void) const
		{
			return const_iterator(_value[_size]);
		}
		reverse_iterator rbegin(void)
		{
			return reverse_iterator(end());
		}
		const_reverse_iterator rbegin(void) const
		{
			return const_reverse_iterator(end());
		}
		reverse_iterator rend(void)
		{
			return reverse_iterator(begin());
		}
		const_reverse_iterator rend(void) const
		{
			return const_reverse_iterator(begin());
		}

		size_type size(void) const
		{
			return _size;
		}
		size_type max_size(void) const
		{
			return _alloc.max_size();
		}
		void resize(size_type n, value_type val = value_type())
		{
			if (n < _size)
				for (size_t i = n; i < _size; i++)
					_alloc.destroy(&_value[i]);
			else if (n > _size)
			{
				insert(end(), n - _size, val);
			}
			_size = n;
		}
		size_type capacity(void) const
		{
			return _capacity;
		}
		bool empty(void) const
		{
			return (_size == 0);
		}
		void reserve(size_type n)
		{
			if (n > _alloc.max_size())
				throw(std::length_error("vector::reserve"));
			if (n > _capacity)
			{
				pointer tmp = &_alloc.allocate(n + 2)[1];

				if (_capacity)
				{
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&tmp[i], _value[i]);
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(&_value[i]);
					_alloc.deallocate(&_value[-1], _capacity + 2);
				}
				_value = tmp;
				_capacity = n;
			}
		}
		reference operator[](size_type n)
		{
			return at(n);
		}
		const_reference operator[](size_type n) const
		{
			return at(n);
		}
		reference at(size_type n)
		{
			if (n >= _size)
				throw std::out_of_range("");
			else
				return _value[n];
		}
		const_reference at(size_type n) const
		{
			if (n >= _size)
				throw std::out_of_range("");
			else
				return _value[n];
		}
		reference front(void)
		{
			return _value[0];
		}
		const_reference front(void) const
		{
			return _value[0];
		}
		reference back(void)
		{
			return _value[_size - 1];
		}
		const_reference back(void) const
		{
			return _value[_size - 1];
		}

		template <class InputIterator>
		void assign(InputIterator first, typename ft::enable_if<!isIntegral<InputIterator>::value, InputIterator>::type last)
		{
			size_type len = last - first;
			_save_old();
			if (_capacity < len)
			{
				_capacity = 0;
				reserve(len);
			}
			size_type i = 0;
			for (InputIterator it = first; it != last; it++)
			{
				_alloc.construct(&_value[i], *it);
				i++;
			}
			_size = i;
			_destroy_dealloc_old();
		}
		void assign(size_type n, const_reference val)
		{
			_save_old();
			if (_capacity < n)
			{
				_capacity = 0;
				reserve(n);
			}
			for (size_type i = 0; i < n; i++)
			{
				_alloc.construct(&_value[i], val);
			}
			_size = n;
			_destroy_dealloc_old();
		}
		void push_back(const_reference val)
		{
			insert(end(), val);
		}
		void pop_back(void)
		{
			erase(end() - 1);
		}
		iterator insert(iterator position, const_reference val)
		{
			size_type diff = position - begin();

			// if (_size == _capacity)
			insert(position, 1, val);
			// else
			// 	insert(position, 1, value_type(val));
			// std::cerr << "INSERTING " << val << " at index " << diff << std::endl;
			return (begin() + diff);
		}
		void insert(iterator position, size_type n, const_reference val)
		{
			size_type diff = position - begin();
			bool new_alloc = _prepare_insert(diff, n);

			for (size_type i = diff; i < diff + n; i++)
			{
				// std::cerr << "INSERTING " << val << " at index " << i << std::endl;
				if (i < _size && !new_alloc)
					_value[i] = val;
				else
					_alloc.construct(&_value[i], val);
			}
			_size += n;
			_destroy_dealloc_old();
		}
		template <class InputIterator>
		void insert(iterator position, InputIterator first, typename ft::enable_if<!isIntegral<InputIterator>::value, InputIterator>::type last)
		{
			size_type diff = position - begin();
			size_type n = last - first;
			bool new_alloc = _prepare_insert(diff, n);

			for (size_type i = diff; i < diff + n; i++)
			{
				// std::cerr << "INSERTING " << *first << " at index " << i << std::endl;
				if (i < _size && !new_alloc)
					_value[i] = *first;
				else
					_alloc.construct(&_value[i], *first);
				first++;
			}
			_size += n;
			_destroy_dealloc_old();
		}
		iterator erase(iterator position)
		{
			for (iterator it = position; it != end() - 1; it++)
			{
				*it = *(it + 1);
			}
			_alloc.destroy(&_value[_size - 1]);
			_size--;
			return position;
		}
		iterator erase(iterator first, iterator last)
		{
			size_type len = last - first;

			for (iterator it = first; it != end() - len; it++)
				*it = *(it + len);
			for (iterator it = end() - len; it != end(); it++)
				_alloc.destroy(&(*it));
			_size -= len;
			return first;
		}
		void swap(vector &x)
		{
			pointer tmp_value;
			size_type tmp;

			tmp = _capacity;
			_capacity = x._capacity;
			x._capacity = tmp;
			tmp = _size;
			_size = x._size;
			x._size = tmp;
			tmp_value = _value;
			_value = x._value;
			x._value = tmp_value;
		}

		void clear(void)
		{
			erase(begin(), end());
		}

	private:
		pointer _value;
		size_type _size;
		size_type _capacity;
		allocator_type _alloc;
		pointer _old_value;
		size_type _old_size;
		size_type _old_capacity;

		void _reserve_no_destroy_move(size_type n, size_type diff, size_type n_new)
		{
			if (n > _alloc.max_size())
				throw(std::length_error("vector::reserve"));
			if (n > _capacity)
			{
				_save_old();
				_value = &_alloc.allocate(n + 2)[1];

				if (_capacity && _size)
				{
					for (size_type i = 0; i < diff; i++)
					{
						_alloc.construct(&_value[i], _old_value[i]);
					}
					for (size_type i = _size - 1; i >= diff; i--)
					{
						// std::cerr << "OLD VALUE : " << _old_value[i] << " PUT AT INDEX " << i + n_new << " FROM INDEX " << i << std::endl;
						_alloc.construct(&_value[i + n_new], _old_value[i]);
						if (!i)
							break;
					}
				}
				_capacity = n;
			}
			else if (_size)
				for (size_type i = _size - 1; i >= diff; i--)
				{
					if (i + n_new < _size)
						_value[i + n_new] = _value[i];
					else
						_alloc.construct(&_value[i + n_new], _value[i]);
					if (!i)
						break;
				}
		}
		void _save_old(void)
		{
			_old_value = _value;
			_old_capacity = _capacity;
			_old_size = _size;
		}
		void _destroy_dealloc_old()
		{
			// std::cerr << "HELLO ???" << std::endl;
			if (_old_capacity)
			{
				for (size_type i = 0; i < _old_size; i++)
				{
					// std::cerr << "AT INDEX " << i << " DESTROYING " << _old_value[i] << std::endl;
					_alloc.destroy(&_old_value[i]);
				}
				if (_old_capacity < _capacity)
					_alloc.deallocate(&_old_value[-1], _old_capacity + 2);
				_old_capacity = 0;
			}
		}
		bool _prepare_insert(size_type diff, size_type n)
		{
			bool new_alloc = false;
			if (_capacity < _size + n)
			{
				if (n == 1 && !_size)
					_reserve_no_destroy_move(1, diff, n);
				else if (_size << 1 < _size + n)
					_reserve_no_destroy_move(_size + n, diff, n);
				else
					_reserve_no_destroy_move(_size << 1, diff, n);
				new_alloc = true;
			}
			else
				_reserve_no_destroy_move(0, diff, n);
			return new_alloc;
		}
	};

	template <class T, class Alloc>
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
	{
		x.swap(y);
	}

	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(lhs > rhs));
	}

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(lhs == rhs || lhs < rhs));
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}

};