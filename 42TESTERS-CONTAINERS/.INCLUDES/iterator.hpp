/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:09:40 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/07 18:34:45 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <cstddef>
# include <iostream>
# include <iterator>
# include <ostream>

namespace ft
{

struct input_iterator_tag { };
struct output_iterator_tag { };
struct forward_iterator_tag : public input_iterator_tag { };
struct bidirectional_iterator_tag : public forward_iterator_tag { };
struct random_access_iterator_tag : public bidirectional_iterator_tag { };

template< class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T& >
class iterator
{
	public :

		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;

};

template < class Iter >
class iterator_traits
{
	public :
	
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;

};

template < class T >
class iterator_traits<T*>
{
	public :

		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef const T*							pointer;
		typedef const T&							reference;
		typedef random_access_iterator_tag			iterator_category;
};

template < class Iterator>
class reverse_iterator
{
	public :
		typedef Iterator								iterator_type;
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;

		reverse_iterator(void)
		{
			current = iterator_type();
		}
		explicit reverse_iterator(iterator_type x)
		{
			current = x;
		}
		template< class U >
		reverse_iterator(const reverse_iterator<U> & rhs)
		{
			*this = rhs;
		}
		virtual ~reverse_iterator(void) {}

		template< class U >
		reverse_iterator& operator=( const reverse_iterator<U>& rhs)
		{
			current = rhs.base();
			return *this;
		}
		iterator_type base() const
		{
			return current;
		}
		reference operator*() const
		{
		  iterator_type tmp = current;
		  return(*(--tmp));
		}
		pointer operator->() const
		{
			iterator_type tmp = current;
			return (&(*(--tmp)));
		}
		reference operator[](difference_type n) const
		{
			return (current[-n - 1]);
		}
		reverse_iterator& operator++()
		{
			current--;
			return *this;
		}
		reverse_iterator& operator--()
		{
			current++;
			return *this;
		}
		reverse_iterator operator++(int)
		{
			reverse_iterator tmp = *this;
			++(*this);
			return (tmp);
		}
		reverse_iterator operator--(int)
		{
			reverse_iterator tmp = *this;
			--(*this);
			return (tmp);
		}
		reverse_iterator operator+( difference_type n ) const
		{
			return reverse_iterator(current - n);
		}
		reverse_iterator operator-( difference_type n ) const
		{
			return reverse_iterator(current + n);
		}
		reverse_iterator& operator+=( difference_type n )
		{
			current -= n;
			return *this;
		}
		reverse_iterator& operator-=( difference_type n )
		{
			current += n;
			return *this;
		}

	protected :

		iterator_type	current;
};

template< class Iterator1, class Iterator2 >
bool operator==( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
{
	return lhs.base() == rhs.base();
}
template< class Iterator1, class Iterator2 >
bool operator!=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
{
	return lhs.base() != rhs.base();
}
template< class Iterator1, class Iterator2 >
bool operator>( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
{
	return lhs.base() < rhs.base();
}
template< class Iterator1, class Iterator2 >
bool operator>=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
{
	return lhs.base() <= rhs.base();
}
template< class Iterator1, class Iterator2 >
bool operator<( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
{
	return lhs.base() > rhs.base();
}
template< class Iterator1, class Iterator2 >
bool operator<=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
{
	return lhs.base() >= rhs.base();
}

template< class Iter >
reverse_iterator<Iter>	operator+( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it )
{
	return(reverse_iterator<Iter>(it.base() - n));
}

template< class Iterator >
typename reverse_iterator<Iterator>::difference_type	operator-( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs )
{
	return (rhs.base() - lhs.base());
}

}

/***************************************** random_access_iterator **********************************************/
	
	// template <typename T>
	// class random_access_iterator : public iterator<std::random_access_iterator_tag, T>
	// {
	// 	public:
	// 		typedef typename iterator<random_access_iterator_tag, T>::value_type          value_type;
	// 		typedef typename iterator<random_access_iterator_tag, T>::difference_type     difference_type;
	// 		typedef typename iterator<random_access_iterator_tag, T>::pointer             pointer;
	// 		typedef typename iterator<random_access_iterator_tag, T>::reference           reference;
	// 		typedef typename iterator<random_access_iterator_tag, T>::iterator_category   iterator_category;

	// 		random_access_iterator() :
	// 		_ptr(NULL)
	// 		{
	// 			return ;
	// 		}

	// 		random_access_iterator(pointer ptr) :
	// 		_ptr(ptr)
	// 		{
	// 			return ;
	// 		}
			
	// 		random_access_iterator(const random_access_iterator &other) :
	// 		_ptr(other._ptr)
	// 		{
	// 			return ;
	// 		}
			
	// 		~random_access_iterator(void)
	// 		{
	// 			return ;
	// 		}

	// 		random_access_iterator& operator=(const random_access_iterator &other)
	// 		{
	// 			_ptr = other._ptr;
				
	// 			return *this;
	// 		}

	// 		pointer	base(void) const
	// 		{
	// 			return _ptr;
	// 		}

	// 		reference operator*(void) const
	// 		{
	// 			return *_ptr;
	// 		}
			
	// 		pointer operator->(void) const
	// 		{
	// 			return _ptr;
	// 		}

	// 		random_access_iterator& operator++(void)
	// 		{
	// 			++_ptr;
				
	// 			return *this;
	// 		}

	// 		random_access_iterator operator++(int)
	// 		{
	// 			random_access_iterator tmp(*this);
	// 			++_ptr;

	// 			return tmp;
	// 		}

	// 		random_access_iterator& operator--(void)
	// 		{
	// 			--_ptr;

	// 			return *this;
	// 		}

	// 		random_access_iterator operator--(int)
	// 		{
	// 			random_access_iterator tmp(*this);
	// 			--_ptr;
				
	// 			return tmp;
	// 		}

	// 		random_access_iterator operator+(difference_type n) const
	// 		{
	// 			return random_access_iterator(_ptr + n);
	// 		}

	// 		random_access_iterator& operator+=(difference_type n)
	// 		{
	// 			_ptr += n;
				
	// 			return *this;
	// 		}

	// 		random_access_iterator operator-(difference_type n) const
	// 		{
	// 			return random_access_iterator(_ptr - n);
	// 		}

	// 		random_access_iterator& operator-=(difference_type n)
	// 		{
	// 			_ptr -= n;
				
	// 			return *this;
	// 		}

	// 		reference operator[](difference_type n) const
	// 		{
	// 			return _ptr[n];
	// 		}

	// 		bool operator==(const random_access_iterator &other) const
	// 		{
	// 			return _ptr == other._ptr;
	// 		}
			
	// 		bool operator!=(const random_access_iterator &other) const
	// 		{
	// 			return _ptr != other._ptr;
	// 		}
			
	// 		bool operator<(const random_access_iterator &other) const
	// 		{
	// 			return _ptr < other._ptr;
	// 		}
			
	// 		bool operator<=(const random_access_iterator &other) const
	// 		{
	// 			return _ptr <= other._ptr;
	// 		}
			
	// 		bool operator>(const random_access_iterator &other) const
	// 		{
	// 			return _ptr > other._ptr;
	// 		}
			
	// 		bool operator>=(const random_access_iterator &other) const
	// 		{
	// 			return _ptr >= other._ptr;
	// 		}
			
			
	// 	protected:
	// 		pointer _ptr;
	// };

	// template <typename T1, typename T2>
	// bool operator==(const random_access_iterator<T1> &lhs, const random_access_iterator<T2> &rhs)
	// {
	// 	return (lhs.base() == rhs.base());
	// }
	
	// template <typename T1, typename T2>
	// bool operator!=(const random_access_iterator<T1> &lhs, const random_access_iterator<T2> &rhs)
	// {
	// 	return (lhs.base() != rhs.base());
	// }
	
	// template <typename T1, typename T2>
	// bool operator<(const random_access_iterator<T1> &lhs, const random_access_iterator<T2> &rhs)
	// {
	// 	return (lhs.base() < rhs.base());
	// }

	// template <typename T1, typename T2>
	// bool operator<=(const random_access_iterator<T1> &lhs, const random_access_iterator<T2> &rhs)
	// {
	// 	return (lhs.base() <= rhs.base());
	// }

	// template <typename T1, typename T2>
	// bool operator>(const random_access_iterator<T1> &lhs, const random_access_iterator<T2> &rhs)
	// {
	// 	return (lhs.base() > rhs.base());
	// }

	// template <typename T1, typename T2>
	// bool operator>=(const random_access_iterator<T1> &lhs, const random_access_iterator<T2> &rhs)
	// {
	// 	return (lhs.base() >= rhs.base());
	// }

	// template <typename T1, typename T2>
	// typename random_access_iterator<T1>::difference_type operator-(const random_access_iterator<T1> &lhs,
	// 																const random_access_iterator<T2> &rhs)
	// {
	// 	return (lhs.base() - rhs.base());
	// }

	// template <typename T1, typename T2>
	// random_access_iterator<T1> operator+(typename random_access_iterator<T1>::difference_type n,
	// 									const random_access_iterator<T2> &it)
	// {
	// 	return random_access_iterator<T1>(it.base() + n);
	// }
// };
