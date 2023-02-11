/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isIntegral.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:59:56 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/11 11:05:05 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISINTEGRAL_HPP
# define ISINTEGRAL_HPP

#include <iostream>

namespace ft
{
	template <class T>
	struct is_integral
	{
		static const bool value = false;
	};

	template <>
	struct is_integral<bool>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<char>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<signed char>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<unsigned char>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<wchar_t>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<short>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<unsigned short>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<int>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<unsigned int>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<long>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<unsigned long>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<long long>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<unsigned long long>
	{
		static const bool value = true;
	};

	struct true_type {};
	struct false_type {};

	template <typename, typename>
	struct is_same
	{
	typedef bool value_type;
	typedef false_type type;

	static const bool value = false;
	operator bool() {
		return value;
	}
	};

	template <typename T>
	struct is_same<T, T>
	{
	typedef bool value_type;
	typedef false_type type;

	static const bool value = true;
	operator bool() {
		return value;
	}
	};
}

#endif
