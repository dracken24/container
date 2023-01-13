/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:09:40 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/12 23:41:06 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
# include <iostream>
# include <iterator>

namespace ft
{
	template<class Category, class Tp, class Distance = std::ptrdiff_t,
		class Pointer = Tp*, class Reference = Tp &>
	struct iterator
	{
		typedef Tp			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
		
		iterator() : _m_ptr(pointer())
		{
			return ;
		}

		iterator(pointer ptr): _m_ptr(ptr)
		{
			return ;
		}

		iterator(const Tp& i) : _m_ptr(i)
		{
			return ;
		}
		
		// iterator	operator iterator<const Tp> () const
		// {
		// 	return (iterator<const Tp>(this->_m_ptr));
		// }

		reference	operator*() const throw()
		{
			return *_m_ptr;
		}
		
		pointer		operator->() const throw()
		{
			return _m_ptr;
		}
		
		reference	operator[](size_t n) const
		{
			return *(_m_ptr + n);
		}

		iterator &operator++() throw()
		{
			++_m_ptr;
			
			return *this;
		}
		
		iterator operator++(int) throw()
		{
			iterator tmp = *this;
			++_m_ptr; 
			
			return tmp;
		}

		iterator &operator--() throw()
		{
			_m_ptr -= 1;
			
			return *this;
		}
		
		iterator operator--(int) throw()
		{
			iterator tmp = *this;
			--_m_ptr;
			
			return tmp;
		}

		iterator  operator+ (difference_type n) const
		{
			return _m_ptr + n;
		}
		
		iterator& operator+=(difference_type n)
		{
			_m_ptr += n;
			
			return *this;
		}
		
		iterator  operator-(difference_type n) const
		{
			return _m_ptr - n;
		}
		
		iterator& operator-=(difference_type n)
		{
			_m_ptr -= n;
			
			return *this;
		}

		pointer base() const
		{
			return _m_ptr;
		}

	protected:
		pointer _m_ptr;
	};

	template < typename Iterator >
    struct iterator_traits
    {
        typedef typename Iterator::iterator_category   iterator_category;
        typedef typename Iterator::value_type          value_type;
        typedef typename Iterator::difference_type     difference_type;
        typedef typename Iterator::pointer             pointer;
        typedef typename Iterator::reference           reference;
    };

	template < typename Iterator, typename Container >
    class normal_iterator
    {

    private:
        Iterator                                        _Elem;
        typedef iterator_traits<Iterator>               _traits_type;

    public:
        typedef Iterator                                iterator_type;
        typedef typename _traits_type::iterator_category iterator_category;
        typedef typename _traits_type::value_type       value_type;
        typedef typename _traits_type::difference_type  difference_type;
        typedef typename _traits_type::pointer          pointer;
        typedef typename _traits_type::reference        reference;

        //Default Constructor
        normal_iterator() : _Elem(iterator_type())
		{
			return ;
		}

        //Copy Constructor
        explicit normal_iterator(const iterator_type elem) : _Elem(elem)
		{
			return ;
		}

        //iterator to const_iterator conversion
        template < typename Iter >
        normal_iterator(const normal_iterator<Iter, typename enable_if
                        <are_same<Iter, typename Container::pointer>::_value,
                        Container>::_type> &i) : _Elem(i.base())
		{
			return ;
		}

        //Destructor
        ~normal_iterator()
		{
			return ;
		}

        //Assignment operator
        normal_iterator& operator=(const normal_iterator& other)
        {
            _Elem = other._Elem;
			
            return *this;
        }

        //member overloading operator
        reference operator*() const
		{
			return *_Elem;
		}

        pointer operator->() const
		{
			return _Elem;
		}

        normal_iterator& operator++()
        {
            ++_Elem;
            return *this;
        }

        normal_iterator operator++(int)
		{
			return normal_iterator(_Elem++);
		}

        normal_iterator& operator--()
        {
            --_Elem;
			
            return *this;
        }

        normal_iterator operator--(int)
		{
			return normal_iterator(_Elem--);
		}

        reference operator[](difference_type n) 
		{
			return _Elem[n];
		}

        normal_iterator& operator+=(difference_type n)
        {
            _Elem += n;
			
            return *this;
        }

        normal_iterator operator+(difference_type n) const
        { return normal_iterator(_Elem + n); }

        normal_iterator& operator-=(difference_type n)
        {
            _Elem -= n;
			
            return *this;
        }
      
        normal_iterator operator-(difference_type n) const
        { 
			return normal_iterator(_Elem - n);
			}
       
        const iterator_type& base() const
		{
			return _Elem;
		}

    };

	template<class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};


	template<class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator	iterator_type;
		
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iterator>::value_type			value_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::pointer				pointer;
		typedef typename iterator_traits<Iterator>::reference			reference;

		typedef reverse_iterator<Iterator>			iterator;
		typedef reverse_iterator<const Iterator>	const_iterator;

		reverse_iterator() : _current()
		{
			return ;
		}
		
		explicit reverse_iterator(iterator_type x) : _current(x)
		{
			return ;
		}
		
		template<class Iter>
		reverse_iterator(const reverse_iterator<Iter> &x) : _current(x.base())
		{
			return ;
		}
		
		iterator_type base() const
		{
			return _current;
		}
		
		reference operator*() const
		{
			iterator_type tmp = _current;
			return *--tmp;
		}
		
		pointer operator->() const
		{
			return &(operator*());
		}
		
		reverse_iterator &operator++()
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

		reverse_iterator &operator--()
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
		
		reverse_iterator &operator+=(difference_type n)
		{
			_current -= n;
			return *this;
		}
		
		reverse_iterator operator-(difference_type n) const
		{
			return self(_current + n);
		}
		
		reverse_iterator &operator-=(difference_type n)
		{
			_current += n;
			return *this;
		}
		
		reference operator[](difference_type n) const
		{
			return *(*this + n);
		}
		
	private:
		iterator_type _current;
	};
};

#endif
