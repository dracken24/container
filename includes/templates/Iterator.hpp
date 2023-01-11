/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:09:40 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/11 12:51:28 by dracken24        ###   ########.fr       */
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

	// template <typename T>
	// struct normal_iterator
	// {
	// 	typedef T			value_type;
	// 	typedef value_type	&reference;
	// 	typedef value_type	*pointer;

	// 	typedef std::random_access_iterator_tag		iterator_category;
	// 	typedef std::ptrdiff_t						difference_type;
		

	// 	normal_iterator() : _m_ptr(pointer())
	// 	{
	// 		return ;
	// 	}
	// 	normal_iterator(pointer ptr): _m_ptr(ptr)
	// 	{
	// 		return ;
	// 	}
		
	// 	normal_iterator(const T& i) : _m_ptr(i)
	// 	{
	// 		return ;
	// 	}

	// 	operator normal_iterator<const T> () const
	// 	{
	// 		return (normal_iterator<const T>(this->_m_ptr));
	// 	}

	// 	reference	operator*() const throw()
	// 	{
	// 		return *_m_ptr;
	// 	}
		
	// 	pointer		operator->() const throw()
	// 	{
	// 		return _m_ptr;
	// 	}
		
	// 	reference	operator[](size_t n) const
	// 	{
	// 		return *(_m_ptr + n);
	// 	}

	// 	normal_iterator &operator++() throw()
	// 	{
	// 		++_m_ptr; return *this;
	// 	}
		
	// 	normal_iterator operator++(int) throw()
	// 	{
	// 		normal_iterator tmp = *this; ++_m_ptr; return tmp;
	// 	}

	// 	normal_iterator &operator--() throw()
	// 	{
	// 		_m_ptr -= 1; return *this;
	// 	}
		
	// 	normal_iterator operator--(int) throw()
	// 	{
	// 		normal_iterator tmp = *this; --_m_ptr; return tmp;
	// 	}

	// 	normal_iterator  operator+ (difference_type n) const
	// 	{
	// 		return _m_ptr + n;
	// 	}
		
	// 	normal_iterator& operator+=(difference_type n)
	// 	{
	// 		_m_ptr += n;
			
	// 		return *this;
	// 	}
		
	// 	normal_iterator  operator- (difference_type n) const
	// 	{
	// 		return _m_ptr - n;
	// 	}
		
	// 	normal_iterator& operator-=(difference_type n)
	// 	{
	// 		_m_ptr -= n; return *this;
	// 	}

	// 	pointer base() const
	// 	{
	// 		return _m_ptr;
	// 	}

	// protected:
	// 	pointer _m_ptr;
	// };
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
        normal_iterator() : _Elem(iterator_type()) {}

        //Copy Constructor
        explicit normal_iterator(const iterator_type elem) : _Elem(elem) {}

        //iterator to const_iterator conversion
        template < typename Iter >
        normal_iterator(const normal_iterator<Iter, typename enable_if
                        <are_same<Iter, typename Container::pointer>::_value,
                        Container>::_type> &i) : _Elem(i.base()) {}

        //Destructor
        ~normal_iterator() {}

        //Assignment operator
        normal_iterator& operator=(const normal_iterator& other)
        {
            _Elem = other._Elem;
            return *this;
        }

        //member overloading operator
        reference operator*() const { return *_Elem; }

        pointer operator->() const { return _Elem; }

        normal_iterator& operator++()
        {
            ++_Elem;
            return *this;
        }

        normal_iterator operator++(int) { return normal_iterator(_Elem++); }

        normal_iterator& operator--()
        {
            --_Elem;
            return *this;
        }

        normal_iterator operator--(int) { return normal_iterator(_Elem--); }

        reference operator[](difference_type n) { return _Elem[n]; }

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
        { return normal_iterator(_Elem - n); }
       
        const iterator_type& base() const { return _Elem; }

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

	template<class Tp>
	struct iterator_traits<Tp*>
	{
		typedef Tp				value_type;
		typedef std::ptrdiff_t	difference_type;
		typedef Tp				*pointer;
		typedef Tp				&reference;
		
		typedef std::random_access_iterator_tag iterator_category;
	};

	template<class Tp>
	struct iterator_traits<const Tp*>
	{
		typedef Tp				value_type;
		typedef std::ptrdiff_t	difference_type;
		typedef const Tp		*pointer;
		typedef const Tp		&reference;
		
		typedef std::random_access_iterator_tag		iterator_category;
	};

	template<class Iterator>
	inline typename iterator_traits<Iterator>::iterator_category
	iterator_category(const Iterator &src)
	{
		typedef typename iterator_traits<Iterator>::iterator_category Category;
		return (Category());
	}

	template<class Iterator>
	inline typename iterator_traits<Iterator>::difference_type*
	distance_type(const Iterator &src)
	{
		return static_cast<typename iterator_traits<Iterator>::difference_type*>(0);
	}

	template<class Iterator>
	inline typename iterator_traits<Iterator>::value_type*
	value_type(const Iterator &src)
	{
		return static_cast<typename iterator_traits<Iterator>::value_type*>(0);
	}

	template<class InputIterator, class Distance>
	inline void advance(InputIterator &i, Distance n, std::input_iterator_tag)
	{
		while (n--)
			++i;
	}

	template<class BidirectionalIterator, class Distance>
	inline void advance(BidirectionalIterator &i, Distance n, std::bidirectional_iterator_tag)
	{
		if (n > 0)
			while (n--)
				++i;
		else
			while (n++)
				--i;
	}

	template<class RandomAccessIterator, class Distance>
	inline void advance(RandomAccessIterator &i, Distance n, std::random_access_iterator_tag)
	{
		i += n;
	}

	template<class InputIterator, class Distance>
	inline void advance(InputIterator &i, Distance n)
	{
		advance(i, n, iterator_category(i));
	}

	template<class InputIterator>
	inline typename iterator_traits<InputIterator>::difference_type
	distance(InputIterator first, InputIterator last)
	{
		typename iterator_traits<InputIterator>::difference_type n = 0;
		while (first != last)
		{
			++first;
			++n;
		}
		return n;
	}

	template<class InputIterator, class Distance>
	inline void distance(InputIterator first, InputIterator last, Distance &n, std::input_iterator_tag)
	{
		while (first != last)
		{
			++first;
			++n;
		}
	}

	template<class RandomAccessIterator, class Distance>
	inline void distance(RandomAccessIterator first, RandomAccessIterator last, Distance &n, std::random_access_iterator_tag)
	{
		n = last - first;
	}

	template<class InputIterator, class Distance>
	inline void distance(InputIterator first, InputIterator last, Distance &n)
	{
		distance(first, last, n, iterator_category(first));
	}

	template<class InputIterator, class Distance>
	inline InputIterator next(InputIterator x, Distance n)
	{
		advance(x, n);
		return x;
	}

	template<class BidirectionalIterator, class Distance>
	inline BidirectionalIterator prev(BidirectionalIterator x, Distance n)
	{
		advance(x, -n);
		return x;
	}

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

	template<class Iterator>
	inline bool operator==(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
	{
		return x.base() == y.base();
	}

	template<class Iterator>
	inline bool operator<(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
	{
		return x.base() > y.base();
	}

	template<class Iterator>
	inline bool operator!=(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
	{
		return !(x == y);
	}

	template<class Iterator>
	inline bool operator>(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
	{
		return y < x;
	}

	template<class Iterator>
	inline bool operator<=(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
	{
		return !(y < x);
	}

	template<class Iterator>
	inline bool operator>=(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
	{
		return !(x < y);
	}

	template<class Iterator>
	inline typename reverse_iterator<Iterator>::difference_type
	operator-(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y)
	{
		return y.base() - x.base();
	}

	template<class Iterator>
	inline reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &x)
	{
		return reverse_iterator<Iterator>(x.base() - n);
	}

	template<class IteratorL, class IteratorR>
	inline bool operator==(const reverse_iterator<IteratorL> &x, const reverse_iterator<IteratorR> &y)
	{
		return x.base() == y.base();
	}

	template<class IteratorL, class IteratorR>
	inline bool operator<(const reverse_iterator<IteratorL> &x, const reverse_iterator<IteratorR> &y)
	{
		return x.base() > y.base();
	}

	template<class IteratorL, class IteratorR>
	inline bool operator!=(const reverse_iterator<IteratorL> &x, const reverse_iterator<IteratorR> &y)
	{
		return !(x == y);
	}

	template<class IteratorL, class IteratorR>
	inline bool operator>(const reverse_iterator<IteratorL> &x, const reverse_iterator<IteratorR> &y)
	{
		return y < x;
	}
	
	template<class IteratorL, class IteratorR>
	inline bool operator<=(const reverse_iterator<IteratorL> &x, const reverse_iterator<IteratorR> &y)
	{
		return !(y < x);
	}
	
	template<class IteratorL, class IteratorR>
	inline bool operator>=(const reverse_iterator<IteratorL> &x, const reverse_iterator<IteratorR> &y)
	{
		return !(x < y);
	}

	template<class IteratorL, class IteratorR>
	inline typename reverse_iterator<IteratorL>::difference_type
	operator-(const reverse_iterator<IteratorL> &x, const reverse_iterator<IteratorR> &y)
	{
		return y.base() - x.base();
	}

	template<class IteratorL, class IteratorR>
	inline reverse_iterator<IteratorL> operator+(typename reverse_iterator<IteratorL>::difference_type n, const reverse_iterator<IteratorR> &x)
	{
		return reverse_iterator<IteratorL>(x.base() - n);
	}

	template<class Iterator>
	inline void swap(reverse_iterator<Iterator> &x, reverse_iterator<Iterator> &y)
	{
		x.swap(y);
	}

	template<class Iterator>
	class reverse_iterator<const Iterator>
	{
	public:
		typedef Iterator															iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category				iterator_category;
		typedef typename iterator_traits<Iterator>::value_type						value_type;
		typedef typename iterator_traits<Iterator>::difference_type					difference_type;
		typedef typename iterator_traits<Iterator>::pointer							pointer;
		typedef typename iterator_traits<Iterator>::reference						reference;

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
			return reverse_iterator(_current + n);
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

	template<class Iterator>
	class reverse_iterator<Iterator *>
	{
	public:
		typedef Iterator															iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category				iterator_category;
		typedef typename iterator_traits<Iterator>::value_type						value_type;
		typedef typename iterator_traits<Iterator>::difference_type					difference_type;
		typedef typename iterator_traits<Iterator>::pointer							pointer;
		typedef typename iterator_traits<Iterator>::reference						reference;
		typedef reverse_iterator<Iterator>											self;

		reverse_iterator() : _current() {}
		
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
		
		self &operator++()
		{
			--_current;
			
			return *this;
		}

		self operator++(int)
		{
			self tmp = *this;
			--_current;
			
			return tmp;
		}
		
		self &operator--()
		{
			++_current;

			return *this;
		}

		self operator--(int)
		{
			self tmp = *this;
			++_current;
			
			return tmp;
		}
		
		self operator+(difference_type n) const
		{
			return self(_current - n);
		}
		
		self &operator+=(difference_type n)
		{
			_current -= n;
			
			return *this;
		}

		self operator-(difference_type n) const
		{
			return self(_current + n);
		}
		
		self &operator-=(difference_type n)
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

	template<class Iterator>
	class reverse_iterator<const Iterator *>
	{
	public:
		typedef Iterator															iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category				iterator_category;
		typedef typename iterator_traits<Iterator>::value_type						value_type;
		typedef typename iterator_traits<Iterator>::difference_type					difference_type;
		typedef typename iterator_traits<Iterator>::pointer							pointer;
		typedef typename iterator_traits<Iterator>::reference						reference;
		typedef reverse_iterator<Iterator>											self;

		reverse_iterator() : _current() {}

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
			return reverse_iterator(_current + n);
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
