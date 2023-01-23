/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:44:57 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/23 13:52:47 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include "../templates/Iterator.hpp"

// static class nullptr_t
// {
// 	public:
// 		template<class T>
// 		operator T*() const { return (0); }

// 		template<class C, class T>
// 		operator T C::*() const { return (0); }

// 	private:
// 		void operator&() const;

// } u_nullptr = {};

namespace ft
{
	template <typename T>
	void	swap(T &a, T &b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	};
};
