/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteratorsTest.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:27:24 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/19 21:17:41 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.hpp"

// Int tests

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
	
		std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << GREEN << "------------ END TESTS random_access_iterator INT -------------" << RESET << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;
}

/********************************************************************************************************/
// Float tests

std::string	convertStructPtrToString(struct s *ptr)
{
	std::stringstream	ss;
	std::string			str;

	ss << ptr;
	str = ss.str();
	
	return (str);
}

void	printResultStruct(struct s *ptr, struct s *ptr2, std::string str, std::string str2)
{
	std::string	strResult;
	std::string	strResult2;
	int			nbr;
	int			nbr2;
	static int	i = 1;

	strResult = convertStructPtrToString(ptr);
	strResult2 = convertStructPtrToString(ptr2);
	strResult = strResult.substr(2, 10);
	strResult2 = strResult2.substr(2, 10);
	nbr = convertStringToHexToInt(strResult);
	nbr2 = convertStringToHexToInt(strResult2);
	
	std::cout << YELLOW << "Test it #[" << i << "]: " << str << std::endl;
	std::cout << GREEN << "Pointer                      it: " << MAGENTA << ptr << std::endl;
	std::cout << GREEN << "random_access_iterator<int>: it: "  << MAGENTA << nbr << RESET << std::endl << std::endl;
	std::cout << YELLOW << "Test it #[" << i << "]: " << str2 << std::endl;
	std::cout << GREEN << "Pointer                      it2: " << MAGENTA << ptr2 << std::endl;
	std::cout << GREEN << "random_access_iterator<int>: it2: "  << MAGENTA << nbr2 << RESET << std::endl << std::endl;
	i++;
}

void	randomAccessIteratorTestClass(void)
{
	std::cout << std::boolalpha;
	
	std::cout << std::endl;
	std::cout << RED << "/************************" << GREEN << " random_access_iterator CLASS " << RED << "************************/" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET  << std::endl;
	std::cout << std::endl;
	
	// StructA		it("I am StructA it", 24);
	// StructA		it2("I am StructA it2", 42);
	
	A	*it = new A;
	A	*it2 = new A;

	it++;
	it2 += 2;
	// printResultStruct(it.operator->(), it2.operator->(), "it++", "it2 += 2");
	
	// it += 18;
	// it2 = it;
	// printResultStruct(it.operator->(), it2.operator->(), "it += 18", "it2 = it");

	// it -= 4;
	// it2 += 4;
	// printResultStruct(it.operator->(), it2.operator->(), "it -= 4", "it2 += 4");
	
	std::cout << BLUE << "it < it2 = " << MAGENTA << (it < it2) << RESET << std::endl;
	std::cout << BLUE << "it > it2 = " << MAGENTA << (it > it2) << RESET << std::endl;
	std::cout << BLUE << "it <= it2 = " << MAGENTA << (it <= it2) << RESET << std::endl;
	std::cout << BLUE << "it >= it2 = " << MAGENTA << (it >= it2) << RESET << std::endl;
	std::cout << BLUE << "it == it2 = " << MAGENTA << (it == it2) << RESET << std::endl;
	std::cout << BLUE << "it != it2 = " << MAGENTA << (it != it2) << RESET << std::endl;
	std::cout << std::endl;
	
	std::cout << RED << "----------------------------------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << GREEN << "----------- END TESTS random_access_iterator CLASS ------------" << RESET << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;
}