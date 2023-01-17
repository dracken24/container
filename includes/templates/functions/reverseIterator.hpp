/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:16:57 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/16 19:21:31 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

namespace ft
{
    template <class Iterator>
    class reverseIterator
    {
        public:
            typedef Iterator iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename iterator_traits<Iterator>::value_type value_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::pointer pointer;
            typedef typename iterator_traits<Iterator>::reference reference;

            reverseIterator() : _current() {}
            explicit reverseIterator(iterator_type x) : _current(x) {}
            template <class Iter>
            reverseIterator(const reverseIterator<Iter>& rev_it) : _current(rev_it.base()) {}
            iterator_type base() const { return _current; }
            reference operator*() const
            {
                Iterator tmp = _current;
                return *--tmp;
            }
            pointer operator->() const { return &(operator*()); }
            reverseIterator& operator++()
            {
                --_current;
                return *this;
            }
            reverseIterator operator++(int)
            {
                reverseIterator tmp = *this;
                --_current;
                return tmp;
            }
            reverseIterator& operator--()
            {
                ++_current;
                return *this;
            }
            reverseIterator operator--(int)
            {
                reverseIterator tmp = *this;
                ++_current;
                return tmp;
            }
            reverseIterator operator+(difference_type n) const { return reverseIterator(_current - n); }
            reverseIterator& operator+=(difference_type n)
            {
                _current -= n;
                return *this;
            }
            reverseIterator operator-(difference_type n) const { return reverseIterator(_current + n); }
            reverseIterator& operator-=(difference_type n)
            {
                _current += n;
                return *this;
            }
            reference operator[](difference_type n) const { return *(*this + n); }

        protected:
            iterator_type _current;
    };

    template <class Iterator>
    bool operator==(const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
    {
        return lhs.base() == rhs.base();
    }

    template <class Iterator>
    bool operator!=(const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
    {
        return lhs.base() != rhs.base();
    }
    
    template <class Iterator>
    bool operator<(const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
    {
        return lhs.base() > rhs.base();
    }

    template <class Iterator>
    bool operator<=(const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
    {
        return lhs.base() >= rhs.base();
    }
    
    template <class Iterator>
    bool operator>(const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
    {
        return lhs.base() < rhs.base();
    }

    template <class Iterator>
    bool operator>=(const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
    {
        return lhs.base() <= rhs.base();
    }
    
    template <class Iterator>
    reverseIterator<Iterator> operator+(typename reverseIterator<Iterator>::difference_type n, const reverseIterator<Iterator>& rev_it)
    {
        return reverseIterator<Iterator>(rev_it.base() - n);
    }
    
    template <class Iterator>
    typename reverseIterator<Iterator>::difference_type operator-(const reverseIterator<Iterator>& lhs, const reverseIterator<Iterator>& rhs)
    {
        return rhs.base() - lhs.base();
    }

    template <class Iterator>
    class const_reverseIterator
    {
        public:
            typedef Iterator iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename iterator_traits<Iterator>::value_type value_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::pointer pointer;
            typedef typename iterator_traits<Iterator>::reference reference;

            const_reverseIterator() : _current() {}
            explicit const_reverseIterator(iterator_type x) : _current(x) {}
            template <class Iter>
            const_reverseIterator(const const_reverseIterator<Iter>& rev_it) : _current(rev_it.base()) {}
            template <class Iter>
            const_reverseIterator(const reverseIterator<Iter>& rev_it) : _current(rev_it.base()) {}
            iterator_type base() const { return _current; }
            reference operator*() const
            {
                Iterator tmp = _current;
                return *--tmp;
            }
            
            pointer operator->() const 
            {
                return &(operator*());
            }
            
            const_reverseIterator& operator++()
            {
                --_current;
                return *this;
            }
            
            const_reverseIterator operator++(int)
            {
                const_reverseIterator tmp = *this;
                --_current;
                return tmp;
            }
            
            const_reverseIterator& operator--()
            {
                ++_current;
                return *this;
            }
            
            const_reverseIterator operator--(int)
            {
                const_reverseIterator tmp = *this;
                ++_current;
                return tmp;
            }
            
            const_reverseIterator operator+(difference_type n) const
            {
                return const_reverseIterator(_current - n);
            }
            
            const_reverseIterator& operator+=(difference_type n)
            {
                _current -= n;
                return *this;
            }
            
            const_reverseIterator operator-(difference_type n) const
            {
                return const_reverseIterator(_current + n);
            }
           
            const_reverseIterator& operator-=(difference_type n)
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
}
#endif
