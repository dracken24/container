/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:09:40 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/18 19:13:44 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
# include <iostream>
# include <iterator>
# include <ostream>

namespace ft
{
	class input_iterator_tag 
	{

	};
	
	class output_iterator_tag
	{

	};
	
	class forward_iterator_tag       : public input_iterator_tag
	{

	};
	
	class bidirectional_iterator_tag : public forward_iterator_tag
	{

	};

	class random_access_iterator_tag : public bidirectional_iterator_tag
	{
		
	};

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	class iterator
	{
		public:
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;
	};

	template <class Iterator>
	class iterator_traits
	{
		public:
			typedef typename Iterator::difference_type   	difference_type;
			typedef typename Iterator::value_type        	value_type;
			typedef typename Iterator::pointer           	pointer;
			typedef typename Iterator::reference         	reference;
			typedef typename Iterator::iterator_category 	iterator_category;
	};

	template <class T>
	class iterator_traits<T*>
	{
		public:
			typedef ptrdiff_t                           difference_type;
			typedef T                                   value_type;
			typedef T*                                  pointer;
			typedef T&                                  reference;
			typedef ft::random_access_iterator_tag      iterator_category;
	};

	template <class T>
	class iterator_traits<const T*>
	{
		public:
			typedef ptrdiff_t                           difference_type;
			typedef T                                   value_type;
			typedef const T*                            pointer;
			typedef const T&                            reference;
			typedef ft::random_access_iterator_tag      iterator_category;
	};

/***************************************** reverse_iterator **********************************************/

	template <class Iterator>
	class reverse_iterator
	{
		public:
			typedef Iterator iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;

			reverse_iterator() :
			_current()
			{
				return ;
			}
			
			explicit reverse_iterator(iterator_type x) :
			_current(x)
			{
				return ;
			}
			
			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter>& rev_it) :
			_current(rev_it.base())
			{
				return ;
			}
			
			iterator_type base() const
			{
				return _current;
			}
			
			reference operator*() const
			{
				Iterator tmp = _current;
				
				return *--tmp;
			}
			
			pointer operator->() const
			{
				return &(operator*());
			}

			reverse_iterator& operator++()
			{
				--_current;
				
				return *this;
			}
			
			reverse_iterator operator++(int)
			{
				reverse_iterator tmp = *this;
				--_current;
				
				return tmp;
			}
			
			reverse_iterator& operator--()
			{
				++_current;
				
				return *this;
			}

			reverse_iterator operator--(int)
			{
				reverse_iterator tmp = *this;
				++_current;
				
				return tmp;
			}
			
			reverse_iterator operator+(difference_type n) const
			{
				return reverse_iterator(_current - n);
			}
			
			reverse_iterator& operator+=(difference_type n)
			{
				_current -= n;
				
				return *this;
			}
			
			reverse_iterator operator-(difference_type n) const
			{
				return reverse_iterator(_current + n);
			}
			
			reverse_iterator& operator-=(difference_type n)
			{
				_current += n;
				
				return *this;
			}
			
			reference operator[](difference_type n) const
			{
				return *(*this + n);
			}

		protected:
			iterator_type _current;
	};

	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() != rhs.base();
	}
	
	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() >= rhs.base();
	}
	
	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() <= rhs.base();
	}
	
	template <class Iterator>
	reverse_iterator<Iterator> operator+
		(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{
		return reverse_iterator<Iterator>(rev_it.base() - n);
	}
	
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-
		(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return rhs.base() - lhs.base();
	}

/***************************************** random_access_iterator **********************************************/
	template <typename T>
	class random_access_iterator : public iterator<random_access_iterator_tag, T>
	{
		public:
			typedef typename iterator<random_access_iterator_tag, T>::value_type          value_type;
			typedef typename iterator<random_access_iterator_tag, T>::difference_type     difference_type;
			typedef typename iterator<random_access_iterator_tag, T>::pointer             pointer;
			typedef typename iterator<random_access_iterator_tag, T>::reference           reference;
			typedef typename iterator<random_access_iterator_tag, T>::iterator_category   iterator_category;

			random_access_iterator() :
			_ptr(NULL)
			{
				return ;
			}

			random_access_iterator(pointer ptr) :
			_ptr(ptr)
			{
				return ;
			}
			
			random_access_iterator(const random_access_iterator& other) :
			_ptr(other._ptr)
			{
				return ;
			}
			
			~random_access_iterator()
			{
				return ;
			}

			random_access_iterator& operator=(const random_access_iterator& other)
			{
				_ptr = other._ptr;
				
				return *this;
			}

			reference operator*() const
			{
				return *_ptr;
			}
			
			pointer operator->() const
			{
				return _ptr;
			}

			random_access_iterator& operator++()
			{
				++_ptr;
				
				return *this;
			}

			random_access_iterator operator++(int)
			{
				random_access_iterator tmp(*this);
				++_ptr;

				return tmp;
			}

			random_access_iterator& operator--()
			{
				--_ptr;

				return *this;
			}

			random_access_iterator operator--(int)
			{
				random_access_iterator tmp(*this);
				--_ptr;
				
				return tmp;
			}

			random_access_iterator operator+(difference_type n) const
			{
				return random_access_iterator(_ptr + n);
			}

			random_access_iterator& operator+=(difference_type n)
			{
				_ptr += n;
				
				return *this;
			}

			random_access_iterator operator-(difference_type n) const
			{
				return random_access_iterator(_ptr - n);
			}

			random_access_iterator& operator-=(difference_type n)
			{
				_ptr -= n;
				
				return *this;
			}

			reference operator[](difference_type n) const
			{
				return _ptr[n];
			}

			bool operator==(const random_access_iterator& other) const
			{
				return _ptr == other._ptr;
			}
			
			bool operator!=(const random_access_iterator& other) const
			{
				return _ptr != other._ptr;
			}
			
			bool operator<(const random_access_iterator& other) const
			{
				return _ptr < other._ptr;
			}
			
			bool operator<=(const random_access_iterator& other) const
			{
				return _ptr <= other._ptr;
			}
			
			bool operator>(const random_access_iterator& other) const
			{
				return _ptr > other._ptr;
			}
			
			bool operator>=(const random_access_iterator& other) const
			{
				return _ptr >= other._ptr;
			}
			
			
		protected:
			pointer _ptr;
	};

	template <typename T1, typename T2>
	bool operator==(const random_access_iterator<T1>& lhs, const random_access_iterator<T2> &rhs)
	{
		return (lhs.base() == rhs.base());
	}
	
	template <typename T1, typename T2>
	bool operator!=(const random_access_iterator<T1>& lhs, const random_access_iterator<T2> &rhs)
	{
		return (lhs.base() != rhs.base());
	}
	
	template <typename T1, typename T2>
	bool operator<(const random_access_iterator<T1>& lhs, const random_access_iterator<T2> &rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <typename T1, typename T2>
	bool operator<=(const random_access_iterator<T1>& lhs, const random_access_iterator<T2> &rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <typename T1, typename T2>
	bool operator>(const random_access_iterator<T1>& lhs, const random_access_iterator<T2> &rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <typename T1, typename T2>
	bool operator>=(const random_access_iterator<T1>& lhs, const random_access_iterator<T2> &rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <typename T1, typename T2>
	typename random_access_iterator<T1>::difference_type operator-(const random_access_iterator<T1>& lhs,
																	const random_access_iterator<T2> &rhs)
	{
		return (lhs.base() - rhs.base());
	}

	template <typename T1, typename T2>
	random_access_iterator<T1> operator+(typename random_access_iterator<T1>::difference_type n,
										const random_access_iterator<T2>& it)
	{
		return random_access_iterator<T1>(it.base() + n);
	}
};
#endif
