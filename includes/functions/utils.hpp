/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:44:57 by dracken24         #+#    #+#             */
/*   Updated: 2023/03/04 12:52:41 by dracken24        ###   ########.fr       */
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

	template< typename InputIt1, typename InputIt2 >
	bool	lexicographical_compare( InputIt1 first1, InputIt1 last1,
				InputIt2 first2, InputIt2 last2 )
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
		{
			if (*first1 < *first2)
				return true;
			if (*first2 < *first1)
				return false;
		}
	
		return (first1 == last1) && (first2 != last2);
	}

	template< typename InputIt1, typename InputIt2 >
	bool	equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 )
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
