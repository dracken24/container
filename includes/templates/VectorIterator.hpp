/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:20:21 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/09 21:16:11 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

# include <iostream>

namespace ft
{
	template <class T>
	class VectorIterator
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
			typedef std::ptrdiff_t difference_type;
			typedef std::random_access_iterator_tag iterator_category;

			VectorIterator(void) :
			_ptr(NULL)
			{
				return ;
			}
			
			VectorIterator(pointer ptr) :
			_ptr(ptr)
			{
				return ;
			}
			
			VectorIterator(VectorIterator const & src)
			{
				*this = src;

				return ;
			}
			
			~VectorIterator(void)
			{
				return ;
			}

			VectorIterator & operator=(VectorIterator const & rhs)
			{
				if (this != &rhs)
					this->_ptr = rhs._ptr;
					
				return *this;
			}

			reference operator*(void) const 
			{
				return *this->_ptr;
			}
			
			pointer operator->(void) const
			{
				return this->_ptr;
			}

			VectorIterator & operator++(void)
			{
				++this->_ptr;
				
				return *this;
			}
			
			VectorIterator operator++(int)
			{
				VectorIterator tmp(*this);
				++this->_ptr;
				
				return tmp;
			}
			
			VectorIterator & operator--(void)
			{
				--this->_ptr;
				
				return *this;
			}
			
			VectorIterator operator--(int)
			{
				VectorIterator tmp(*this);
				--this->_ptr;
				
				return tmp;
			}

			VectorIterator operator+(difference_type n) const
			{
				return VectorIterator(this->_ptr + n);
			}
			
			VectorIterator operator-(difference_type n) const
			{
				return VectorIterator(this->_ptr - n);
			}
			
			VectorIterator & operator+=(difference_type n)
			{
				this->_ptr += n;
				
				return *this;
			}
			
			VectorIterator & operator-=(difference_type n)
			{
				this->_ptr -= n;
				
				return *this;
			}

			reference operator[](difference_type n) const
			{
				return this->_ptr[n];
			}

			friend bool operator==(VectorIterator const & lhs, VectorIterator const & rhs)
			{
				return lhs._ptr == rhs._ptr;
			}

			friend bool operator!=(VectorIterator const & lhs, VectorIterator const & rhs)
			{
				return lhs._ptr != rhs._ptr;
			}

			friend bool operator<(VectorIterator const & lhs, VectorIterator const & rhs)
			{
				return lhs._ptr < rhs._ptr;
			}

			friend bool operator<=(VectorIterator const & lhs, VectorIterator const & rhs)
			{
				return lhs._ptr <= rhs._ptr;
			}

			friend bool operator>(VectorIterator const & lhs, VectorIterator const & rhs)
			{
				return lhs._ptr > rhs._ptr;
			}
			
			friend bool operator>=(VectorIterator const & lhs, VectorIterator const & rhs)
			{
				return lhs._ptr >= rhs._ptr;
			}
			
		protected:
			pointer _ptr;
	};

	
};

#endif
