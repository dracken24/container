/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteratorsTest.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:27:24 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/19 22:30:21 by dracken24        ###   ########.fr       */
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
	
		std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << GREEN << "------------ END TESTS random_access_iterator INT -------------" << RESET << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;
}

/********************************************************************************************************/
// Class tests

// std::string convertClassPtrToString(A *ptr)
// {
// 	std::stringstream ss;
// 	ss << ptr;
// 	std::cout << "convertClassPtrToString: " << ss.str() << std::endl;
// 	return (ss.str());
// }

// void	printResultClass(A *it, A *it2, std::string str, std::string str2)
// {
// 	static int	i = 0;

// 	std::cout << RED << "----------------------------------------------------------------" << RESET  << std::endl << std::endl;
// 	std::cout << YELLOW << "Test Class #[" << MAGENTA << i << YELLOW << "]: " << "it: " << str << " *** it2: " << str2 << std::endl;
// 	std::cout << "----------------------------------------" << RESET  << std::endl;

// 	std::cout << BLUE << "it ptr: " << MAGENTA << it << std::endl;
// 	std::cout << BLUE << "it nbr: " << MAGENTA << it->getNbr() << std::endl;
// 	std::cout << BLUE << "it vector2: X: " << MAGENTA << it->getVecX() << BLUE << "  Y: " << MAGENTA << it->getVecY() << RESET << std::endl << std::endl;
	
// 	std::cout << BLUE << "it2 ptr: " << MAGENTA << it2 << RESET << std::endl;
// 	std::cout << BLUE << "it2 nbr: " << MAGENTA << it2->getNbr() << std::endl;
// 	std::cout << BLUE << "it2 vector2: X: " << MAGENTA << it2->getVecX() << BLUE << "  Y: " << MAGENTA << it2->getVecY() << RESET << std::endl << std::endl;
	
// 	i++;
// }

// void	randomAccessIteratorTestClass(void)
// {
// 	std::cout << std::boolalpha;
	
// 	std::cout << std::endl;
// 	std::cout << RED << "/************************" << GREEN << " random_access_iterator CLASS " << RED << "************************/" << RESET << std::endl;
// 	std::cout << std::endl;

// 	A	**it = new A*;
// 	A	**it2 = new A*;
	
// 	for (int i = 0; i < 5; i++)
// 		it[i] = new A(i, (Vector2){i, i});
// 	for (int i = 0; i < 5; i++)
// 		it2[i * 2] = new A((i * 2), (Vector2){i * 2, i * 2});
// 	for (int i = 0; i < 5; i++)
// 		printResultClass(it[i], it2[i], "init", "init");

// 	// it++;
// 	// it2 += 2;
// 	// printResultClass(it, it2, "it++", "it2 += 2");
	
// 	// it += 18;
// 	// it2 = it;
// 	// printResultClass(it, it2, "it += 18", "it2 = it");

// 	// it -= 4;
// 	// it2 += 4;
// 	// printResultStruct(it.operator->(), it2.operator->(), "it -= 4", "it2 += 4");
	
// 	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;
// 	std::cout << BLUE << "it < it2 = " << MAGENTA << (it < it2) << RESET << std::endl;
// 	std::cout << BLUE << "it > it2 = " << MAGENTA << (it > it2) << RESET << std::endl;
// 	std::cout << BLUE << "it <= it2 = " << MAGENTA << (it <= it2) << RESET << std::endl;
// 	std::cout << BLUE << "it >= it2 = " << MAGENTA << (it >= it2) << RESET << std::endl;
// 	std::cout << BLUE << "it == it2 = " << MAGENTA << (it == it2) << RESET << std::endl;
// 	std::cout << BLUE << "it != it2 = " << MAGENTA << (it != it2) << RESET << std::endl;
// 	std::cout << std::endl;
	
// 	std::cout << RED << "----------------------------------------------------------------" << RESET  << std::endl << std::endl;
// 	std::cout << GREEN << "----------- END TESTS random_access_iterator CLASS ------------" << RESET << std::endl << std::endl;
// 	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;

// 	delete[] it;
// 	delete[] it2;
// }