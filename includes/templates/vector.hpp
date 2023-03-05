/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:43:30 by dracken24         #+#    #+#             */
/*   Updated: 2023/03/04 22:02:11 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "../functions/utils.hpp"

#include <iostream>
#include <limits>
#include <memory>
#include <iterator>

#include "iterator.hpp"

namespace ft
{
	template <typename T, typename Allocator = std::allocator<T> >
	class vector
	{
		public:

			// [allocator_type](#allocator_type)	A type that represents the allocator class for the vector object.
			typedef Allocator											allocator_type;
			// const_pointer	A type that provides a pointer to a const element in a vector.
			typedef const T*											const_pointer;
			// const_iterator	A type that provides a random-access iterator that can read a const element in a vector.
			typedef std::random_access_iterator_tag						const_iterator;
			// typedef ft::random_access_iterator_tag<const_pointer, vector>		const_iterator;
			
			// value_type	A type that represents the data type stored in a vector.
			typedef T													value_type;
			// const_reference	A type that provides a reference to a const element stored in a vector. It's used for reading and doing const operations.
			typedef const value_type									&const_reference;
			// const_reverse_iterator	A type that provides a random-access iterator that can read any const element in the vector.
			typedef std::reverse_iterator<const_iterator>				const_reverse_iterator;
			// difference_type	A type that provides the difference between the addresses of two elements in a vector.
			typedef std::ptrdiff_t										difference_type;
			// pointer	A type that provides a pointer to an element in a vector.
			typedef T*													pointer;
			// iterator	A type that provides a random-access iterator that can read or modify any element in a vector.
			typedef std::random_access_iterator_tag						iterator;
			// typedef ft::random_access_iterator_tag<pointer, vector>		iterator;
			
			// reference	A type that provides a reference to an element stored in a vector.
			typedef value_type&											reference;
			// reverse_iterator	A type that provides a random-access iterator that can read or modify any element in a reversed vector.
			typedef std::reverse_iterator<iterator>						reverse_iterator;
			// size_type	A type that counts the number of elements in a vector.
			typedef std::size_t											size_type;

			//******************************************************************************************************//
			//										Constructor - Destructor							    		//
			//******************************************************************************************************//

			vector(void) :
			_first(), _end(_first), _capacity(_first), _alloc()
			{ } ;

			explicit	vector(const allocator_type& alloc = allocator_type()) :
			_first(nullptr), _end(_first), _capacity(_first), _alloc(alloc)
			{ };
			
			explicit	vector(size_type size, const value_type& value = value_type(),
				const allocator_type &alloc = allocator_type()) :
			_first(nullptr), _end(_first), _capacity(_first), _alloc(alloc)
			{
				// check the capacity
				//init storage
			};
			
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) :
			_first(nullptr), _end(_first), _capacity(_first), _alloc(alloc)
			{
				// insert
			}
				
			vector (const vector &src) :
			_first(nullptr), _end(_first), _capacity(_first), _alloc(allocator_type())
			{
				// alloc storage with src size
				// insert src values
			}
			
			~vector(void)
			{
				// clear

				// in non null, dealloc
			}
			
			vector& operator=(const vector &src)
			{
				// clear vector
				// dealloc all the capacity of this vector
				// alloc for src values
				// insert all src values
				// return  this
			}

			reference		at(size_type nbr)
			{
				return reference(_first + nbr);
			}
			
			const_reference	at(size_type nbr) const
			{
				return const_reference(_first + nbr);
			}

			reference		front(void)
			{
				return reference(*begin());
			}
			
			const_reference	front(void) const
			{
				return const_reference(*begin());
			}

			reference		back(void)
			{
				return reference(*end() - 1);
			}
			
			const_reference	back(void) const
			{
				return const_reference(*end() - 1);
			}

			//******************************************************************************************************//
			//												Modifiers									    		//
			//******************************************************************************************************//

			// push_back(): This function allows you to add a new element at the end of the vector.
			void	push_back(const value_type &value);

			// pop_back(): It is used to remove or delete the last element from the vector.
			void	pop_back(void);

			// insert(): This function is used to add a new element before a specified position inside the vector.
			iterator	insert(iterator position, const value_type &value);

			void		insert(iterator position, size_type nbr, const value_type &value);
			
			template <class InputIterator>
			void		insert(iterator position, InputIterator first, InputIterator last);

			// erase(): It is used to remove the element from the container at a specified position or a range.
			iterator	erase(iterator position);
			
			iterator	erase(iterator first, iterator last);

			// swap(): It is used to swap the contents between the vectors, but it should be of the same type.
			void	swap(vector &src);

			// assign(): It is used to assign a new value to the vector by substituting the old value.
			template <class InputIterator>
			void	assign(InputIterator first, InputIterator last);
			
			void	assign(size_type nbr, const value_type &value);
			
			// clear(): This function is used to remove all elements from the vectors.
			void	clear(void)
			{
				if (empty() == false)
					_destroy_storage(_first, _end);
				_end = _first;
			}

			//******************************************************************************************************//
			//												Iterators									    		//
			//******************************************************************************************************//

			// begin(): This function returns the iterator to the first element of the vector container.
			iterator		begin(void)
			{
				return iterator(_first);
			}
			
			const_iterator begin(void) const
			{
				return const_iterator(_first);
			}
			
			// end(): This function returns the iterator to the last element of the vector container.
			iterator		end(void)
			{
				return iterator(_end);
			}

			const_iterator	end(void) const
			{
				return const_iterator(_end);
			}

			// rbegin(): This function is similar to the begin() function; the only difference is that
			// it cannot change or modify the content it is pointing to.
			reverse_iterator		rbegin(void);
			
			const_reverse_iterator	rbegin(void) const;

			// rend(): This function also returns the iterator to the last element of the vector,
			// just like the end() function, but the difference is it cannot modify the content it is pointing to.
			reverse_iterator		rend(void);
			
			const_reverse_iterator	rend(void) const;
			
			//******************************************************************************************************//
			//												Capacity									    		//
			//******************************************************************************************************//

			// size(): This function is used to return the number of elements inside the vector.
			size_type	size(void) const;
			
			// max_size(): It is used to return the maximum size allow in your pc for allocation.
			size_type	max_size(void) const
			{
				return (std::numeric_limits<size_type>::max() / sizeof(value_type));
			}
			
			// resize(n): This function is used to resize the container, i.e., if the given size is greater than nbr,
			// then the extra elements are removed. And if the size is less than n, then some extra elements are added.
			void	resize(size_type nbr, value_type value = value_type());
			
			// capacity(): This function returns the size that is currently allocated to the vector.
			size_type	capacity(void) const;

			void	reserve(size_type size)
			{
				if (size > max_size())
					throw std::length_error("error, no more space. Capacity exed max_size()");
				
				if (size < _capacity)
					return ;
				
				pointer	start = _alloc.allocate(size);

				int i = 0;
				for (; _first + i != _end; ++i)
				{
					_alloc.construct(start + i, *(_first + i));
				}
				pointer	end = start + i;

				clear();

				if (_capacity != _first)
					_alloc.deallocate(_first, _capacity - _first);
				
				_first = start;
				_end = end;
				_capacity = _first + size;
			}
			
			// empty(): It checks whether the vector is empty or not, and it returns true if a vector is empty else it returns false.
			bool	empty(void) const
			{
				return begin() == end();
			}

			const_reference	operator[](size_type nbr) const;

			reference		operator[](size_type nbr);
			
			//******************************************************************************************************//
			//									Private non members functions							    		//
			//******************************************************************************************************//
		
		private:
			void checkCapacity(size_type capacity)
			{
				if (capacity > max_size())
					throw std::length_error("error, no more space. Capacity exed max_size()");
				for (;capacity > _capacity;)
					reserve(_capacity *= 2);
			}
			
		private:
			pointer			_first;
			pointer			_end;
			pointer			_capacity;
			
			allocator_type	_alloc;
	};
	
	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc> &src1, const vector<T,Alloc> &src2);
	
	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc> &src1, const vector<T,Alloc> &src2);
	
	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc> &src1, const vector<T,Alloc> &src2);
	
	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc> &src1, const vector<T,Alloc> &src2);

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc> &src1, const vector<T,Alloc> &src2);

	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc> &src1, const vector<T,Alloc> &src2);

	template <class T, class Alloc>
	void swap(vector<T,Alloc>& x, vector<T,Alloc>& y);
}

#endif
