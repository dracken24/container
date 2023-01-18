/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enableIf.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:11:17 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/16 19:24:31 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLEIF_HPP
# define ENABLEIF_HPP

namespace ft
{
	template <bool B, class T = void>
	struct enable_if
	{

	};

	template <class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
}

#endif
