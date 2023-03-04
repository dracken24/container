/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:55:09 by dracken24         #+#    #+#             */
/*   Updated: 2023/03/03 20:41:22 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.hpp"

template<typename T>
void	printIs_integral(std::is_integral<T> std, ft::is_integral<T> ft, std::string str)
{
	std::cout << RED << "<---------------------------------------------------------------------->" << std::endl;
	std::cout << GREEN << "ft::is_integral<" << str << "> : " << MAGENTA << ft << std::endl;
	std::cout << YELLOW << "<---------------------------------------------------------------------->" << std::endl;
	std::cout << BLUE << "std::is_integral<" << str << ">: " << MAGENTA << std << std::endl;
	std::cout << YELLOW << "<---------------------------------------------------------------------->\n" << RESET << std::endl;
}

void	is_integralTests(void)
{
	std::cout << std::boolalpha;

	ft::is_integral<bool>					ft_bool;
	ft::is_integral<char>					ft_char;
	ft::is_integral<unsigned char>			ft_uchar;
	ft::is_integral<signed char>			ft_schar;
	ft::is_integral<char16_t>				ft_char16_t;
	ft::is_integral<char32_t>				ft_char32_t;
	ft::is_integral<wchar_t>				ft_wchar_t;
	ft::is_integral<short>					ft_short;
	ft::is_integral<unsigned short>			ft_ushort;
	ft::is_integral<int>					ft_int;
	ft::is_integral<unsigned int>			ft_uint;
	ft::is_integral<long>					ft_long;
	ft::is_integral<unsigned long>			ft_ulong;
	ft::is_integral<long long>				ft_longlong;
	ft::is_integral<unsigned long long>		ft_ulonglong;
	ft::is_integral<float>					ft_float;
	ft::is_integral<double>					ft_double;
	ft::is_integral<long double>			ft_ldouble;
	ft::is_integral<A>						ft_class;
	ft::is_integral<StructA>				ft_struct;

	std::is_integral<bool>					std_bool;
	std::is_integral<char>					std_char;
	std::is_integral<unsigned char>			std_uchar;
	std::is_integral<signed char>			std_schar;
	std::is_integral<char16_t>				std_char16_t;
	std::is_integral<char32_t>				std_char32_t;
	std::is_integral<wchar_t>				std_wchar_t;
	std::is_integral<short>					std_short;
	std::is_integral<unsigned short>		std_ushort;
	std::is_integral<int>					std_int;
	std::is_integral<unsigned int>			std_uint;
	std::is_integral<long>					std_long;
	std::is_integral<unsigned long>			std_ulong;
	std::is_integral<long long>				std_longlong;
	std::is_integral<unsigned long long>	std_ulonglong;
	std::is_integral<float>					std_float;
	std::is_integral<double>				std_double;
	std::is_integral<long double>			std_ldouble;
	std::is_integral<A>						std_class;
	std::is_integral<StructA>				std_struct;

	printIs_integral(std_bool, ft_bool, "bool");
	printIs_integral(std_char, ft_char, "char");
	printIs_integral(std_uchar, ft_uchar, "unsigned char");
	printIs_integral(std_schar, ft_schar, "signed char");
	printIs_integral(std_char16_t, ft_char16_t, "char16_t");
	printIs_integral(std_char32_t, ft_char32_t, "char32_t");
	printIs_integral(std_wchar_t, ft_wchar_t, "wchar_t");
	printIs_integral(std_short, ft_short, "short");
	printIs_integral(std_ushort, ft_ushort, "unsigned short");
	printIs_integral(std_int, ft_int, "int");
	printIs_integral(std_uint, ft_uint, "unsigned int");
	printIs_integral(std_long, ft_long, "long");
	printIs_integral(std_ulong, ft_ulong, "unsigned long");
	printIs_integral(std_longlong, ft_longlong, "long long");
	printIs_integral(std_ulonglong, ft_ulonglong, "unsigned long long");
	printIs_integral(std_float, ft_float, "float");
	printIs_integral(std_double, ft_double, "double");
	printIs_integral(std_ldouble, ft_ldouble, "long double");
	printIs_integral(std_class, ft_class, "class");
	printIs_integral(std_struct, ft_struct, "struct");

	std::string input;
	
	std::cout << "Press ENTER to continue" << std::endl;
	std::getline(std::cin, input);
	std::getline(std::cin, input);
	std::cout << "\e[1;1H\e[2J";
}

template<typename T, typename U>
void	printIs_same(std::is_same<T, U> std, ft::is_same<T, U> ft, std::string str)
{
	std::cout << RED << "<---------------------------------------------------------------------->" << std::endl;
	std::cout << GREEN << "ft::is_same<" << str << "> : " << MAGENTA << ft << std::endl;
	std::cout << YELLOW << "<---------------------------------------------------------------------->" << std::endl;
	std::cout << BLUE << "std::is_same<" << str << ">: " << MAGENTA << std << std::endl;
	std::cout << YELLOW << "<---------------------------------------------------------------------->\n" << RESET << std::endl;
}

void	is_sameTests(void)
{
	std::cout << std::boolalpha;

	ft::is_same<int, bool>					ft_bool;
	ft::is_same<char, char>					ft_char;
	ft::is_same<int, unsigned char>			ft_uchar;
	ft::is_same<int, signed char>			ft_schar;
	ft::is_same<int, char16_t>				ft_char16_t;
	ft::is_same<char32_t, char32_t>			ft_char32_t;
	ft::is_same<int, wchar_t>				ft_wchar_t;
	ft::is_same<int, short>					ft_short;
	ft::is_same<int, unsigned short>		ft_ushort;
	ft::is_same<int, int>					ft_int;
	ft::is_same<int, unsigned int>			ft_uint;
	ft::is_same<long, long>					ft_long;
	ft::is_same<int, unsigned long>			ft_ulong;
	ft::is_same<int, long long>				ft_longlong;
	ft::is_same<int, unsigned long long>	ft_ulonglong;
	ft::is_same<float, float>				ft_float;
	ft::is_same<int, double>				ft_double;
	ft::is_same<int, long double>			ft_ldouble;
	ft::is_same<int, A>						ft_class;
	ft::is_same<StructA, StructA>			ft_struct;

	std::is_same<int, bool>					std_bool;
	std::is_same<char, char>				std_char;
	std::is_same<int, unsigned char>		std_uchar;
	std::is_same<int, signed char>			std_schar;
	std::is_same<int, char16_t>				std_char16_t;
	std::is_same<char32_t, char32_t>		std_char32_t;
	std::is_same<int, wchar_t>				std_wchar_t;
	std::is_same<int, short>				std_short;
	std::is_same<int, unsigned short>		std_ushort;
	std::is_same<int, int>					std_int;
	std::is_same<int, unsigned int>			std_uint;
	std::is_same<long, long>				std_long;
	std::is_same<int, unsigned long>		std_ulong;
	std::is_same<int, long long>			std_longlong;
	std::is_same<int, unsigned long long>	std_ulonglong;
	std::is_same<float, float>				std_float;
	std::is_same<int, double>				std_double;
	std::is_same<int, long double>			std_ldouble;
	std::is_same<int, A>					std_class;
	std::is_same<StructA, StructA>			std_struct;

	printIs_same(std_bool, ft_bool, "int, bool");
	printIs_same(std_char, ft_char, "char, char");
	printIs_same(std_uchar, ft_uchar, "int, unsigned char");
	printIs_same(std_schar, ft_schar, "int, signed char");
	printIs_same(std_char16_t, ft_char16_t, "int, char16_t");
	printIs_same(std_char32_t, ft_char32_t, "char32_t, char32_t");
	printIs_same(std_wchar_t, ft_wchar_t, "int, wchar_t");
	printIs_same(std_short, ft_short, "int, short");
	printIs_same(std_ushort, ft_ushort, "int, unsigned short");
	printIs_same(std_int, ft_int, "int, int");
	printIs_same(std_uint, ft_uint, "int, unsigned int");
	printIs_same(std_long, ft_long, "long, long");
	printIs_same(std_ulong, ft_ulong, "int, unsigned long");
	printIs_same(std_longlong, ft_longlong, "int, long long");
	printIs_same(std_ulonglong, ft_ulonglong, "int, unsigned long long");
	printIs_same(std_float, ft_float, "float, float");
	printIs_same(std_double, ft_double, "int, double");
	printIs_same(std_ldouble, ft_ldouble, "int, long double");
	printIs_same(std_class, ft_class, "int, class");
	printIs_same(std_struct, ft_struct, "struct, struct");

	std::string input;
	
	std::cout << "Press ENTER to continue" << std::endl;
	std::getline(std::cin, input);
	std::getline(std::cin, input);
	std::cout << "\e[1;1H\e[2J";
}
