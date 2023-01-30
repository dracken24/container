/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapTest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:47:12 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/30 11:41:22 by nadesjar         ###   ########.fr       */
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


	std::string input;
	
	std::cout << "Press ENTER to continue" << std::endl;
	std::getline(std::cin, input);
	std::getline(std::cin, input);
	std::cout << "\e[1;1H\e[2J";
}

/**************************************************************************************************************************/

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

	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 5 << YELLOW << "]: " << "ft::map: " << "Find(Unicorn)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << ftIt->first << MAGENTA << ", " << BLUE << ftIt->second << MAGENTA "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 5 << YELLOW << "]: " << "std::map: " << "Find(Unicorn)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << stdIt->first << MAGENTA << ", " << GREEN << stdIt->second << MAGENTA "] ";
	std::cout << std::endl;

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


	std::string input;
	
	std::cout << "Press ENTER to continue" << std::endl;
	std::getline(std::cin, input);
	std::getline(std::cin, input);
	std::cout << "\e[1;1H\e[2J";
}

/****************************************************************************************************************************/

template <typename T, typename U>
void	printClassMap(ft::map<T, U> map_FT, std::map<T, U> map_STD,
						std::string str, std::string type, int nbr, int reset)
{
	static int		i = nbr;
	static int		ct = 1;
	std::string		input = "";

	if (reset == 1)
	{
		i = nbr;
		ct = 1;
	}
	else if (reset == -1)
		i = nbr;
		
	if (ct == 1)
	{
		std::cout << "       Press 'A' to all tests" << std::endl;
		std::cout << "                 or" << std::endl;
		std::cout << "Press enter to continue to next test" << std::endl;
		
		std::getline(std::cin, input);
		if (input == "A" || input == "a")
			ct = 0;
	}

	std::cout << YELLOW << "ft::map:< " << MAGENTA << type << YELLOW << " >" << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" 
		<< RESET << std::endl << std::endl;
	std::cout << YELLOW << "Test " << BLUE << type << YELLOW << "#[" << MAGENTA << i
		<< YELLOW << "]: " << str << std::endl << std::endl;
	std::cout << "----------------------------------------------------------------" 
		<< RESET << std::endl << std::endl;
	
	
	int j = 0;
	typename std::map<T, U>::iterator itStd = map_STD.begin();
	for (typename ft::map<T, U>::iterator it = map_FT.begin(); it != map_FT.end(); it++)
	{
		std::cout << YELLOW << "Place in array: " << MAGENTA << "[" << j << "] " << std::endl << std::endl;
		
		A	a = it->second;
		std::cout << BLUE << "ft: KEY: " << MAGENTA << "[" << BLUE << it->first << MAGENTA << "] " << std::endl << std::endl;
		std::cout << BLUE << "ft: nbr : " << MAGENTA << a.getNbr() << std::endl;
		std::cout << BLUE << "ft: name: " << MAGENTA << a.getStr() << std::endl;
		std::cout << BLUE << "ft: pos : " << MAGENTA << a.getVecX() << " " << a.getVecY() << std::endl;
		std::cout << std::endl;
		
		std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;

		a = itStd->second;
		std::cout << GREEN << "std: KEY: " << MAGENTA << "[" << BLUE << it->first << MAGENTA << "] " << std::endl << std::endl;
		std::cout << GREEN << "std: nbr : " << MAGENTA << a.getNbr() << std::endl;
		std::cout << GREEN << "std: name: " << MAGENTA << a.getStr() << std::endl;
		std::cout << GREEN << "std: pos : " << MAGENTA << a.getVecX() << " " << a.getVecY() << std::endl;
		std::cout << std::endl;

		std::cout << RED << "----------------------------------------------------------------" 
			<< RESET << std::endl << std::endl;
		
		itStd++;
		j++;
	}
		
	std::cout << BLUE << "----------------------------------------------------------------" 
			<< RESET << std::endl << std::endl << std::endl;
	i++;
}

void	printOneClass(ft::map<int, A>::iterator ftIt, std::map<int, A>::iterator stdIt, std::string str, std::string type, int nbr)
{
	std::cout << YELLOW << "ft::map:< " << MAGENTA << type << YELLOW << " >" << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" 
		<< RESET << std::endl << std::endl;
	std::cout << YELLOW << "Test " << BLUE << type << YELLOW << "#[" << MAGENTA << nbr
		<< YELLOW << "]: " << str << std::endl << std::endl;
	std::cout << "----------------------------------------------------------------" 
		<< RESET << std::endl << std::endl;
	
	A	a = ftIt->second;
	std::cout << BLUE << "ft: KEY: " << MAGENTA << "[" << BLUE << ftIt->first << MAGENTA << "] " << std::endl << std::endl;
	std::cout << BLUE << "ft: nbr : " << MAGENTA << a.getNbr() << std::endl;
	std::cout << BLUE << "ft: name: " << MAGENTA << a.getStr() << std::endl;
	std::cout << BLUE << "ft: pos X: " << MAGENTA << a.getVecX() << BLUE << "  Pos Y:" << MAGENTA << a.getVecY() << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;

	A	b = stdIt->second;
	std::cout << GREEN << "std: KEY: " << MAGENTA << "[" << BLUE << stdIt->first << MAGENTA << "] " << std::endl << std::endl;
	std::cout << GREEN << "std: nbr : " << MAGENTA << b.getNbr() << std::endl;
	std::cout << GREEN << "std: name: " << MAGENTA << b.getStr() << std::endl;
	std::cout << GREEN << "std: pos X: " << MAGENTA << b.getVecX() << GREEN << "  Pos Y:" << MAGENTA << b.getVecY() << std::endl;
	std::cout << std::endl << std::endl;
}

void	mapTestClass()
{
	std::cout << std::boolalpha;
	std::cout << RED << "/**************************" << GREEN << " MAP CLASS " << \
		RED << "**************************/" << RESET << std::endl << std::endl;

	std::string		buffer;

	A	map[] = 
	{
		A("Monkey", 24, (Vector2){24, 48}),
		A("Unicorn", 42, (Vector2){42, 84}),
		A("Pony", 96, (Vector2){96, 192}),
		A("Zombie", 666, (Vector2){666, 1332}),
		A("Squirrel", 77, (Vector2){777, 154}),
	};

	A	map2[] = 
	{
		A("Bob", 33, (Vector2){37, 52}),
		A("Tony", 69, (Vector2){69, 138}),
		A("Henry", 196, (Vector2){96, 192}),
		A("Clamelie", 228, (Vector2){258, 456}),
		A("Chuck Noris", 420, (Vector2){421, 840}),
		A("Banana", 24, (Vector2){24, 48}),
	};


	ft::map<int, A>	ftMap;
	ft::map<int, A>	ftMap2;
	std::map<int, A>	stdMap;
	std::map<int, A>	stdMap2;


	ftMap.insert(ft::make_pair(34, map[0]));
	ftMap.insert(ft::make_pair(42, map[1]));
	ftMap.insert(ft::make_pair(96, map[2]));
	ftMap.insert(ft::make_pair(666, map[3]));
	ftMap.insert(ft::make_pair(77, map[4]));
	
	stdMap.insert(std::make_pair(34, map[0]));
	stdMap.insert(std::make_pair(42, map[1]));
	stdMap.insert(std::make_pair(96, map[2]));
	stdMap.insert(std::make_pair(666, map[3]));
	stdMap.insert(std::make_pair(77, map[4]));
	
	ftMap2.insert(ft::make_pair(33, map2[0]));
	ftMap2.insert(ft::make_pair(69, map2[1]));
	ftMap2.insert(ft::make_pair(196, map2[2]));
	ftMap2.insert(ft::make_pair(628, map2[3]));
	ftMap2.insert(ft::make_pair(420, map2[4]));
	ftMap2.insert(ft::make_pair(24, map2[5]));
	
	stdMap2.insert(std::make_pair(33, map2[0]));
	stdMap2.insert(std::make_pair(69, map2[1]));
	stdMap2.insert(std::make_pair(196, map2[2]));
	stdMap2.insert(std::make_pair(628, map2[3]));
	stdMap2.insert(std::make_pair(420, map2[4]));
	stdMap2.insert(std::make_pair(24, map2[5]));
	

	

	// Test 1: init // good
	printClassMap(ftMap, stdMap,"Init", "Class", 1, 1);
	printClassMap(ftMap2, stdMap2,"Init for change" , "Class", 1, 1);

	// Test 2: insert // good
	ftMap.insert(ftMap2.begin(), ftMap2.end());
	stdMap.insert(stdMap2.begin(), stdMap2.end());
	printClassMap(ftMap, stdMap,"Insert(Map2.begin(), Map2.end())", "Class", 2, 0);

	// Test 3: erase // good
	ftMap.erase(ftMap.begin());
	stdMap.erase(stdMap.begin());
	printClassMap(ftMap, stdMap, "Erase(begin())", "Class", 3, 0);

	// Test 4: swap // good
	ftMap.swap(ftMap2);
	stdMap.swap(stdMap2);
	printClassMap(ftMap, stdMap, "Swap(Map2)", "Class", 4, 0);
	
	
	// Test 5: find(5)
	ft::map<int, A>::iterator ftIt = ftMap.find(5);
	std::map<int, A>::iterator stdIt = stdMap.find(5);
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << MAGENTA << "Class" << YELLOW << " #[" << MAGENTA << 5 << YELLOW << "]: " << "ft::map: " << "Find(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << ftIt->first << MAGENTA "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << MAGENTA << "Class" << YELLOW << " #[" << MAGENTA << 5 << YELLOW << "]: " << "std::map: " << "Find(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << stdIt->first << MAGENTA "] ";
	std::cout << std::endl;
	
	// printClassMap(ftMap, stdMap, "ftMap.find(5)", "Class", 5, 0);

	
	// Test 6: find(420) // good
	ftIt = ftMap.find(420);
	stdIt = stdMap.find(420);
	
	printOneClass(ftIt, stdIt, "Find(420)", "Class", 6);


	// Test 7: count 5 // good
	int ftCount = ftMap.count(5);
	int stdCount = stdMap.count(5);
	
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << MAGENTA << "Class" << YELLOW << " #[" << MAGENTA << 7 << YELLOW << "]: " << "ft::map: " << "Count(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << ftCount << MAGENTA << "]" << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << MAGENTA << "Class" << YELLOW << " #[" << MAGENTA << 7 << YELLOW << "]: " << "std::map: " << "Count(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << stdCount << MAGENTA << "]" << std::endl << std::endl;


	// Test 8: count 277 // good
	ftCount = ftMap.count(420);
	stdCount = stdMap.count(420);
	
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << MAGENTA << "Class" << YELLOW << " #[" << MAGENTA << 8 << YELLOW << "]: " << "ft::map: " << "Count(420)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << ftCount << MAGENTA << "]" << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << MAGENTA << "Class" << YELLOW << " #[" << MAGENTA << 8 << YELLOW << "]: " << "std::map: " << "Count(420)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << stdCount << MAGENTA << "]" << std::endl;


	// Test 9: lower_bound // good
	ftIt = ftMap.lower_bound(5);
	stdIt = stdMap.lower_bound(5);
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << MAGENTA << "Class" << YELLOW << " #[" << MAGENTA << 9 << YELLOW << "]: " << "ft::map: " << "lower_bound(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << ftIt->first << MAGENTA "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << MAGENTA << "Class" << YELLOW << " #[" << MAGENTA << 9 << YELLOW << "]: " << "std::map: " << "lower_bound(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << stdIt->first << MAGENTA "] ";
	std::cout << std::endl;

	// Test 10: lower_bound // good
	ftIt = ftMap.lower_bound(420);
	stdIt = stdMap.lower_bound(420);

	printOneClass(ftIt, stdIt, "lower_bound(420)", "Class", 10);


	// Test 11: upper_bound
	ftIt = ftMap.upper_bound(5);
	stdIt = stdMap.upper_bound(5);

	printOneClass(ftIt, stdIt, "upper_bound(5)", "Class", 11);
	

	// Test 12: upper_bound
	ftIt = ftMap.upper_bound(420);
	stdIt = stdMap.upper_bound(420);

	printOneClass(ftIt, stdIt, "upper_bound(420)", "Class", 12);
	
	
	// Test 13: equal_range(5)
	ft::pair<ft::map<int, A>::iterator, ft::map<int, A>::iterator> ftPair = ftMap.equal_range(5);
	std::pair<std::map<int, A>::iterator, std::map<int, A>::iterator> stdPair = stdMap.equal_range(5);
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 13 << YELLOW << "]: " << "ft::map: " << "Equal_range(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << ftPair.first->first << MAGENTA "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 13 << YELLOW << "]: " << "std::map: " << "Equal_range(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << stdPair.first->first << MAGENTA "] ";
	std::cout << std::endl;


	// Test 14: equal_range
	ftPair = ftMap.equal_range(420);
	stdPair = stdMap.equal_range(420);

	printOneClass(ftMap.find(420), stdMap.find(420), "upper_bound(420)", "Class", 14);
	
	std::cout << GREEN << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 14 << YELLOW << "]: " << "ft::map: " << "Equal_range(420)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << ftPair.first->first << MAGENTA "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 14 << YELLOW << "]: " << "std::map: " << "Equal_range(420)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << stdPair.first->first << MAGENTA "] ";
	std::cout << std::endl;


	printClassMap(ftMap, stdMap, "Print Map", "Class", 0, -1);

	// Test 15: erase(5)
	ftMap.erase(5);
	stdMap.erase(5);
	printClassMap(ftMap, stdMap, "erase(5)", "Class", 15, -1);

	// Test 16: erase(420)
	ftMap.erase(420);
	stdMap.erase(420);
	printClassMap(ftMap, stdMap, "erase(420)", "Class", 16, 0);

	// Test 17: clear()
	ftMap.clear();
	stdMap.clear();
	printClassMap(ftMap, stdMap, "clear()", "Class", 17, 0);

	std::cout << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << GREEN << "------------------------ END TESTS MAP -------------------------" << RESET << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;


	std::string input;
	
	std::cout << "Press ENTER to continue" << std::endl;
	std::getline(std::cin, input);
	std::cout << "\e[1;1H\e[2J";
}
