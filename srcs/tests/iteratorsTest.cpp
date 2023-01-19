/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteratorsTest.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:27:24 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/18 19:10:24 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.hpp"

std::string convertPtrToString(int *ptr)
{
	std::stringstream ss;
	ss << ptr;

	return (ss.str());
}

int		convertStringToHexToInt(std::string str)
{
	int		nbr;

	std::stringstream ss(str);
	ss >> std::hex >> nbr;

	return (nbr / 4);
}

void	printResultInt(int *ptr, int *ptr2, std::string str, std::string str2)
{
	std::string strResult;
	std::string strResult2;
	int			nbr;
	int			nbr2;
	static int	i = 1;

	strResult = convertPtrToString(ptr);
	strResult2 = convertPtrToString(ptr2);
	strResult = strResult.substr(2, 10);
	strResult2 = strResult2.substr(2, 10);
	nbr = convertStringToHexToInt(strResult);
	nbr2 = convertStringToHexToInt(strResult2);
	
	std::cout << YELLOW << "Test it #[" << i << "]: " << str << std::endl;
	std::cout << "----------------------------------------" << RESET  << std::endl;
	std::cout << BLUE << "Pointer                      it: " << MAGENTA << ptr << std::endl;
	std::cout << BLUE << "random_access_iterator<int>: it: "  << MAGENTA << nbr << RESET << std::endl << std::endl;

	std::cout << std::endl;
	std::cout << YELLOW << "Test it2 #[" << i << "]: " << str2 << std::endl;
	std::cout << GREEN << "Pointer                      it2: " << MAGENTA << ptr2 << std::endl;
	std::cout << GREEN << "random_access_iterator<int>: it2: "  << MAGENTA << nbr2 << RESET << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET  << std::endl;
	std::cout << std::endl;

	i++;
}

void    randomAccessIteratorTestInt(void)
{
	std::cout << std::boolalpha;
	
	std::cout << std::endl;
	std::cout << RED << "/************************" << GREEN << " random_access_iterator INT " << RED << "************************/" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET  << std::endl;
	std::cout << std::endl;
	
	ft::random_access_iterator<int>		it(0);
	ft::random_access_iterator<int>		it2(0);
	
	it++;
	it2 += 2;
	printResultInt(it.operator->(), it2.operator->(), "it++", "it2 += 2");
	
	it += 18;
	it2 = it;
	printResultInt(it.operator->(), it2.operator->(), "it += 18", "it2 = it");

	it -= 4;
	it2 += 4;
	printResultInt(it.operator->(), it2.operator->(), "it -= 4", "it2 += 4");
	
	std::cout << BLUE << "it < it2 = " << MAGENTA << (it < it2) << RESET << std::endl;
	std::cout << BLUE << "it > it2 = " << MAGENTA << (it > it2) << RESET << std::endl;
	std::cout << BLUE << "it <= it2 = " << MAGENTA << (it <= it2) << RESET << std::endl;
	std::cout << BLUE << "it >= it2 = " << MAGENTA << (it >= it2) << RESET << std::endl;
	std::cout << BLUE << "it == it2 = " << MAGENTA << (it == it2) << RESET << std::endl;
	std::cout << BLUE << "it != it2 = " << MAGENTA << (it != it2) << RESET << std::endl;
	std::cout << std::endl;

	std::cout << RED << "----------------------------------------------------------------" << RESET  << std::endl;
	std::cout << std::endl;

	it = it2;
	printResultInt(it.operator->(), it2.operator->(), "it = it2", "it = it2");

	std::cout << BLUE << "it < it2 = " << MAGENTA << (it < it2) << RESET << std::endl;
	std::cout << BLUE << "it > it2 = " << MAGENTA << (it > it2) << RESET << std::endl;
	std::cout << BLUE << "it <= it2 = " << MAGENTA << (it <= it2) << RESET << std::endl;
	std::cout << BLUE << "it >= it2 = " << MAGENTA << (it >= it2) << RESET << std::endl;
	std::cout << BLUE << "it == it2 = " << MAGENTA << (it == it2) << RESET << std::endl;
	std::cout << BLUE << "it != it2 = " << MAGENTA << (it != it2) << RESET << std::endl;
	std::cout << std::endl;

	std::cout << RED << "----------------------------------------------------------------" << RESET  << std::endl;
	std::cout << std::endl;
	
	std::cout << GREEN << "END OF TESTS" << RESET << std::endl;
}

/********************************************************************************************************/

std::string convertPtrToStringF(float *ptr)
{
	std::stringstream ss;
	ss << ptr;

	return (ss.str());
}

float	convertStringToHexToFloat(std::string str)
{
	float		nbr;

	std::stringstream ss(str);
	ss >> std::hex >> nbr;

	return (nbr / 4);
}

void	printResultFloat(float *ptr, float *ptr2, std::string str, std::string str2)
{
	std::string strResult;
	std::string strResult2;
	float			nbr;
	float			nbr2;
	static int	i = 1;

	strResult = convertPtrToStringF(ptr);
	strResult2 = convertPtrToStringF(ptr2);
	strResult = strResult.substr(2, 10);
	strResult2 = strResult2.substr(2, 10);
	nbr = convertStringToHexToFloat(strResult);
	nbr2 = convertStringToHexToFloat(strResult2);
	
	std::cout << YELLOW << "Test it #[" << i << "]: " << str << std::endl;
	std::cout << "----------------------------------------" << RESET  << std::endl;
	std::cout << BLUE << "Pointer                      it: " << MAGENTA << ptr << std::endl;
	std::cout << BLUE << "random_access_iterator<float>: it: "  << MAGENTA << nbr << RESET << std::endl << std::endl;

	std::cout << std::endl;
	std::cout << YELLOW << "Test it2 #[" << i << "]: " << str2 << std::endl;
	std::cout << GREEN << "Pointer                      it2: " << MAGENTA << ptr2 << std::endl;
	std::cout << GREEN << "random_access_iterator<float>: it2: "  << MAGENTA << nbr2 << RESET << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET  << std::endl;
	std::cout << std::endl;

	i++;
}

void    randomAccessIteratorTestFloat(void)
{
	std::cout << std::boolalpha;
	
	std::cout << std::endl;
	std::cout << RED << "/************************" << GREEN << " random_access_iterator FLOAT " << RED << "************************/" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET  << std::endl;
	std::cout << std::endl;
	
	ft::random_access_iterator<float>		it(0);
	ft::random_access_iterator<float>		it2(0);
	
	it++;
	it2 += 5.0f;
	printResultFloat(it.operator->(), it2.operator->(), "it++", "it2 += 5");
	
	it += 18.0f;
	it2 = it;
	printResultFloat(it.operator->(), it2.operator->(), "it += 18", "it2 = it");

	it -= 4.0f;
	it2 += 4.0f;
	printResultFloat(it.operator->(), it2.operator->(), "it -= 4", "it2 += 4");
	
	std::cout << BLUE << "it < it2 = " << MAGENTA << (it < it2) << RESET << std::endl;
	std::cout << BLUE << "it > it2 = " << MAGENTA << (it > it2) << RESET << std::endl;
	std::cout << BLUE << "it <= it2 = " << MAGENTA << (it <= it2) << RESET << std::endl;
	std::cout << BLUE << "it >= it2 = " << MAGENTA << (it >= it2) << RESET << std::endl;
	std::cout << BLUE << "it == it2 = " << MAGENTA << (it == it2) << RESET << std::endl;
	std::cout << BLUE << "it != it2 = " << MAGENTA << (it != it2) << RESET << std::endl;
	std::cout << std::endl;

	std::cout << RED << "----------------------------------------------------------------" << RESET  << std::endl;
	std::cout << std::endl;

	it = it2;
	printResultFloat(it.operator->(), it2.operator->(), "it = it2", "it = it2");

	std::cout << BLUE << "it < it2 = " << MAGENTA << (it < it2) << RESET << std::endl;
	std::cout << BLUE << "it > it2 = " << MAGENTA << (it > it2) << RESET << std::endl;
	std::cout << BLUE << "it <= it2 = " << MAGENTA << (it <= it2) << RESET << std::endl;
	std::cout << BLUE << "it >= it2 = " << MAGENTA << (it >= it2) << RESET << std::endl;
	std::cout << BLUE << "it == it2 = " << MAGENTA << (it == it2) << RESET << std::endl;
	std::cout << BLUE << "it != it2 = " << MAGENTA << (it != it2) << RESET << std::endl;
	std::cout << std::endl;

	std::cout << RED << "----------------------------------------------------------------" << RESET  << std::endl;
	std::cout << std::endl;
	
	std::cout << GREEN << "END OF TESTS" << RESET << std::endl;
}

