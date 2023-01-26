/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapTest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:47:12 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/26 15:20:01 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/container.hpp"

template <class T, class U>
void	printMap(ft::map<T, U> &ftMap, std::map<T, U> &stdMap, int i, std::string str)
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
};

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

	// Test 1: init // good
	printMap<int>(ftMap, stdMap, 1, "Init");
	printMap<int>(ftMap2, stdMap2, 1, "Init for change");

	// Test 2: insert // good
	ftMap.insert(ftMap2.begin(), ftMap2.end());
	stdMap.insert(stdMap2.begin(), stdMap2.end());
	printMap<int>(ftMap, stdMap, 2, "Insert(Map2.begin(), Map2.end())");

	// Test 3: erase // good
	ftMap.erase(ftMap.begin());
	stdMap.erase(stdMap.begin());
	printMap(ftMap, stdMap, 3, "Erase(begin())");

	// Test 4: swap // good
	ftMap.swap(ftMap2);
	stdMap.swap(stdMap2);
	printMap(ftMap, stdMap, 4, "Swap(Map2)");
	
	// Test 5: find(5)
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

	// Test 6: find(277) // good
	ftIt = ftMap.find(277);
	stdIt = stdMap.find(277);
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 6 << YELLOW << "]: " << "ft::map: " << "Find(277)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << ftIt->first << MAGENTA << ", " << BLUE << ftIt->second << MAGENTA "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 6 << YELLOW << "]: " << "std::map: " << "Find(277)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << stdIt->first << MAGENTA << ", " << GREEN << stdIt->second << MAGENTA "] ";
	std::cout << std::endl;

	printMap(ftMap, stdMap, 0, "Print Values");

	// Test 7: count 5 // good
	int ftCount = ftMap.count(5);
	int stdCount = stdMap.count(5);
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 7 << YELLOW << "]: " << "ft::map: " << "Count(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << ftCount << MAGENTA << "]" << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 7 << YELLOW << "]: " << "std::map: " << "Count(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << stdCount << MAGENTA << "]" << std::endl;

	// Test 8: count 277 // good
	ftCount = ftMap.count(277);
	stdCount = stdMap.count(277);
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 8 << YELLOW << "]: " << "ft::map: " << "Count(277)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << ftCount << MAGENTA << "]" << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 8 << YELLOW << "]: " << "std::map: " << "Count(277)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << stdCount << MAGENTA << "]" << std::endl;

	printMap(ftMap, stdMap, 0, "Print Values");

	// Test 9: lower_bound // good
	ftIt = ftMap.lower_bound(5);
	stdIt = stdMap.lower_bound(5);
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 9 << YELLOW << "]: " << "ft::map: " << "Lower_bound(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << ftIt->first << MAGENTA << ", " << BLUE << ftIt->second << MAGENTA "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 9 << YELLOW << "]: " << "std::map: " << "Lower_bound(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << stdIt->first << MAGENTA << ", " << GREEN << stdIt->second << MAGENTA "] ";
	std::cout << std::endl;

	// Test 10: lower_bound // good
	ftIt = ftMap.lower_bound(277);
	stdIt = stdMap.lower_bound(277);
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 9 << YELLOW << "]: " << "ft::map: " << "Lower_bound(277)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << ftIt->first << MAGENTA << ", " << BLUE << ftIt->second << MAGENTA "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 9 << YELLOW << "]: " << "std::map: " << "Lower_bound(277)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << stdIt->first << MAGENTA << ", " << GREEN << stdIt->second << MAGENTA "] ";
	std::cout << std::endl;

	printMap(ftMap, stdMap, 0, "Print Values");

	// Test 11: upper_bound
	ftIt = ftMap.upper_bound(5);
	stdIt = stdMap.upper_bound(5);
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 11 << YELLOW << "]: " << "ft::map: " << "Upper_bound(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << ftIt->first << MAGENTA << ", " << BLUE << ftIt->second << MAGENTA "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 11 << YELLOW << "]: " << "std::map: " << "Upper_bound(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << stdIt->first << MAGENTA << ", " << GREEN << stdIt->second << MAGENTA "] ";
	std::cout << std::endl;

	// Test 12: upper_bound
	ftIt = ftMap.upper_bound(277);
	stdIt = stdMap.upper_bound(277);
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 12 << YELLOW << "]: " << "ft::map: " << "Upper_bound(277)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << ftIt->first << MAGENTA << ", " << BLUE << ftIt->second << MAGENTA "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 12 << YELLOW << "]: " << "std::map: " << "Upper_bound(277)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << stdIt->first << MAGENTA << ", " << GREEN << stdIt->second << MAGENTA "] ";
	std::cout << std::endl;

	printMap(ftMap, stdMap, 0, "Print Values");
	
	// Test 13: equal_range(5)
	ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> ftPair = ftMap.equal_range(5);
	std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> stdPair = stdMap.equal_range(5);
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 13 << YELLOW << "]: " << "ft::map: " << "Equal_range(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << ftPair.first->first << MAGENTA << ", " << BLUE << ftPair.first->second << MAGENTA "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 13 << YELLOW << "]: " << "std::map: " << "Equal_range(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << stdPair.first->first << MAGENTA << ", " << GREEN << stdPair.first->second << MAGENTA "] ";
	std::cout << std::endl;

	// Test 14: equal_range
	ftPair = ftMap.equal_range(277);
	stdPair = stdMap.equal_range(277);
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 14 << YELLOW << "]: " << "ft::map: " << "Equal_range(277)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << ftPair.first->first << MAGENTA << ", " << BLUE << ftPair.first->second << MAGENTA "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 14 << YELLOW << "]: " << "std::map: " << "Equal_range(277)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << stdPair.first->first << MAGENTA << ", " << GREEN << stdPair.first->second << MAGENTA "] ";
	std::cout << std::endl;

	printMap(ftMap, stdMap, 0, "Print Values");

	// Test 15: erase(5)
	ftMap.erase(5);
	stdMap.erase(5);
	printMap(ftMap, stdMap, 15, "erase(5)");

	// Test 16: erase(277)
	ftMap.erase(277);
	stdMap.erase(277);
	printMap(ftMap, stdMap, 16, "erase(277)");

	// Test 17: clear()
	ftMap.clear();
	stdMap.clear();
	printMap(ftMap, stdMap, 17, "clear()");

	std::cout << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << GREEN << "------------------------ END TESTS MAP -------------------------" << RESET << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;
}

void	mapTestString()
{
	std::cout << std::boolalpha;
	std::cout << RED << "/**************************" << GREEN << " MAP STRING " << \
		RED << "**************************/" << RESET << std::endl << std::endl;

	std::string		buffer;
	
	ft::map<std::string, std::string>	ftMap;
	ft::map<std::string, std::string>	ftMap2;
	std::map<std::string, std::string>	stdMap;
	std::map<std::string, std::string>	stdMap2;


	ftMap.insert(ft::make_pair<std::string, std::string>("Monkey", "Banana"));
	ftMap.insert(ft::make_pair<std::string, std::string>("Lion", "Meat"));
	ftMap.insert(ft::make_pair<std::string, std::string>("Elephant", "Grass"));
	ftMap.insert(ft::make_pair<std::string, std::string>("Tiger", "Meat"));
	ftMap.insert(ft::make_pair<std::string, std::string>("Giraffe", "Leaves"));
	ftMap.insert(ft::make_pair<std::string, std::string>("Zebra", "Leaves"));
	ftMap.insert(ft::make_pair<std::string, std::string>("Hippo", "Rainbow"));

	stdMap.insert(std::make_pair<std::string, std::string>("Monkey", "Banana"));
	stdMap.insert(std::make_pair<std::string, std::string>("Lion", "Meat"));
	stdMap.insert(std::make_pair<std::string, std::string>("Elephant", "Grass"));
	stdMap.insert(std::make_pair<std::string, std::string>("Tiger", "Meat"));
	stdMap.insert(std::make_pair<std::string, std::string>("Giraffe", "Leaves"));
	stdMap.insert(std::make_pair<std::string, std::string>("Zebra", "Leaves"));
	stdMap.insert(std::make_pair<std::string, std::string>("Hippo", "Rainbow"));
	
	ftMap2.insert(ft::make_pair<std::string, std::string>("Bob", "BabyShark"));
	ftMap2.insert(ft::make_pair<std::string, std::string>("Henry", "MamaShark"));
	ftMap2.insert(ft::make_pair<std::string, std::string>("Steve", "AfroShark"));
	ftMap2.insert(ft::make_pair<std::string, std::string>("Tony", "DadyShark"));
	ftMap2.insert(ft::make_pair<std::string, std::string>("Bruce", "ArnoldSharkseneger"));
	ftMap2.insert(ft::make_pair<std::string, std::string>("Natasha", "ChuckNoShark"));

	stdMap2.insert(std::make_pair<std::string, std::string>("Bob", "BabyShark"));
	stdMap2.insert(std::make_pair<std::string, std::string>("Henry", "MamaShark"));
	stdMap2.insert(std::make_pair<std::string, std::string>("Steve", "AfroShark"));
	stdMap2.insert(std::make_pair<std::string, std::string>("Tony", "DadyShark"));
	stdMap2.insert(std::make_pair<std::string, std::string>("Bruce", "ArnoldSharkseneger"));
	stdMap2.insert(std::make_pair<std::string, std::string>("Natasha", "ChuckNoShark"));

	// Test 1: init // good
	printMap<std::string>(ftMap, stdMap, 1, "Init");
	printMap<std::string>(ftMap2, stdMap2, 1, "Init for change");

	// Test 2: insert // good
	ftMap.insert(ftMap2.begin(), ftMap2.end());
	stdMap.insert(stdMap2.begin(), stdMap2.end());
	printMap<std::string>(ftMap, stdMap, 2, "Insert(Map2.begin(), Map2.end())");

	// Test 3: erase // good
	ftMap.erase(ftMap.begin());
	stdMap.erase(stdMap.begin());
	printMap(ftMap, stdMap, 3, "Erase(begin())");

	// Test 4: swap // good
	ftMap.swap(ftMap2);
	stdMap.swap(stdMap2);
	printMap(ftMap, stdMap, 4, "Swap(Map2)");
	
	// Test 5: find(Unicorn)
	ft::map<std::string, std::string>::iterator ftIt = ftMap.find("Unicorn");
	std::map<std::string, std::string>::iterator stdIt = stdMap.find("Unicorn");

	// std::cout << RED << "----------------------------------------------------------------"
	// 	<< RESET  << std::endl << std::endl;
	// std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 5 << YELLOW << "]: " << "ft::map: " << "Find(Unicorn)" << std::endl << std::endl;
	// std::cout << MAGENTA << "[" << BLUE << ftIt->first << MAGENTA << ", " << BLUE << ftIt->second << MAGENTA "] ";
	// std::cout << std::endl;
	// std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	// std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 5 << YELLOW << "]: " << "std::map: " << "Find(Unicorn)" << std::endl << std::endl;
	// std::cout << MAGENTA << "[" << GREEN << stdIt->first << MAGENTA << ", " << GREEN << stdIt->second << MAGENTA "] ";
	// std::cout << std::endl;

	// Test 6: find(Tony) // good
	ftIt = ftMap.find("Tony");
	stdIt = stdMap.find("Tony");
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 6 << YELLOW << "]: " << "ft::map: " << "Find(Tony)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << ftIt->first << MAGENTA << ", " << BLUE << ftIt->second << MAGENTA "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 6 << YELLOW << "]: " << "std::map: " << "Find(Tony)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << stdIt->first << MAGENTA << ", " << GREEN << stdIt->second << MAGENTA "] ";
	std::cout << std::endl;

	printMap(ftMap, stdMap, 0, "Print Values");

	// Test 7: count Unicorn // good
	int ftCount = ftMap.count("Unicorn");
	int stdCount = stdMap.count("Unicorn");
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 7 << YELLOW << "]: " << "ft::map: " << "Count(Unicorn)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << ftCount << MAGENTA << "]" << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 7 << YELLOW << "]: " << "std::map: " << "Count(Unicorn)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << stdCount << MAGENTA << "]" << std::endl;

	// Test 8: count Tony // good
	ftCount = ftMap.count("Tony");
	stdCount = stdMap.count("Tony");
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 8 << YELLOW << "]: " << "ft::map: " << "Count(Tony)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << ftCount << MAGENTA << "]" << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 8 << YELLOW << "]: " << "std::map: " << "Count(Tony)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << stdCount << MAGENTA << "]" << std::endl;

	printMap(ftMap, stdMap, 0, "Print Values");

	// // Test 9: lower_bound("Unicorn") // good
	// ftIt = ftMap.lower_bound("Unicorn");
	// stdIt = stdMap.lower_bound("Unicorn");
	// std::cout << RED << "----------------------------------------------------------------"
	// 	<< RESET  << std::endl << std::endl;
	// std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 9 << YELLOW << "]: " << "ft::map: " << "Lower_bound(Unicorn)" << std::endl << std::endl;
	// std::cout << MAGENTA << "[" << BLUE << ftIt->first << MAGENTA << ", " << BLUE << ftIt->second << MAGENTA "] ";
	// std::cout << std::endl;
	// std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	// std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 9 << YELLOW << "]: " << "std::map: " << "Lower_bound(Unicorn)" << std::endl << std::endl;
	// std::cout << MAGENTA << "[" << GREEN << stdIt->first << MAGENTA << ", " << GREEN << stdIt->second << MAGENTA "] ";
	// std::cout << std::endl;

	// Test 10: lower_bound("Tony") // good
	ftIt = ftMap.lower_bound("Tony");
	stdIt = stdMap.lower_bound("Tony");
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 10 << YELLOW << "]: " << "ft::map: " << "Lower_bound(Tony)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << ftIt->first << MAGENTA << ", " << BLUE << ftIt->second << MAGENTA "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 10 << YELLOW << "]: " << "std::map: " << "Lower_bound(Tony)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << stdIt->first << MAGENTA << ", " << GREEN << stdIt->second << MAGENTA "] ";
	std::cout << std::endl;

	printMap(ftMap, stdMap, 0, "Print Values");

	// // Test 11: upper_bound(Unicorn)
	// ftIt = ftMap.upper_bound("Unicorn");
	// stdIt = stdMap.upper_bound("Unicorn");
	// std::cout << RED << "----------------------------------------------------------------"
	// 	<< RESET  << std::endl << std::endl;
	// std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 11 << YELLOW << "]: " << "ft::map: " << "Upper_bound(Unicorn)" << std::endl << std::endl;
	// std::cout << MAGENTA << "[" << BLUE << ftIt->first << MAGENTA << ", " << BLUE << ftIt->second << MAGENTA "] ";
	// std::cout << std::endl;
	// std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	// std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 11 << YELLOW << "]: " << "std::map: " << "Upper_bound(Unicorn)" << std::endl << std::endl;
	// std::cout << MAGENTA << "[" << GREEN << stdIt->first << MAGENTA << ", " << GREEN << stdIt->second << MAGENTA "] ";
	// std::cout << std::endl;

	// // Test 12: upper_bound(Tony)
	// ftIt = ftMap.upper_bound("Tony");
	// stdIt = stdMap.upper_bound("Tony");
	// std::cout << RED << "----------------------------------------------------------------"
	// 	<< RESET  << std::endl << std::endl;
	// std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 12 << YELLOW << "]: " << "ft::map: " << "Upper_bound(Tony)" << std::endl << std::endl;
	// std::cout << MAGENTA << "[" << BLUE << ftIt->first << MAGENTA << ", " << BLUE << ftIt->second << MAGENTA "] ";
	// std::cout << std::endl;
	// std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	// std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 12 << YELLOW << "]: " << "std::map: " << "Upper_bound(Tony)" << std::endl << std::endl;
	// std::cout << MAGENTA << "[" << GREEN << stdIt->first << MAGENTA << ", " << GREEN << stdIt->second << MAGENTA "] ";
	// std::cout << std::endl;

	// printMap(ftMap, stdMap, 0, "Print Values");
	
	// // Test 13: equal_range(Unicorn)
	ft::pair<ft::map<std::string, std::string>::iterator, ft::map<std::string, std::string>::iterator> ftPair = ftMap.equal_range("Unicorn");
	std::pair<std::map<std::string, std::string>::iterator, std::map<std::string, std::string>::iterator> stdPair = stdMap.equal_range("Unicorn");
	// std::cout << RED << "----------------------------------------------------------------"
	// 	<< RESET  << std::endl << std::endl;
	// std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 13 << YELLOW << "]: " << "ft::map: " << "Equal_range(Unicorn)" << std::endl << std::endl;
	// std::cout << MAGENTA << "[" << BLUE << ftPair.first->first << MAGENTA << ", " << BLUE << ftPair.first->second << MAGENTA "] ";
	// std::cout << std::endl;
	// std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	// std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 13 << YELLOW << "]: " << "std::map: " << "Equal_range(Unicorn)" << std::endl << std::endl;
	// std::cout << MAGENTA << "[" << GREEN << stdPair.first->first << MAGENTA << ", " << GREEN << stdPair.first->second << MAGENTA "] ";
	// std::cout << std::endl;

	// Test 14: equal_range(Tony)
	ftPair = ftMap.equal_range("Tony");
	stdPair = stdMap.equal_range("Tony");
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 14 << YELLOW << "]: " << "ft::map: " << "Equal_range(Tony)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << ftPair.first->first << MAGENTA << ", " << BLUE << ftPair.first->second << MAGENTA "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 14 << YELLOW << "]: " << "std::map: " << "Equal_range(Tony)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << stdPair.first->first << MAGENTA << ", " << GREEN << stdPair.first->second << MAGENTA "] ";
	std::cout << std::endl;

	printMap(ftMap, stdMap, 0, "Print Values");

	// Test 15: erase(Unicorn)
	ftMap.erase("Unicorn");
	stdMap.erase("Unicorn");
	printMap(ftMap, stdMap, 15, "erase(Unicorn)");

	// Test 16: erase(Tony)
	ftMap.erase("Tony");
	stdMap.erase("Tony");
	printMap(ftMap, stdMap, 16, "erase(Tony)");

	// Test 17: clear()
	ftMap.clear();
	stdMap.clear();
	printMap(ftMap, stdMap, 17, "clear()");

	std::cout << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << GREEN << "------------------------ END TESTS MAP -------------------------" << RESET << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;
}
