/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:09:40 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/11 16:45:04 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
# include <iostream>
# include <iterator>
# include <ostream>

# include "../functions/utils.hpp"
# include "../functions/isIntegral.hpp"
# include "../functions/pair.hpp"


namespace ft
{

//******************************************************************************************************//
//											iterator_traits									    		//
//******************************************************************************************************//

  template <typename Iterator>
	struct iterator_traits
	{
	  typedef typename Iterator::iterator_category iterator_category;
	  typedef typename Iterator::value_type value_type;
	  typedef typename Iterator::difference_type difference_type;
	  typedef typename Iterator::pointer pointer;
	  typedef typename Iterator::reference reference;
	};

	template <typename Tp>
	struct iterator_traits<Tp*>
	{
	  typedef std::random_access_iterator_tag iterator_category;
	  typedef Tp value_type;
	  typedef std::ptrdiff_t difference_type;
	  typedef Tp* pointer;
	  typedef Tp& reference;
	};

	template <typename Tp>
	struct iterator_traits<const Tp*> {
	  typedef std::random_access_iterator_tag iterator_category;
	  typedef Tp value_type;
	  typedef std::ptrdiff_t difference_type;
	  typedef const Tp* pointer;
	  typedef const Tp& reference;
	};
	
//******************************************************************************************************//
//										random_access_iterator								    		//
//******************************************************************************************************//

	template <typename Iterator_type, typename Container>
	class random_access_iterator
	{
	protected:
		Iterator_type	current_;

		typedef iterator_traits<Iterator_type>				traits_type;

	public:
		typedef typename traits_type::iterator_category		iterator_category;
		typedef typename traits_type::value_type			value_type;
		typedef typename traits_type::difference_type		difference_type;
		typedef typename traits_type::reference				reference;
		typedef typename traits_type::pointer				pointer;

		//******************************************************************************************************//
		//										Constructor - Destructor							    		//
		//******************************************************************************************************//

	public:
		random_access_iterator() :
		current_(Iterator_type())
		{
			
		}

		random_access_iterator(const Iterator_type &i) :
		current_(i)
		{
			
		}

		template <typename Iter>
		random_access_iterator(const random_access_iterator<Iter, typename enable_if<(
			is_same<Iter, typename Container::pointer>::value), Container>::type> &i) :
		current_(i.base())
		{
			
		}

		//******************************************************************************************************//
		//										Overload Member Functions							    		//
		//******************************************************************************************************//
		
		reference operator*() const
		{
			return *current_;
		}

		pointer operator->() const
		{
			return current_;
		}

		random_access_iterator &operator=(const random_access_iterator &other)
		{
			current_ = other.current_;
			
			return *this;
		}

		random_access_iterator &operator++()
		{
			++current_;
			
			return *this;
		}

		random_access_iterator operator++(int)
		{
			return random_access_iterator(current_++);
		}

		random_access_iterator &operator--()
		{
			--current_;
			
			return *this;
		}

		random_access_iterator operator--(int)
		{
			return random_access_iterator(current_--);
		}

		reference operator[](difference_type n) const
		{
			return current_[n];
		}

		random_access_iterator &operator+=(difference_type n)
		{
			current_ += n;
			
			return *this;
		}

		random_access_iterator operator+(difference_type elem) const
		{
			return random_access_iterator(current_ + elem);
		}

		random_access_iterator &operator-=(difference_type n)
		{
			current_ -= n;
			
			return *this;
		}

		random_access_iterator operator-(difference_type elem) const
		{
			return random_access_iterator(current_ - elem);
		}

		const Iterator_type& base() const
		{
			return current_;
		}
	};

//******************************************************************************************************//
//										Overload Not Member Functions							   		//
//******************************************************************************************************//

	template <typename IteratorL, typename IteratorR, typename Container>
	bool operator==(const random_access_iterator<IteratorL, Container> &lhs,
		const random_access_iterator<IteratorR, Container> &rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <typename IteratorL, typename IteratorR, typename Container>
	bool operator!=(const random_access_iterator<IteratorL, Container> &lhs,
		const random_access_iterator<IteratorR, Container> &rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <typename IteratorL, typename IteratorR, typename Container>
	bool operator>(const random_access_iterator<IteratorL, Container> &lhs,
		const random_access_iterator<IteratorR, Container> &rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <typename IteratorL, typename IteratorR, typename Container>
	bool operator<(const random_access_iterator<IteratorL, Container> &lhs,
		const random_access_iterator<IteratorR, Container> &rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <typename IteratorL, typename IteratorR, typename Container>
	bool operator>=(const random_access_iterator<IteratorL, Container> &lhs,
		const random_access_iterator<IteratorR, Container> &rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <typename IteratorL, typename IteratorR, typename Container>
	bool operator<=(const random_access_iterator<IteratorL, Container> &lhs,
		const random_access_iterator<IteratorR, Container> &rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <typename Iter1, typename Iter2, typename Container>
	typename random_access_iterator<Iter1, Container>::difference_type operator-(
			const random_access_iterator<Iter1, Container>& lhs, const random_access_iterator<Iter2, Container>& rhs)
	{
		return lhs.base() - rhs.base();
	}

	template <typename Iterator, typename Container>
	random_access_iterator<Iterator, Container> operator+( typename random_access_iterator<Iterator,
		Container>::difference_type lhs, const random_access_iterator<Iterator, Container>& rhs)
	{
		return random_access_iterator<Iterator, Container>(rhs.base() + lhs);
	}

//******************************************************************************************************//
//											reverse_iterator								    		//
//******************************************************************************************************//

	template<typename Iterator_type>
	class reverse_iterator : std::iterator<typename iterator_traits<Iterator_type>::iterator_category,
		typename iterator_traits<Iterator_type>::value_type, typename iterator_traits<Iterator_type>::difference_type,
			typename iterator_traits<Iterator_type>::pointer, typename iterator_traits<Iterator_type>::reference>
	{
		public:
		Iterator_type current;

		public:
		typedef iterator_traits<Iterator_type>				traits_type;
		typedef Iterator_type								Iter;
		typedef typename traits_type::iterator_category		iterator_category;
		typedef typename traits_type::value_type			value_type;
		typedef typename traits_type::difference_type		difference_type;
		typedef typename traits_type::pointer				pointer;
		typedef typename traits_type::reference				reference;

		//******************************************************************************************************//
		//										Constructor - Destructor							    		//
		//******************************************************************************************************//

		public:
		reverse_iterator() :
		current()
		{
			
		}

		explicit reverse_iterator(Iterator_type x) : 
		current(x)
		{
			
		}

		template<typename U>
		reverse_iterator(const reverse_iterator<U> &other) :
		current(other.current)
		{
			
		}

		Iterator_type base() const
		{
			return current;
		}

		//******************************************************************************************************//
		//										Overload Member Functions							    		//
		//******************************************************************************************************//

		template<typename U>
		reverse_iterator &operator=(const reverse_iterator<U> &other)
		{
			current = other.current;
			
			return *this;
		}

		reference operator*() const
		{
			Iter tmp = current;
			
			return *--tmp;
		}

		pointer operator->() const
		{
			return &(operator*());
		}

		reference operator[](difference_type n) const
		{
			return base()[-n-1];
		}

		reverse_iterator &operator++()
		{
			--current;
			
			return *this;
		}

		reverse_iterator &operator--()
		{
			++current;
			
			return *this;
		}

		reverse_iterator operator++(int)
		{
			return reverse_iterator(current--);
		}

		reverse_iterator operator--(int)
		{
			return reverse_iterator(current++);
		}

		reverse_iterator operator+(difference_type n) const
		{
			return reverse_iterator(current - n);
		}

		difference_type operator+(reverse_iterator n) const
		{
			return current - n;
		}

		reverse_iterator operator-(difference_type n) const
		{
			return reverse_iterator(current + n);
		}

		reverse_iterator &operator+=(difference_type n)
		{
			current -= n;

			return *this;
		}

		reverse_iterator &operator-=(difference_type n)
		{
			current += n;
			
			return *this;
		}
	};

//******************************************************************************************************//
//										Overload Not Member Functions							   		//
//******************************************************************************************************//

	template<typename Iterator1, typename Iterator2>
	bool operator==(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<typename Iterator1, typename Iterator2>
	bool operator!=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() != rhs.base();
	}

	template<typename Iterator1, typename Iterator2>
	bool operator<(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() > rhs.base();
	}

	template<typename Iterator1, typename Iterator2>
	bool operator<=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template<typename Iterator1, typename Iterator2>
	bool operator>(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() < rhs.base();
	}

	template<typename Iterator1, typename Iterator2>
	bool operator>=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template<class Iter>
	reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter> &it)
	{
		return reverse_iterator<Iter>(it.base() - n);
	}

	template<class Iter>
	reverse_iterator<Iter> operator-(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter> &it)
	{
		return it.base() + n;
	}

	template <typename Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
		const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (rhs.base() - lhs.base());
	}

	template <typename Iter1, typename Iter2>
	typename reverse_iterator<Iter1>::difference_type operator-(
		const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs)
	{
		return (rhs.base() - lhs.base());
	}	
}

#endif
