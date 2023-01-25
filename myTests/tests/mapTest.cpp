/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapTest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:47:12 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/24 11:22:02 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/container.hpp"

template <class T>
void	printMap(ft::map<T, int> &ftMap, std::map<T, int> &stdMap, int i, std::string str)
{
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #["
		<< MAGENTA << i << YELLOW << "]: " << "ft::map: " << str << std::endl << std::endl;
		
	for (typename ft::map<T, T>::iterator it = ftMap.begin(); it != ftMap.end(); it++)
	{
		std::cout << MAGENTA << "[" << BLUE << it->first << MAGENTA << ", " << BLUE << it->second << MAGENTA "] ";
	}
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	
	std::cout << YELLOW << "Test " << YELLOW << " #["
		<< MAGENTA << i << YELLOW << "]: " << "std::map: " << str << std::endl << std::endl;
	for (typename std::map<T, T>::iterator it = stdMap.begin(); it != stdMap.end(); it++)
	{
		std::cout << MAGENTA << "[" << GREEN << it->first << MAGENTA << ", " << GREEN << it->second << MAGENTA "] ";
	}
	std::cout << std::endl;
}



void	mapTestInt()
{
	std::cout << std::boolalpha;
	std::cout << RED << "/**************************" << GREEN << " MAP INT " << \
		RED << "**************************/" << RESET << std::endl << std::endl;

	std::string		buffer;
	
	ft::map<int, int>	ftMap;
	ft::map<int, int>	ftMap2;
	std::map<int, int>	stdMap;
	std::map<int, int>	stdMap2;
	
	for (int i = 0; i < 7; i++)
	{
		int nbr = rand() % 1000;
		int nbr2 = rand() % 1000;
		
		ftMap.insert(ft::make_pair(nbr, nbr2));
		stdMap.insert(std::make_pair(nbr, nbr2));

		nbr = rand() % 500;
		nbr2 = rand() % 500;

		ftMap2.insert(ft::make_pair(nbr, i * nbr2));
		stdMap2.insert(std::make_pair(nbr, i * nbr2));
	}

	// Test 1: init
	printMap<int>(ftMap, stdMap, 1, "Init");
	printMap<int>(ftMap2, stdMap2, 1, "Init for change");

	// Test 2: insert
	ftMap.insert(ftMap2.begin(), ftMap2.end());
	stdMap.insert(stdMap2.begin(), stdMap2.end());
	printMap<int>(ftMap, stdMap, 2, "Insert(Map2.begin(), Map2.end())");

	// Test 3: erase
	ftMap.erase(ftMap.begin());
	stdMap.erase(stdMap.begin());
	printMap(ftMap, stdMap, 3, "Erase(begin())");

	// Test 4: swap
	ftMap.swap(ftMap2);
	stdMap.swap(stdMap2);
	printMap(ftMap, stdMap, 4, "Swap(Map2)");
	
	// Test 5: find
	ft::map<int, int>::iterator ftIt = ftMap.find(5);
	std::map<int, int>::iterator stdIt = stdMap.find(5);
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 5 << YELLOW << "]: " << "ft::map: " << "Find(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << ftIt->first << MAGENTA << ", " << BLUE << ftIt->second << MAGENTA "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 5 << YELLOW << "]: " << "std::map: " << "Find(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << stdIt->first << MAGENTA << ", " << GREEN << stdIt->second << MAGENTA "] ";
	std::cout << std::endl;

	// // Test 6: count
	// int ftCount = ftMap.count(5);
	// int stdCount = stdMap.count(5);
	// std::cout << RED << "----------------------------------------------------------------"
	// 	<< RESET  << std::endl << std::endl;
	// std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 6 << YELLOW << "]: " << "ft::map: " << "Count(5)" << std::endl << std::endl;
	// std::cout << MAGENTA << "[" << BLUE << ftCount << MAGENTA << "]" << std::endl;
	// std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	// std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 6 << YELLOW << "]: " << "std::map: " << "Count(5)" << std::endl << std::endl;
	// std::cout << MAGENTA << "[" << GREEN << stdCount << MAGENTA << "]" << std::endl;

	// // Test 7: lower_bound
	// ft::map<int, int>::iterator ftIt = ftMap.lower_bound(5);
	// std::map<int, int>::iterator stdIt = stdMap.lower_bound(5);
	// std::cout << RED << "----------------------------------------------------------------"
	// 	<< RESET  << std::endl << std::endl;
	// std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 7 << YELLOW << "]: " << "ft::map: " << "Lower_bound(5)" << std::endl << std::endl;
	// std::cout << MAGENTA << "[" << BLUE << ftIt->first << MAGENTA << ", " << BLUE << ftIt->second << MAGENTA "] ";
	// std::cout << std::endl;
	// std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	// std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 7 << YELLOW << "]: " << "std::map: " << "Lower_bound(5)" << std::endl << std::endl;
	// std::cout << MAGENTA << "[" << GREEN << stdCount << MAGENTA << "]" << std::endl;

	// // Test 8: upper_bound
	// ftIt = ftMap.upper_bound(5);
	// stdIt = stdMap.upper_bound(5);
	// std::cout << RED << "----------------------------------------------------------------"
	// 	<< RESET  << std::endl << std::endl;
	// std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 8 << YELLOW << "]: " << "ft::map: " << "Upper_bound(5)" << std::endl << std::endl;
	// std::cout << MAGENTA << "[" << BLUE << ftIt->first << MAGENTA << ", " << BLUE << ftIt->second << MAGENTA "] ";
	// std::cout << std::endl;
	// std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	// std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 8 << YELLOW << "]: " << "std::map: " << "Upper_bound(5)" << std::endl << std::endl;
	// std::cout << MAGENTA << "[" << GREEN << stdCount << MAGENTA << "]" << std::endl;

	// Test 9: equal_range
	ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> ftPair = ftMap.equal_range(5);
	std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> stdPair = stdMap.equal_range(5);
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 9 << YELLOW << "]: " << "ft::map: " << "Equal_range(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << ftPair.first->first << MAGENTA << ", " << BLUE << ftPair.first->second << MAGENTA "] ";
	std::cout << MAGENTA << "[" << BLUE << ftPair.second->first << MAGENTA << ", " << BLUE << ftPair.second->second << MAGENTA "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 9 << YELLOW << "]: " << "std::map: " << "Equal_range(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << stdPair.first->first << MAGENTA << ", " << GREEN << stdPair.first->second << MAGENTA "] ";
	std::cout << MAGENTA << "[" << GREEN << stdPair.second->first << MAGENTA << ", " << GREEN << stdPair.second->second << MAGENTA "] ";
	std::cout << std::endl;

	// // Test 10: find
	// ftIt = ftMap.find(5);
	// stdIt = stdMap.find(5);
	// std::cout << RED << "----------------------------------------------------------------"
	// 	<< RESET  << std::endl << std::endl;
	// std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 10 << YELLOW << "]: " << "ft::map: " << "Find(5)" << std::endl << std::endl;
	// std::cout << MAGENTA << "[" << BLUE << ftIt->first << MAGENTA << ", " << BLUE << ftIt->second << MAGENTA "] ";
	// std::cout << std::endl;
	// std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	// std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 10 << YELLOW << "]: " << "std::map: " << "Find(5)" << std::endl << std::endl;
	// std::cout << MAGENTA << "[" << GREEN << stdIt->first << MAGENTA << ", " << GREEN << stdIt->second << MAGENTA "] ";
	// std::cout << std::endl;

	// // Test 11: erase
	// ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> ftIt1 = ftMap.equal_range(5);
	// std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> stdIt1 = stdMap.equal_range(5);
	
	// ftMap.erase(ftIt1.first, ftIt1.second);
	// stdMap.erase(stdIt1.first, stdIt1.second);
	// printMap(ftMap, stdMap, 11, "Erase(ftMap.equal_range(5))");

	// Test 12: clear
	ftMap.clear();
	stdMap.clear();
	printMap(ftMap, stdMap, 12, "clear()");

	std::cout << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << GREEN << "------------------------ END TESTS MAP -------------------------" << RESET << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;
}
