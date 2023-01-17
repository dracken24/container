/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteratorTraits.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:13:24 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/16 19:16:31 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORTRAITS_HPP
# define ITERATORTRAITS_HPP

# include <iostream>

namespace ft
{
    template <class Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::difference_type   difference_type;
        typedef typename Iterator::value_type        value_type;
        typedef typename Iterator::pointer           pointer;
        typedef typename Iterator::reference         reference;
        typedef typename Iterator::iterator_category iterator_category;
    };

    template <class T>
    struct iterator_traits<T*>
    {
        typedef ptrdiff_t                           difference_type;
        typedef T                                   value_type;
        typedef T*                                  pointer;
        typedef T&                                  reference;
        // *** //
        typedef std::random_access_iterator_tag      iterator_category; // Change for ft::random_access_iterator_tag 
    };

    template <class T>
    struct iterator_traits<const T*>
    {
        typedef ptrdiff_t                           difference_type;
        typedef T                                   value_type;
        typedef const T*                            pointer;
        typedef const T&                            reference;
        // *** //
        typedef std::random_access_iterator_tag      iterator_category; // Change for ft::random_access_iterator_tag 
    };
}

#endif
