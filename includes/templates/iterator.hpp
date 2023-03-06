/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:09:40 by dracken24         #+#    #+#             */
/*   Updated: 2023/03/05 00:13:53 by dracken24        ###   ########.fr       */
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

// void	test(void)
// {
	
// }


namespace ft
{
	struct input_iterator_tag { };	
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };

//******************************************************************************************************//
//											iterator_traits									    		//
//******************************************************************************************************//

  template <typename Iter>
	struct iterator_traits
	{
		typedef typename Iter::difference_type	difference_type;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::pointer			pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};

	template <typename T>
	struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t					difference_type;
		typedef T									value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};

	template <typename T>
	struct iterator_traits<const T*>
	{
		typedef std::ptrdiff_t					difference_type;
		typedef T									value_type;
		typedef const T*							pointer;
		typedef const T&							reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};
	
//******************************************************************************************************//
//										random_access_iterator								    		//
//******************************************************************************************************//

	template <typename iterator_type, typename Container>
	class random_access_iterator
	{
		public:
			typedef iterator_traits<iterator_type>			iter_type;
			
			typedef typename iter_type::iterator_category	iterator_category;
			typedef typename iter_type::value_type			value_type;
			typedef typename iter_type::difference_type		difference_type;
			typedef typename iter_type::reference			reference;
			typedef typename iter_type::pointer				pointer;

		//******************************************************************************************************//
		//										Constructor - Destructor							    		//
		//******************************************************************************************************//

			random_access_iterator() :
			_value(iterator_type())
			{ };

			random_access_iterator(const iterator_type &it) :
			_value(it)
			{ };

			template <typename iter>
			random_access_iterator(const random_access_iterator<iter, typename enable_if<(
				is_same<iter, typename Container::pointer>::value), Container>::type> &it) :
			_value(it.base())
			{ };

		private:
			~random_access_iterator()
			{ };
		
		//******************************************************************************************************//
		//										Overload Not Member Functions							   		//
		//******************************************************************************************************//

		public:
			random_access_iterator &operator=(const random_access_iterator &src)
			{
				if (this != &src)
					_value = src._value;
				
				return (*this);
			}

			reference	operator*()
			{
				return (*_value);
			}

			reference	operator*() const
			{
				return (*_value);
			}

			pointer operator->()
			{
				return (_value);
			}

			pointer operator->() const
			{
				return (_value);
			}

			random_access_iterator	operator+(difference_type src)
			{
				return random_access_iterator(_value + src);
			}

			random_access_iterator	operator++(int)
			{
				return random_access_iterator(_value++);
			}

			random_access_iterator	&operator++()
			{
				return random_access_iterator(&++_value);
			}

			random_access_iterator	&operator+=(difference_type src)
			{
				return random_access_iterator(_value += src);
			}

			random_access_iterator	operator-(difference_type src)
			{
				return random_access_iterator(_value - src);
			}

			random_access_iterator	operator--(int)
			{
				return random_access_iterator(_value--);
			}

			random_access_iterator	&operator--()
			{
				return random_access_iterator(&--_value);
			}

			random_access_iterator	&operator-=(difference_type src)
			{
				return random_access_iterator(_value -= src);
			}

			const iterator_type	&base() const
			{
				return (_value);
			}

		protected:
			iterator_type	_value;
	};

//******************************************************************************************************//
//										Overload Not Member Functions							   		//
//******************************************************************************************************//
	
	template <typename T, typename U, typename Container>
	bool operator==(const random_access_iterator<T, Container> &src1, const random_access_iterator<U, Container> &src2)
	{
		return (src1.base() == src2.base());
	}
	
	template <typename T, typename U, typename Container>
	bool operator!=(const random_access_iterator<T, Container> &src1, const random_access_iterator<U, Container> &src2)
	{
		return (src1.base() != src2.base());
	}

	template <typename T, typename U, typename Container>
	bool operator>(const random_access_iterator<T, Container> &src1, const random_access_iterator<U, Container> &src2)
	{
		return (src1.base() > src2.base());
	}

	template <typename T, typename U, typename Container>
	bool operator>=(const random_access_iterator<T, Container> &src1, const random_access_iterator<U, Container> &src2)
	{
		return (src1.base() >= src2.base());
	}

	template <typename T, typename U, typename Container>
	bool operator<(const random_access_iterator<T, Container> &src1, const random_access_iterator<U, Container> &src2)
	{
		return (src1.base() < src2.base());
	}

	template <typename T, typename U, typename Container>
	bool operator<=(const random_access_iterator<T, Container> &src1, const random_access_iterator<U, Container> &src2)
	{
		return (src1.base() <= src2.base());
	}
	

//******************************************************************************************************//
//											reverse_iterator								    		//
//******************************************************************************************************//

	template<typename iterator_type>
	class reverse_iterator
	{
		public:
			typedef iterator_traits<iterator_type>			iter_type;
			
			typedef typename iter_type::iterator_category	iterator_category;
			typedef typename iter_type::value_type			value_type;
			typedef typename iter_type::difference_type		difference_type;
			typedef typename iter_type::reference			reference;
			typedef typename iter_type::pointer				pointer;

		//******************************************************************************************************//
		//										Constructor - Destructor							    		//
		//******************************************************************************************************//

			reverse_iterator() :
			_value(iterator_type())
			{ };

			reverse_iterator(const iterator_type &it) :
			_value(it)
			{ };

			template <typename T>
			reverse_iterator(const reverse_iterator<T> &src) :
			_value(src._value)
			{ };

		private:
			~reverse_iterator()
			{ };
		
		//******************************************************************************************************//
		//										Overload Not Member Functions							   		//
		//******************************************************************************************************//

		public:
			reverse_iterator &operator=(const reverse_iterator &src)
			{
				if (this != &src)
					_value = src._value;
				
				return (*this);
			}

			reference	operator*()
			{
				return (*_value);
			}

			reference	operator*() const
			{
				return (*_value);
			}

			pointer operator->()
			{
				return (_value);
			}

			pointer operator->() const
			{
				return (_value);
			}

			reverse_iterator	operator+(difference_type src)
			{
				return reverse_iterator(_value - src);
			}

			reverse_iterator	operator++(int)
			{
				return reverse_iterator(_value--);
			}

			reverse_iterator	&operator++()
			{
				return reverse_iterator(&--_value);
			}

			reverse_iterator	&operator+=(difference_type src)
			{
				return reverse_iterator(_value -= src);
			}

			reverse_iterator	operator-(difference_type src)
			{
				return reverse_iterator(_value + src);
			}

			reverse_iterator	operator--(int)
			{
				return reverse_iterator(_value++);
			}

			reverse_iterator	&operator--()
			{
				return reverse_iterator(&++_value);
			}

			reverse_iterator	&operator-=(difference_type src)
			{
				return reverse_iterator(_value += src);
			}

			const iterator_type	&base() const
			{
				return (_value);
			}

		protected:
			iterator_type	_value;
	};

//******************************************************************************************************//
//										Overload Not Member Functions							   		//
//******************************************************************************************************//

	template<typename T, typename U>
	bool operator==(const reverse_iterator<T> &src1, const reverse_iterator<U> &src2)
	{
		return src1.base() == src2.base();
	}

	template<typename T, typename U>
	bool operator!=(const reverse_iterator<T> &src1, const reverse_iterator<U> &src2)
	{
		return src1.base() != src2.base();
	}

	template<typename T, typename U>
	bool operator>(const reverse_iterator<T> &src1, const reverse_iterator<U> &src2)
	{
		return src1.base() > src2.base();
	}

	template<typename T, typename U>
	bool operator>=(const reverse_iterator<T> &src1, const reverse_iterator<U> &src2)
	{
		return src1.base() >= src2.base();
	}

	template<typename T, typename U>
	bool operator<(const reverse_iterator<T> &src1, const reverse_iterator<U> &src2)
	{
		return src1.base() < src2.base();
	}

	template<typename T, typename U>
	bool operator<=(const reverse_iterator<T> &src1, const reverse_iterator<U> &src2)
	{
		return src1.base() <= src2.base();
	}
}

#endif
