/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:44:57 by dracken24         #+#    #+#             */
/*   Updated: 2023/03/05 14:17:24 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

// #include "../templates/iterator.hpp"
#include "isIntegral.hpp"
#include "pair.hpp"

namespace ft
{
	template <bool B, typename T =  void > 
	struct enable_if
	{ }; 
 
	template <typename T> 
	struct enable_if<true , T> 
	{ 
		typedef T type ; 
	};

	template< typename T, typename U >
	bool	lexicographical_compare( T first1, T last1,
				U first2, U last2 )
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
		{
			if (*first1 < *first2)
				return true;
			if (*first1 > *first2)
				return false;
		}
	
		return (first1 == last1) && (first2 != last2);
	}

	template< typename T, typename U >
	bool	equal( T first1, T last1, U first2 )
	{
		for (; first1 != last1; ++first1, ++first2)
		{
			if ((*first1 != *first2))
				return false;
		}
	
		return true;
	}
};

#endif
