/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isIntegral.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:59:56 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/16 19:06:52 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISINTEGRAL_HPP
# define ISINTEGRAL_HPP

#include <iostream>

namespace ft
{
	template <class T>
	struct isIntegral
	{
		static const bool value = false;
	};

	template <>
	struct isIntegral<bool>
	{
		static const bool value = true;
	};

	template <>
	struct isIntegral<char>
	{
		static const bool value = true;
	};

	template <>
	struct isIntegral<signed char>
	{
		static const bool value = true;
	};

	template <>
	struct isIntegral<unsigned char>
	{
		static const bool value = true;
	};

	template <>
	struct isIntegral<wchar_t>
	{
		static const bool value = true;
	};

	template <>
	struct isIntegral<short>
	{
		static const bool value = true;
	};

	template <>
	struct isIntegral<unsigned short>
	{
		static const bool value = true;
	};

	template <>
	struct isIntegral<int>
	{
		static const bool value = true;
	};

	template <>
	struct isIntegral<unsigned int>
	{
		static const bool value = true;
	};

	template <>
	struct isIntegral<long>
	{
		static const bool value = true;
	};

	template <>
	struct isIntegral<unsigned long>
	{
		static const bool value = true;
	};

	template <>
	struct isIntegral<long long>
	{
		static const bool value = true;
	};

	template <>
	struct isIntegral<unsigned long long>
	{
		static const bool value = true;
	};
}

#endif
