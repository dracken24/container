/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:13:12 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/12 20:02:03 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

    template<bool B, typename T = void >
    struct enable_if
	{
		
	};

    template<typename T>
    struct enable_if<true, T>
    {
        typedef T _type;
    };

    template < typename T, T Val >
	struct integral_constant 
	{
		typedef integral_constant   type;
		typedef T                   value_type;
		static const bool           value = Val;
	};

    typedef integral_constant<bool, true>	true_type;
	typedef integral_constant<bool, false>	false_type;
    
	//* ============================= Is_integral =============================
	
	template < typename >
	struct _is_integral_result : public false_type	{};
	
	template <>
	struct _is_integral_result<bool> : public true_type {};
	
	template <>
	struct _is_integral_result<char> : public true_type {};
	
	template <>
	struct _is_integral_result<signed char> : public true_type {};
	
	template <>
	struct _is_integral_result<unsigned char> : public true_type {};
	
	template <>
	struct _is_integral_result<wchar_t> : public true_type {};
	
	template <>
	struct _is_integral_result<short> : public true_type {};
	
	template <>
	struct _is_integral_result<unsigned short> : public true_type {};
	
	template <>
	struct _is_integral_result<int> : public true_type {};
	
	template <>
	struct _is_integral_result<unsigned int> : public true_type {};

	template <>
	struct _is_integral_result<long> : public true_type {};
	
	template <>
	struct _is_integral_result<unsigned long> : public true_type {};

	template < typename T >
	struct is_integral : public _is_integral_result<T> {};

#endif
