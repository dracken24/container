/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteratorsTest.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:27:24 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/20 19:18:47 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.hpp"

// Int tests

template <typename T>
void	printResult(ft::random_access_iterator<T> it, ft::random_access_iterator<T> it2, std::string str, std::string str2, std::string type, int reset)
{
	static int	i = 1;

	if (reset == 1)
		i = 1;

	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << MAGENTA << type << YELLOW << " #["
		<< MAGENTA << i << YELLOW << "]: " << "it: " << str << std::endl;
	std::cout << "----------------------------------------" << RESET  << std::endl;

	std::cout << BLUE << "it ptr: " << MAGENTA << it.operator->() << std::endl << std::endl;
	
	std::cout << YELLOW << "Test " << MAGENTA << type << YELLOW <<" #["
		<< MAGENTA << i << YELLOW << "]: " << "it2: " << str2 << std::endl;
	std::cout << "----------------------------------------" << RESET  << std::endl;
	
	std::cout << BLUE << "it2 ptr: " << MAGENTA << it2.operator->() << RESET << std::endl << std::endl;

	i++;
}

// Test INT
void    randomAccessIteratorTestInt(void)
{
	std::cout << std::boolalpha;
	
	std::cout << std::endl;
	std::cout << RED << "/************************" << GREEN << " random_access_iterator INT " << \
		RED << "************************/" << RESET << std::endl;
	std::cout << std::endl << std::endl;
	
	ft::random_access_iterator<int>		it(0);	// Int
	ft::random_access_iterator<int>		it2(0);	// Int
	printResult(it, it2, "init", "init", "INT", 1);
	
	it++;
	it2 += 2;
	printResult(it, it2, "it++", "it2 += 2", "INT", 0);
	
	it += 18;
	it2 = it;
	printResult(it, it2, "it += 18", "it2 = it", "INT", 0);

	it -= 4;
	it2 += 4;
	printResult(it, it2, "it -= 4", "it2 += 4", "INT", 0);
	
	std::cout << std::endl;
	std::cout << BLUE << "it < it2  = " << MAGENTA << (it < it2) << RESET << std::endl;
	std::cout << BLUE << "it > it2  = " << MAGENTA << (it > it2) << RESET << std::endl;
	std::cout << BLUE << "it <= it2 = " << MAGENTA << (it <= it2) << RESET << std::endl;
	std::cout << BLUE << "it >= it2 = " << MAGENTA << (it >= it2) << RESET << std::endl;
	std::cout << BLUE << "it == it2 = " << MAGENTA << (it == it2) << RESET << std::endl;
	std::cout << BLUE << "it != it2 = " << MAGENTA << (it != it2) << RESET << std::endl;
	std::cout << std::endl;

	it = it2;
	printResult(it, it2, "it = it2", "it = it2", "INT", 0);

	std::cout << std::endl;
	std::cout << BLUE << "it < it2  = " << MAGENTA << (it < it2) << RESET << std::endl;
	std::cout << BLUE << "it > it2  = " << MAGENTA << (it > it2) << RESET << std::endl;
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
// Test CLASS

void	randomAccessIteratorTestClass(void)
{
	std::cout << std::boolalpha;
	
	std::cout << std::endl;
	std::cout << RED << "/************************" << GREEN << " random_access_iterator CLASS " << \
		RED << "************************/" << RESET << std::endl;
	std::cout << std::endl << std::endl;
	
	ft::random_access_iterator<A>		it(0);	// Class
	ft::random_access_iterator<A>		it2(0);	// Class
	printResult(it, it2, "init", "init", "CLASS", 1);
	
	it++;
	it2 += 2;
	printResult(it, it2, "it++", "it2 += 2", "CLASS", 0);
	
	it += 18;
	it2 = it;
	printResult(it, it2, "it += 18", "it2 = it", "CLASS", 0);

	it -= 4;
	it2 += 4;
	printResult(it, it2, "it -= 4", "it2 += 4", "CLASS", 0);
	
	std::cout << std::endl;
	std::cout << BLUE << "it < it2  = " << MAGENTA << (it < it2) << RESET << std::endl;
	std::cout << BLUE << "it > it2  = " << MAGENTA << (it > it2) << RESET << std::endl;
	std::cout << BLUE << "it <= it2 = " << MAGENTA << (it <= it2) << RESET << std::endl;
	std::cout << BLUE << "it >= it2 = " << MAGENTA << (it >= it2) << RESET << std::endl;
	std::cout << BLUE << "it == it2 = " << MAGENTA << (it == it2) << RESET << std::endl;
	std::cout << BLUE << "it != it2 = " << MAGENTA << (it != it2) << RESET << std::endl;
	std::cout << std::endl;

	it = it2;
	printResult(it, it2, "it = it2", "it = it2", "CLASS", 0);

	std::cout << std::endl;
	std::cout << BLUE << "it < it2  = " << MAGENTA << (it < it2) << RESET << std::endl;
	std::cout << BLUE << "it > it2  = " << MAGENTA << (it > it2) << RESET << std::endl;
	std::cout << BLUE << "it <= it2 = " << MAGENTA << (it <= it2) << RESET << std::endl;
	std::cout << BLUE << "it >= it2 = " << MAGENTA << (it >= it2) << RESET << std::endl;
	std::cout << BLUE << "it == it2 = " << MAGENTA << (it == it2) << RESET << std::endl;
	std::cout << BLUE << "it != it2 = " << MAGENTA << (it != it2) << RESET << std::endl;
	std::cout << std::endl;
	
	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << GREEN << "------------ END TESTS random_access_iterator CLASS ------------" << RESET << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;
}

/********************************************************************************************************/
// Test DOUBLE

void    randomAccessIteratorTestDouble(void)
{
	std::cout << std::boolalpha;
	
	std::cout << std::endl;
	std::cout << RED << "/************************" << GREEN << " random_access_iterator DOUBLE " << \
		RED << "************************/" << RESET << std::endl;
	std::cout << std::endl << std::endl;
	
	
	ft::random_access_iterator<double>		it(0);	// Int
	ft::random_access_iterator<double>		it2(0);	// Int
	printResult(it, it2, "init", "init", "DOUBLE", 1);
	
	it++;
	it2 += 2;
	printResult(it, it2, "it++", "it2 += 2", "DOUBLE", 0);
	
	it += 18;
	it2 = it;
	printResult(it, it2, "it += 18", "it2 = it", "DOUBLE", 0);

	it -= 4;
	it2 += 4;
	printResult(it, it2, "it -= 4", "it2 += 4", "DOUBLE", 0);
	
	std::cout << std::endl;
	std::cout << BLUE << "it < it2  = " << MAGENTA << (it < it2) << RESET << std::endl;
	std::cout << BLUE << "it > it2  = " << MAGENTA << (it > it2) << RESET << std::endl;
	std::cout << BLUE << "it <= it2 = " << MAGENTA << (it <= it2) << RESET << std::endl;
	std::cout << BLUE << "it >= it2 = " << MAGENTA << (it >= it2) << RESET << std::endl;
	std::cout << BLUE << "it == it2 = " << MAGENTA << (it == it2) << RESET << std::endl;
	std::cout << BLUE << "it != it2 = " << MAGENTA << (it != it2) << RESET << std::endl;
	std::cout << std::endl;

	it = it2;
	printResult(it, it2, "it = it2", "it = it2", "DOUBLE", 0);

	std::cout << std::endl;
	std::cout << BLUE << "it < it2  = " << MAGENTA << (it < it2) << RESET << std::endl;
	std::cout << BLUE << "it > it2  = " << MAGENTA << (it > it2) << RESET << std::endl;
	std::cout << BLUE << "it <= it2 = " << MAGENTA << (it <= it2) << RESET << std::endl;
	std::cout << BLUE << "it >= it2 = " << MAGENTA << (it >= it2) << RESET << std::endl;
	std::cout << BLUE << "it == it2 = " << MAGENTA << (it == it2) << RESET << std::endl;
	std::cout << BLUE << "it != it2 = " << MAGENTA << (it != it2) << RESET << std::endl;
	std::cout << std::endl;
	
	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << GREEN << "----------- END TESTS random_access_iterator DOUBLE ------------" << RESET << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;
}
