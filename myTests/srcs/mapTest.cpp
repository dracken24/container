/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapTest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:47:12 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/09 20:00:48 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/container.hpp"

template <class T, class U>
void	printMap(ft::map<T, U> &ftMap, std::map<T, U> &stdMap, int i, std::string str)
{
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #["
		<< MAGENTA << i << YELLOW << "]: " << "ft::map: " << str << std::endl << std::endl;
		
	for (typename ft::map<T, T>::iterator it = ftMap.begin(); it != ftMap.end(); it++)
	{
		std::cout << MAGENTA << "[" << GREEN << it->first << MAGENTA << ", " << GREEN << it->second << MAGENTA "] ";
	}
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	
	std::cout << YELLOW << "Test " << YELLOW << " #["
		<< MAGENTA << i << YELLOW << "]: " << "std::map: " << str << std::endl << std::endl;
	for (typename std::map<T, T>::iterator it = stdMap.begin(); it != stdMap.end(); it++)
	{
		std::cout << MAGENTA << "[" << BLUE << it->first << MAGENTA << ", " << BLUE << it->second << MAGENTA "] ";
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
	std::cout << MAGENTA << "[" << GREEN << ftIt->first << MAGENTA << ", " << GREEN << ftIt->second << MAGENTA "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 5 << YELLOW << "]: " << "std::map: " << "Find(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << stdIt->first << MAGENTA << ", " << BLUE << stdIt->second << MAGENTA "] ";
	std::cout << std::endl;

	// Test 6: find(277) // good
	ftIt = ftMap.find(277);
	stdIt = stdMap.find(277);
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 6 << YELLOW << "]: " << "ft::map: " << "Find(277)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << ftIt->first << MAGENTA << ", " << GREEN << ftIt->second << MAGENTA "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 6 << YELLOW << "]: " << "std::map: " << "Find(277)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << stdIt->first << MAGENTA << ", " << BLUE << stdIt->second << MAGENTA "] ";
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
	std::cout << MAGENTA << "[" << GREEN << ftCount << MAGENTA << "]" << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 8 << YELLOW << "]: " << "std::map: " << "Count(277)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << stdCount << MAGENTA << "]" << std::endl;

	printMap(ftMap, stdMap, 0, "Print Values");

	// Test 9: lower_bound // good
	ftIt = ftMap.lower_bound(5);
	stdIt = stdMap.lower_bound(5);
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 9 << YELLOW << "]: " << "ft::map: " << "Lower_bound(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << ftIt->first << MAGENTA << ", " << GREEN << ftIt->second << MAGENTA "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 9 << YELLOW << "]: " << "std::map: " << "Lower_bound(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << stdIt->first << MAGENTA << ", " << BLUE << stdIt->second << MAGENTA "] ";
	std::cout << std::endl;

	// Test 10: lower_bound // good
	ftIt = ftMap.lower_bound(277);
	stdIt = stdMap.lower_bound(277);
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 9 << YELLOW << "]: " << "ft::map: " << "Lower_bound(277)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << ftIt->first << MAGENTA << ", " << GREEN << ftIt->second << MAGENTA "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 9 << YELLOW << "]: " << "std::map: " << "Lower_bound(277)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << stdIt->first << MAGENTA << ", " << BLUE << stdIt->second << MAGENTA "] ";
	std::cout << std::endl;

	printMap(ftMap, stdMap, 0, "Print Values");

	// Test 11: upper_bound
	ftIt = ftMap.upper_bound(5);
	stdIt = stdMap.upper_bound(5);
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 11 << YELLOW << "]: " << "ft::map: " << "Upper_bound(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << ftIt->first << MAGENTA << ", " << GREEN << ftIt->second << MAGENTA "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 11 << YELLOW << "]: " << "std::map: " << "Upper_bound(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << stdIt->first << MAGENTA << ", " << BLUE << stdIt->second << MAGENTA "] ";
	std::cout << std::endl;

	// Test 12: upper_bound
	ftIt = ftMap.upper_bound(277);
	stdIt = stdMap.upper_bound(277);
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 12 << YELLOW << "]: " << "ft::map: " << "Upper_bound(277)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << ftIt->first << MAGENTA << ", " << GREEN << ftIt->second << MAGENTA "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 12 << YELLOW << "]: " << "std::map: " << "Upper_bound(277)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << stdIt->first << MAGENTA << ", " << BLUE << stdIt->second << MAGENTA "] ";
	std::cout << std::endl;

	printMap(ftMap, stdMap, 0, "Print Values");
	
	// Test 13: equal_range(5)
	ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> ftPair = ftMap.equal_range(5);
	std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> stdPair = stdMap.equal_range(5);
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 13 << YELLOW << "]: " << "ft::map: " << "Equal_range(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << ftPair.first->first << MAGENTA << ", " << GREEN << ftPair.first->second << MAGENTA "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 13 << YELLOW << "]: " << "std::map: " << "Equal_range(5)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << stdPair.first->first << MAGENTA << ", " << BLUE << stdPair.first->second << MAGENTA "] ";
	std::cout << std::endl;

	// Test 14: equal_range
	ftPair = ftMap.equal_range(277);
	stdPair = stdMap.equal_range(277);
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 14 << YELLOW << "]: " << "ft::map: " << "Equal_range(277)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << ftPair.first->first << MAGENTA << ", " << GREEN << ftPair.first->second << MAGENTA "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 14 << YELLOW << "]: " << "std::map: " << "Equal_range(277)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << stdPair.first->first << MAGENTA << ", " << BLUE << stdPair.first->second << MAGENTA "] ";
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
	if (ftIt != ftMap.end())
		std::cout << MAGENTA << "[" << GREEN << ftIt->first << MAGENTA << ", " << GREEN << ftIt->second << MAGENTA << "] ";
	else
		std::cout << MAGENTA << "[" << GREEN << "key was not found in the map" << MAGENTA << "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 5 << YELLOW << "]: " << "std::map: " << "Find(Unicorn)" << std::endl << std::endl;
	if (stdIt != stdMap.end())
		std::cout << MAGENTA << "[" << BLUE << stdIt->first << MAGENTA << ", " << BLUE << stdIt->second << MAGENTA << "] ";
	else
		std::cout << MAGENTA << "[" << BLUE << "key was not found in the map" << MAGENTA << "] ";
	std::cout << std::endl;

	// Test 6: find(Tony) // good
	ftIt = ftMap.find("Tony");
	stdIt = stdMap.find("Tony");
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 6 << YELLOW << "]: " << "ft::map: " << "Find(Tony)" << std::endl << std::endl;
	if (ftIt != ftMap.end())
		std::cout << MAGENTA << "[" << GREEN << ftIt->first << MAGENTA << ", " << GREEN << ftIt->second << MAGENTA << "] ";
	else
		std::cout << MAGENTA << "[" << GREEN << "key was not found in the map" << MAGENTA << "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 6 << YELLOW << "]: " << "std::map: " << "Find(Tony)" << std::endl << std::endl;
	if (stdIt != stdMap.end())
		std::cout << MAGENTA << "[" << BLUE << stdIt->first << MAGENTA << ", " << BLUE << stdIt->second << MAGENTA << "] ";
	else
		std::cout << MAGENTA << "[" << BLUE << "key was not found in the map" << MAGENTA << "] ";
	std::cout << std::endl;

	printMap(ftMap, stdMap, 0, "Print Values");

	// Test 7: count Unicorn // good
	int ftCount = ftMap.count("Unicorn");
	int stdCount = stdMap.count("Unicorn");
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 7 << YELLOW << "]: " << "ft::map: " << "Count(Unicorn)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << ftCount << MAGENTA << "]" << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 7 << YELLOW << "]: " << "std::map: " << "Count(Unicorn)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << stdCount << MAGENTA << "]" << std::endl;

	// Test 8: count Tony // good
	ftCount = ftMap.count("Tony");
	stdCount = stdMap.count("Tony");
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 8 << YELLOW << "]: " << "ft::map: " << "Count(Tony)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << ftCount << MAGENTA << "]" << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 8 << YELLOW << "]: " << "std::map: " << "Count(Tony)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << stdCount << MAGENTA << "]" << std::endl;

	printMap(ftMap, stdMap, 0, "Print Values");

	// Test 9: lower_bound("Unicorn") // good
	ftIt = ftMap.lower_bound("Unicorn");
	stdIt = stdMap.lower_bound("Unicorn");
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 9 << YELLOW << "]: " << "ft::map: " << "Lower_bound(Unicorn)" << std::endl << std::endl;
	if (ftIt != ftMap.end())
		std::cout << MAGENTA << "[" << GREEN << ftIt->first << MAGENTA << ", " << GREEN << ftIt->second << MAGENTA << "] ";
	else
		std::cout << MAGENTA << "[" << GREEN << "key was not found in the map" << MAGENTA << "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 9 << YELLOW << "]: " << "std::map: " << "Lower_bound(Unicorn)" << std::endl << std::endl;
	if (stdIt != stdMap.end())
		std::cout << MAGENTA << "[" << BLUE << stdIt->first << MAGENTA << ", " << BLUE << stdIt->second << MAGENTA << "] ";
	else
		std::cout << MAGENTA << "[" << BLUE << "key was not found in the map" << MAGENTA << "] ";
	std::cout << std::endl;

	// Test 10: lower_bound("Tony") // good
	ftIt = ftMap.lower_bound("Tony");
	stdIt = stdMap.lower_bound("Tony");
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 10 << YELLOW << "]: " << "ft::map: " << "Lower_bound(Tony)" << std::endl << std::endl;
	if (ftIt != ftMap.end())
		std::cout << MAGENTA << "[" << GREEN << ftIt->first << MAGENTA << ", " << GREEN << ftIt->second << MAGENTA << "] ";
	else
		std::cout << MAGENTA << "[" << GREEN << "key was not found in the map" << MAGENTA << "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 10 << YELLOW << "]: " << "std::map: " << "Lower_bound(Tony)" << std::endl << std::endl;
	if (stdIt != stdMap.end())
		std::cout << MAGENTA << "[" << BLUE << stdIt->first << MAGENTA << ", " << BLUE << stdIt->second << MAGENTA << "] ";
	else
		std::cout << MAGENTA << "[" << BLUE << "key was not found in the map" << MAGENTA << "] ";
	std::cout << std::endl;

	printMap(ftMap, stdMap, 0, "Print Values");

	// Test 11: upper_bound(Unicorn)
	ftIt = ftMap.upper_bound("Unicorn");
	stdIt = stdMap.upper_bound("Unicorn");
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 11 << YELLOW << "]: " << "ft::map: " << "Upper_bound(Unicorn)" << std::endl << std::endl;
	if (ftIt != ftMap.end())
		std::cout << MAGENTA << "[" << GREEN << ftIt->first << MAGENTA << ", " << GREEN << ftIt->second << MAGENTA << "] ";
	else
		std::cout << MAGENTA << "[" << GREEN << "key was not found in the map" << MAGENTA << "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 11 << YELLOW << "]: " << "std::map: " << "Upper_bound(Unicorn)" << std::endl << std::endl;
	if (stdIt != stdMap.end())
		std::cout << MAGENTA << "[" << BLUE << stdIt->first << MAGENTA << ", " << BLUE << stdIt->second << MAGENTA << "] ";
	else
		std::cout << MAGENTA << "[" << BLUE << "key was not found in the map" << MAGENTA << "] ";
	std::cout << std::endl;

	// Test 12: upper_bound(Tony)
	ftIt = ftMap.upper_bound("Tony");
	stdIt = stdMap.upper_bound("Tony");
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 12 << YELLOW << "]: " << "ft::map: " << "Upper_bound(Tony)" << std::endl << std::endl;
	if (ftIt != ftMap.end())
		std::cout << MAGENTA << "[" << GREEN << ftIt->first << MAGENTA << ", " << GREEN << ftIt->second << MAGENTA << "] ";
	else
		std::cout << MAGENTA << "[" << GREEN << "key was not found in the map" << MAGENTA << "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 12 << YELLOW << "]: " << "std::map: " << "Upper_bound(Tony)" << std::endl << std::endl;
	if (stdIt != stdMap.end())
		std::cout << MAGENTA << "[" << BLUE << stdIt->first << MAGENTA << ", " << BLUE << stdIt->second << MAGENTA << "] ";
	else
		std::cout << MAGENTA << "[" << BLUE << "key was not found in the map" << MAGENTA << "] ";
	std::cout << std::endl;

	printMap(ftMap, stdMap, 0, "Print Values");
	
	// // Test 13: equal_range(Unicorn)
	ft::pair<ft::map<std::string, std::string>::iterator, ft::map<std::string, std::string>::iterator> ftPair = ftMap.equal_range("Unicorn");
	std::pair<std::map<std::string, std::string>::iterator, std::map<std::string, std::string>::iterator> stdPair = stdMap.equal_range("Unicorn");
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 13 << YELLOW << "]: " << "ft::map: " << "Equal_range(Unicorn)" << std::endl << std::endl;

	if (ftPair.first != ftMap.end())
		std::cout << MAGENTA << "[" << GREEN << ftIt->first << MAGENTA << ", " << GREEN << ftIt->second << MAGENTA << "] ";
	else
		std::cout << MAGENTA << "[" << GREEN << "key was not found in the map" << MAGENTA << "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 13 << YELLOW << "]: " << "std::map: " << "Equal_range(Unicorn)" << std::endl << std::endl;

	if (stdPair.first != stdMap.end())
		std::cout << MAGENTA << "[" << BLUE << stdIt->first << MAGENTA << ", " << BLUE << stdIt->second << MAGENTA << "] ";
	else
		std::cout << MAGENTA << "[" << BLUE << "key was not found in the map" << MAGENTA << "] ";
	std::cout << std::endl;

	// Test 14: equal_range(Tony)
	ftPair = ftMap.equal_range("Tony");
	stdPair = stdMap.equal_range("Tony");
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 14 << YELLOW << "]: " << "ft::map: " << "Equal_range(Tony)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << ftPair.first->first << MAGENTA << ", " << GREEN << ftPair.first->second << MAGENTA << "] ";
	std::cout << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << YELLOW << " #[" << MAGENTA << 14 << YELLOW << "]: " << "std::map: " << "Equal_range(Tony)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << stdPair.first->first << MAGENTA << ", " << BLUE << stdPair.first->second << MAGENTA << "] ";
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
		
		T	a = it->first;
		U  	b = it->second;
		std::cout << GREEN << "ft: KEY 1: " << std::endl << std::endl;
		std::cout << GREEN << "ft: nbr : " << MAGENTA << a._nbr << std::endl;
		std::cout << GREEN << "ft: name: " << MAGENTA << a._str << std::endl;
		std::cout << GREEN << "ft: pos : " << MAGENTA << a._vec.x << " " << a._vec.y << std::endl;
		std::cout << std::endl;

		std::cout << GREEN << "ft: KEY 2: " << std::endl << std::endl;
		std::cout << GREEN << "ft: nbr : " << MAGENTA << b._nbr << std::endl;
		std::cout << GREEN << "ft: name: " << MAGENTA << b._str << std::endl;
		std::cout << GREEN << "ft: pos : " << MAGENTA << b._vec.x << " " << b._vec.y << std::endl;
		std::cout << std::endl;
		
		std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;

		a = itStd->first;
		b = itStd->second;
		std::cout << BLUE << "std: KEY 1: " << std::endl << std::endl;
		std::cout << BLUE << "std: nbr : " << MAGENTA << a._nbr << std::endl;
		std::cout << BLUE << "std: name: " << MAGENTA << a._str << std::endl;
		std::cout << BLUE << "std: pos : " << MAGENTA << a._vec.x << " " << a._vec.y << std::endl;
		std::cout << std::endl;

		std::cout << BLUE << "std: KEY 2: " << std::endl << std::endl;
		std::cout << BLUE << "std: nbr : " << MAGENTA << b._nbr << std::endl;
		std::cout << BLUE << "std: name: " << MAGENTA << b._str << std::endl;
		std::cout << BLUE << "std: pos : " << MAGENTA << b._vec.x << " " << b._vec.y << std::endl;
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

void	printOneClass(ft::map<A, A>::iterator ftIt, std::map<A, A>::iterator stdIt, std::string str, std::string type, int nbr)
{
	std::cout << RED << "----------------------------------------------------------------" 
		<< RESET << std::endl << std::endl;
	std::cout << YELLOW << "Test " << BLUE << type << YELLOW << "#[" << MAGENTA << nbr
		<< YELLOW << "]: " << str << std::endl << std::endl;
	std::cout << "----------------------------------------------------------------" 
		<< RESET << std::endl << std::endl;
	
	A	a = ftIt->first;
	A	b = ftIt->second;
	std::cout << GREEN << "ft: KEY 1: " << MAGENTA << std::endl << std::endl;
	std::cout << GREEN << "ft: nbr : " << MAGENTA << a.getNbr() << std::endl;
	std::cout << GREEN << "ft: name: " << MAGENTA << a.getStr() << std::endl;
	std::cout << GREEN << "ft: pos X: " << MAGENTA << a.getVecX() << GREEN << "  Pos Y:" << MAGENTA << a.getVecY() << std::endl;
	std::cout << std::endl;
	
	std::cout << GREEN << "ft: KEY 2: " << MAGENTA << std::endl << std::endl;
	std::cout << GREEN << "ft: nbr : " << MAGENTA << b.getNbr() << std::endl;
	std::cout << GREEN << "ft: name: " << MAGENTA << b.getStr() << std::endl;
	std::cout << GREEN << "ft: pos X: " << MAGENTA << b.getVecX() << GREEN << "  Pos Y:" << MAGENTA << b.getVecY() << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;

	a = stdIt->first;
	b = stdIt->second;
	std::cout << BLUE << "std: KEY 1: " << std::endl << std::endl;
	std::cout << BLUE << "std: nbr : " << MAGENTA << a.getNbr() << std::endl;
	std::cout << BLUE << "std: name: " << MAGENTA << a.getStr() << std::endl;
	std::cout << BLUE << "std: pos X: " << MAGENTA << a.getVecX() << BLUE << "  Pos Y:" << MAGENTA << a.getVecY() << std::endl;

	std::cout << BLUE << "std: KEY 2: " << std::endl << std::endl;
	std::cout << BLUE << "std: nbr : " << MAGENTA << b.getNbr() << std::endl;
	std::cout << BLUE << "std: name: " << MAGENTA << b.getStr() << std::endl;
	std::cout << BLUE << "std: pos X: " << MAGENTA << b.getVecX() << BLUE << "  Pos Y:" << MAGENTA << b.getVecY() << std::endl;
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
		A("Bubble", 45, (Vector2){264, 483}),
		A("Tracteur", 6, (Vector2){452, 884}),
		A("Avion", 567, (Vector2){986, 1942}),
		A("Jedi", 85, (Vector2){6566, 13392}),
		A("AAAAAAAAA", 476, (Vector2){7577, 654}),
	};

	A	map3[] = 
	{
		A("Bob", 33, (Vector2){377, 542}),
		A("Tony", 69, (Vector2){69, 1358}),
		A("Henry", 196, (Vector2){966, 1962}),
		A("Clamelie", 228, (Vector2){2758, 4546}),
		A("Chuck Noris", 420, (Vector2){4521, 8450}),
		A("Banana", 24, (Vector2){254, 458}),
	};

	A	map4[] = 
	{
		A("Ichigo", 6785, (Vector2){387, 562}),
		A("Naruto", 456, (Vector2){639, 13568}),
		A("Luffy", 2456, (Vector2){946, 1932}),
		A("Saya", 4697, (Vector2){2558, 656}),
		A("Kenshin", 6263, (Vector2){43421, 8540}),
		A("Toshiro", 6967, (Vector2){2454, 438}),
	};

	A	bad("Bad", 777, (Vector2){777, 777});


	ft::map<A, A>	ftMap;
	ft::map<A, A>	ftMap2;
	std::map<A, A>	stdMap;
	std::map<A, A>	stdMap2;


	ftMap.insert(ft::make_pair(map[0], map2[0]));
	ftMap.insert(ft::make_pair(map[1], map2[1]));
	ftMap.insert(ft::make_pair(map[2], map2[2]));
	ftMap.insert(ft::make_pair(map[3], map2[3]));
	ftMap.insert(ft::make_pair(map[4], map2[4]));
	
	stdMap.insert(std::make_pair(map[0], map2[0]));
	stdMap.insert(std::make_pair(map[1], map2[1]));
	stdMap.insert(std::make_pair(map[2], map2[2]));
	stdMap.insert(std::make_pair(map[3], map2[3]));
	stdMap.insert(std::make_pair(map[4], map2[4]));
	
	ftMap2.insert(ft::make_pair(map3[0], map4[0]));
	ftMap2.insert(ft::make_pair(map3[1], map4[1]));
	ftMap2.insert(ft::make_pair(map3[2], map4[2]));
	ftMap2.insert(ft::make_pair(map3[3], map4[3]));
	ftMap2.insert(ft::make_pair(map3[4], map4[4]));
	ftMap2.insert(ft::make_pair(map3[5], map4[5]));
	
	stdMap2.insert(std::make_pair(map3[0], map4[0]));
	stdMap2.insert(std::make_pair(map3[1], map4[1]));
	stdMap2.insert(std::make_pair(map3[2], map4[2]));
	stdMap2.insert(std::make_pair(map3[3], map4[3]));
	stdMap2.insert(std::make_pair(map3[4], map4[4]));
	stdMap2.insert(std::make_pair(map3[5], map4[5]));
	

	

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
	
	
	// Test 5: find(bad)
	ft::map<A, A>::iterator ftIt = ftMap.find(bad);
	std::map<A, A>::iterator stdIt = stdMap.find(bad);
	
	if (ftIt != ftMap.end() && stdIt != stdMap.end())
		printOneClass(ftIt, stdIt, "Find(bad)", "Class", 5);
	else
	{
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
		std::cout << YELLOW << "Test " << MAGENTA << "Class" << YELLOW << " #[" << MAGENTA << 5 << YELLOW << "]: " << "ft::map and std::map: " << "find(bad)" << std::endl << std::endl;
		std::cout << MAGENTA << "[" << GREEN << "key was not found in the ft::map" << BLUE << " and std::map" << MAGENTA << "] " << std::endl;
	}
	
	
	// Test 6: find(map4[0]) // good
	ftIt = ftMap.find(map3[0]);
	stdIt = stdMap.find(map3[0]);
	
	if (ftIt != ftMap.end() && stdIt != stdMap.end())
		printOneClass(ftIt, stdIt, "find(map3[0])", "Class", 6);
	else
	{
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
		std::cout << YELLOW << "Test " << MAGENTA << "Class" << YELLOW << " #[" << MAGENTA << 6 << YELLOW << "]: " << "ft::map and std::map: " << "find(map3[0])" << std::endl << std::endl;
		std::cout << MAGENTA << "[" << GREEN << "key was not found in the ft::map" << BLUE << " and std::map" << MAGENTA << "] " << std::endl;
	}


	// Test 7: count 5 // good
	int ftCount = ftMap.count(bad);
	int stdCount = stdMap.count(bad);
	
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << MAGENTA << "Class" << YELLOW << " #[" << MAGENTA << 7 << YELLOW << "]: " << "ft::map: " << "Count(bad)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << ftCount << MAGENTA << "]" << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << MAGENTA << "Class" << YELLOW << " #[" << MAGENTA << 7 << YELLOW << "]: " << "std::map: " << "Count(bad)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << stdCount << MAGENTA << "]" << std::endl << std::endl;


	// Test 8: count map3[4] // good
	ftCount = ftMap.count(map3[4]);
	stdCount = stdMap.count(map3[4]);
	
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << MAGENTA << "Class" << YELLOW << " #[" << MAGENTA << 8 << YELLOW << "]: " << "ft::map: " << "Count(map3[4])" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << ftCount << MAGENTA << "]" << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << MAGENTA << "Class" << YELLOW << " #[" << MAGENTA << 8 << YELLOW << "]: " << "std::map: " << "Count(map3[4])" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << stdCount << MAGENTA << "]" << std::endl;


	// Test 9: lower_bound bad // good
	ftIt = ftMap.lower_bound(bad);
	stdIt = stdMap.lower_bound(bad);
	
	if (ftIt != ftMap.end() && stdIt != stdMap.end())
		printOneClass(ftIt, stdIt, "lower_bound(bad)", "Class", 9);
	else
	{
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
		std::cout << YELLOW << "Test " << MAGENTA << "Class" << YELLOW << " #[" << MAGENTA << 9 << YELLOW << "]: " << "ft::map and std::map: " << "lower_bound(bad)" << std::endl << std::endl;
		std::cout << MAGENTA << "[" << GREEN << "key was not found in the ft::map" << BLUE << " and std::map" << MAGENTA << "] \n" << std::endl;
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	}

	// Test 10: lower_bound // good
	ftIt = ftMap.lower_bound(map3[3]);
	stdIt = stdMap.lower_bound(map3[3]);
	
	if (ftIt != ftMap.end() && stdIt != stdMap.end())
		printOneClass(ftIt, stdIt, "lower_bound(map3[3])", "Class", 10);
	else
	{
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
		std::cout << YELLOW << "Test " << MAGENTA << "Class" << YELLOW << " #[" << MAGENTA << 10 << YELLOW << "]: " << "ft::map and std::map: " << "lower_bound(map3[3])" << std::endl << std::endl;
		std::cout << MAGENTA << "[" << GREEN << "key was not found in the ft::map" << BLUE << " and std::map" << MAGENTA << "] \n" << std::endl;
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	}

	printClassMap(ftMap, stdMap, "Print Map", "Class", 0, 0);

	// Test 11: upper_bound
	ftIt = ftMap.upper_bound(bad);
	stdIt = stdMap.upper_bound(bad);

	if (ftIt != ftMap.end() && stdIt != stdMap.end())
		printOneClass(ftIt, stdIt, "upper_bound(bad)", "Class", 11);
	else
	{
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
		std::cout << YELLOW << "Test " << MAGENTA << "Class" << YELLOW << " #[" << MAGENTA << 11 << YELLOW << "]: " << "ft::map and std::map: " << "upper_bound(bad)" << std::endl << std::endl;
		std::cout << MAGENTA << "[" << GREEN << "key was not found in the ft::map" << BLUE << " and std::map" << MAGENTA << "] \n" << std::endl;
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	}

	// Test 12: upper_bound
	ftIt = ftMap.upper_bound(map3[2]);
	stdIt = stdMap.upper_bound(map3[2]);

	if (ftIt != ftMap.end() && stdIt != stdMap.end())
		printOneClass(ftIt, stdIt, "upper_bound(map3[2])", "Class", 12);
	else
	{
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
		std::cout << YELLOW << "Test " << MAGENTA << "Class" << YELLOW << " #[" << MAGENTA << 12 << YELLOW << "]: " << "ft::map and std::map: " << "upper_bound(map3[2])" << std::endl << std::endl;
		std::cout << MAGENTA << "[" << GREEN << "key was not found in the ft::map" << BLUE << " and std::map" << MAGENTA << "] \n" << std::endl;
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	}
	
	
	// Test 13: ftMap.equal_range(bad)
	ft::pair<ft::map<A, A>::iterator, ft::map<A, A>::iterator> ftPair = ftMap.equal_range(bad);
	std::pair<std::map<A, A>::iterator, std::map<A, A>::iterator> stdPair = stdMap.equal_range(bad);
	
	if (ftPair.first != ftMap.end() && stdPair.first != stdMap.end())
		printOneClass(ftIt, stdIt, "equal_range(bad)", "Class", 13);
	else
	{
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
		std::cout << YELLOW << "Test " << MAGENTA << "Class" << YELLOW << " #[" << MAGENTA << 13 << YELLOW << "]: " << "ft::map and std::map: " << "equal_range(bad)" << std::endl << std::endl;
		std::cout << MAGENTA << "[" << GREEN << "key was not found in the ft::map" << BLUE << " and std::map" << MAGENTA << "] \n" << std::endl;
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	}


	// Test 14: equal_range
	ftPair = ftMap.equal_range(map3[1]);
	stdPair = stdMap.equal_range(map3[1]);

	if (ftPair.first != ftMap.end() && stdPair.first != stdMap.end())
		printOneClass(ftIt, stdIt, "equal_range(map3[1])", "Class", 14);
	else
	{
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
		std::cout << YELLOW << "Test " << MAGENTA << "Class" << YELLOW << " #[" << MAGENTA << 14 << YELLOW << "]: " << "ft::map and std::map: " << "equal_range(map3[1])" << std::endl << std::endl;
		std::cout << MAGENTA << "[" << GREEN << "key was not found in the ft::map" << BLUE << " and std::map" << MAGENTA << "] \n" << std::endl;
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	}


	printClassMap(ftMap, stdMap, "Print Map", "Class", 0, 0);

	// Test 15: erase(bad)
	ftMap.erase(bad);
	stdMap.erase(bad);
	printClassMap(ftMap, stdMap, "erase(bad)", "Class", 15, 0);

	// Test 16: erase(map3[1])
	ftMap.erase(map3[1]);
	stdMap.erase(map3[1]);
	printClassMap(ftMap, stdMap, "erase(map3[1])", "Class", 16, 0);

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


void	printOneStruct(ft::map<StructA, StructA>::iterator ftIt, std::map<StructA, StructA>::iterator stdIt, std::string str, std::string type, int nbr)
{
	std::cout << RED << "----------------------------------------------------------------" 
		<< RESET << std::endl << std::endl;
	std::cout << YELLOW << "Test " << BLUE << type << YELLOW << "#[" << MAGENTA << nbr
		<< YELLOW << "]: " << str << std::endl << std::endl;
	std::cout << "----------------------------------------------------------------" 
		<< RESET << std::endl << std::endl;
	
	StructA	a = ftIt->first;
	StructA	b = ftIt->second;
	std::cout << GREEN << "ft: KEY 1: " << MAGENTA << std::endl << std::endl;
	std::cout << GREEN << "ft: nbr : " << MAGENTA << a._nbr << std::endl;
	std::cout << GREEN << "ft: name: " << MAGENTA << a._str << std::endl;
	std::cout << GREEN << "ft: pos X: " << MAGENTA << a._vec.x << GREEN << "  Pos Y:" << MAGENTA << a._vec.y << std::endl;
	std::cout << std::endl;
	
	std::cout << GREEN << "ft: KEY 2: " << MAGENTA << std::endl << std::endl;
	std::cout << GREEN << "ft: nbr : " << MAGENTA << b._nbr << std::endl;
	std::cout << GREEN << "ft: name: " << MAGENTA << b._str << std::endl;
	std::cout << GREEN << "ft: pos X: " << MAGENTA << b._vec.x << GREEN << "  Pos Y:" << MAGENTA << b._vec.y << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;

	a = stdIt->first;
	b = stdIt->second;
	std::cout << BLUE << "std: KEY 1: " << std::endl << std::endl;
	std::cout << BLUE << "std: nbr : " << MAGENTA << a._nbr << std::endl;
	std::cout << BLUE << "std: name: " << MAGENTA << a._str << std::endl;
	std::cout << BLUE << "std: pos X: " << MAGENTA << a._vec.x << BLUE << "  Pos Y:" << MAGENTA << a._vec.y<< std::endl;

	std::cout << BLUE << "std: KEY 2: " << std::endl << std::endl;
	std::cout << BLUE << "std: nbr : " << MAGENTA << b._nbr << std::endl;
	std::cout << BLUE << "std: name: " << MAGENTA << b._str << std::endl;
	std::cout << BLUE << "std: pos X: " << MAGENTA << b._vec.x << BLUE << "  Pos Y:" << MAGENTA << b._vec.y<< std::endl;
	std::cout << std::endl << std::endl;
}

void	mapTestStruct()
{
	std::cout << std::boolalpha;
	std::cout << RED << "/**************************" << GREEN << " MAP STRUT " << \
		RED << "**************************/" << RESET << std::endl << std::endl;

	std::string		buffer;

	StructA	map[] = 
	{
		StructA("Monkey", 24, (Vector2){24, 48}),
		StructA("Unicorn", 42, (Vector2){42, 84}),
		StructA("Pony", 96, (Vector2){96, 192}),
		StructA("Zombie", 666, (Vector2){666, 1332}),
		StructA("Squirrel", 77, (Vector2){777, 154}),
	};

	StructA	map2[] = 
	{
		StructA("Bubble", 45, (Vector2){264, 483}),
		StructA("Tracteur", 6, (Vector2){452, 884}),
		StructA("Avion", 567, (Vector2){986, 1942}),
		StructA("Jedi", 85, (Vector2){6566, 13392}),
		StructA("AAAAAAAAA", 476, (Vector2){7577, 654}),
	};

	StructA	map3[] = 
	{
		StructA("Bob", 33, (Vector2){377, 542}),
		StructA("Tony", 69, (Vector2){69, 1358}),
		StructA("Henry", 196, (Vector2){966, 1962}),
		StructA("Clamelie", 228, (Vector2){2758, 4546}),
		StructA("Chuck Noris", 420, (Vector2){4521, 8450}),
		StructA("Banana", 24, (Vector2){254, 458}),
	};

	StructA	map4[] = 
	{
		StructA("Ichigo", 6785, (Vector2){387, 562}),
		StructA("Naruto", 456, (Vector2){639, 13568}),
		StructA("Luffy", 2456, (Vector2){946, 1932}),
		StructA("Saya", 4697, (Vector2){2558, 656}),
		StructA("Kenshin", 6263, (Vector2){43421, 8540}),
		StructA("Toshiro", 6967, (Vector2){2454, 438}),
	};

	StructA	bad("Bad", 777, (Vector2){777, 777});


	ft::map<StructA, StructA>	ftMap;
	ft::map<StructA, StructA>	ftMap2;
	std::map<StructA, StructA>	stdMap;
	std::map<StructA, StructA>	stdMap2;


	ftMap.insert(ft::make_pair(map[0], map2[0]));
	ftMap.insert(ft::make_pair(map[1], map2[1]));
	ftMap.insert(ft::make_pair(map[2], map2[2]));
	ftMap.insert(ft::make_pair(map[3], map2[3]));
	ftMap.insert(ft::make_pair(map[4], map2[4]));
	
	stdMap.insert(std::make_pair(map[0], map2[0]));
	stdMap.insert(std::make_pair(map[1], map2[1]));
	stdMap.insert(std::make_pair(map[2], map2[2]));
	stdMap.insert(std::make_pair(map[3], map2[3]));
	stdMap.insert(std::make_pair(map[4], map2[4]));
	
	ftMap2.insert(ft::make_pair(map3[0], map4[0]));
	ftMap2.insert(ft::make_pair(map3[1], map4[1]));
	ftMap2.insert(ft::make_pair(map3[2], map4[2]));
	ftMap2.insert(ft::make_pair(map3[3], map4[3]));
	ftMap2.insert(ft::make_pair(map3[4], map4[4]));
	ftMap2.insert(ft::make_pair(map3[5], map4[5]));
	
	stdMap2.insert(std::make_pair(map3[0], map4[0]));
	stdMap2.insert(std::make_pair(map3[1], map4[1]));
	stdMap2.insert(std::make_pair(map3[2], map4[2]));
	stdMap2.insert(std::make_pair(map3[3], map4[3]));
	stdMap2.insert(std::make_pair(map3[4], map4[4]));
	stdMap2.insert(std::make_pair(map3[5], map4[5]));
	

	

	// Test 1: init // good
	printClassMap(ftMap, stdMap,"Init", "Class", 1, 1);
	printClassMap(ftMap2, stdMap2,"Init for change" , "Struct", 1, 1);

	// Test 2: insert // good
	ftMap.insert(ftMap2.begin(), ftMap2.end());
	stdMap.insert(stdMap2.begin(), stdMap2.end());
	printClassMap(ftMap, stdMap,"Insert(Map2.begin(), Map2.end())", "Struct", 2, 0);

	// Test 3: erase // good
	ftMap.erase(ftMap.begin());
	stdMap.erase(stdMap.begin());
	printClassMap(ftMap, stdMap, "Erase(begin())", "Struct", 3, 0);

	// Test 4: swap // good
	ftMap.swap(ftMap2);
	stdMap.swap(stdMap2);
	printClassMap(ftMap, stdMap, "Swap(Map2)", "Struct", 4, 0);
	
	
	// Test 5: find(bad)
	ft::map<StructA, StructA>::iterator ftIt = ftMap.find(bad);
	std::map<StructA, StructA>::iterator stdIt = stdMap.find(bad);
	
	if (ftIt != ftMap.end() && stdIt != stdMap.end())
		printOneStruct(ftIt, stdIt, "Find(bad)", "Struct", 5);
	else
	{
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
		std::cout << YELLOW << "Test " << MAGENTA << "Struct" << YELLOW << " #[" << MAGENTA << 5 << YELLOW << "]: " << "ft::map and std::map: " << "find(bad)" << std::endl << std::endl;
		std::cout << MAGENTA << "[" << GREEN << "key was not found in the ft::map" << BLUE << " and std::map" << MAGENTA << "] " << std::endl;
	}
	
	
	// Test 6: find(map4[0]) // good
	ftIt = ftMap.find(map3[0]);
	stdIt = stdMap.find(map3[0]);
	
	if (ftIt != ftMap.end() && stdIt != stdMap.end())
		printOneStruct(ftIt, stdIt, "find(map3[0])", "Struct", 6);
	else
	{
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
		std::cout << YELLOW << "Test " << MAGENTA << "Struct" << YELLOW << " #[" << MAGENTA << 6 << YELLOW << "]: " << "ft::map and std::map: " << "find(map3[0])" << std::endl << std::endl;
		std::cout << MAGENTA << "[" << GREEN << "key was not found in the ft::map" << BLUE << " and std::map" << MAGENTA << "] " << std::endl;
	}


	// Test 7: count 5 // good
	int ftCount = ftMap.count(bad);
	int stdCount = stdMap.count(bad);
	
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << MAGENTA << "Struct" << YELLOW << " #[" << MAGENTA << 7 << YELLOW << "]: " << "ft::map: " << "Count(bad)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << ftCount << MAGENTA << "]" << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << MAGENTA << "Struct" << YELLOW << " #[" << MAGENTA << 7 << YELLOW << "]: " << "std::map: " << "Count(bad)" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << stdCount << MAGENTA << "]" << std::endl << std::endl;


	// Test 8: count map3[4] // good
	ftCount = ftMap.count(map3[4]);
	stdCount = stdMap.count(map3[4]);
	
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << MAGENTA << "Struct" << YELLOW << " #[" << MAGENTA << 8 << YELLOW << "]: " << "ft::map: " << "Count(map3[4])" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << GREEN << ftCount << MAGENTA << "]" << std::endl;
	std::cout << YELLOW << "----------------------------------------" << RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test " << MAGENTA << "Struct" << YELLOW << " #[" << MAGENTA << 8 << YELLOW << "]: " << "std::map: " << "Count(map3[4])" << std::endl << std::endl;
	std::cout << MAGENTA << "[" << BLUE << stdCount << MAGENTA << "]" << std::endl;


	// Test 9: lower_bound bad // good
	ftIt = ftMap.lower_bound(bad);
	stdIt = stdMap.lower_bound(bad);
	
	if (ftIt != ftMap.end() && stdIt != stdMap.end())
		printOneStruct(ftIt, stdIt, "lower_bound(bad)", "Struct", 9);
	else
	{
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
		std::cout << YELLOW << "Test " << MAGENTA << "Struct" << YELLOW << " #[" << MAGENTA << 9 << YELLOW << "]: " << "ft::map and std::map: " << "lower_bound(bad)" << std::endl << std::endl;
		std::cout << MAGENTA << "[" << GREEN << "key was not found in the ft::map" << BLUE << " and std::map" << MAGENTA << "] \n" << std::endl;
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	}

	// Test 10: lower_bound // good
	ftIt = ftMap.lower_bound(map3[3]);
	stdIt = stdMap.lower_bound(map3[3]);
	
	if (ftIt != ftMap.end() && stdIt != stdMap.end())
		printOneStruct(ftIt, stdIt, "lower_bound(map3[3])", "Struct", 10);
	else
	{
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
		std::cout << YELLOW << "Test " << MAGENTA << "Struct" << YELLOW << " #[" << MAGENTA << 10 << YELLOW << "]: " << "ft::map and std::map: " << "lower_bound(map3[3])" << std::endl << std::endl;
		std::cout << MAGENTA << "[" << GREEN << "key was not found in the ft::map" << BLUE << " and std::map" << MAGENTA << "] \n" << std::endl;
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	}

	printClassMap(ftMap, stdMap, "Print Map", "Struct", 0, 0);

	// Test 11: upper_bound
	ftIt = ftMap.upper_bound(bad);
	stdIt = stdMap.upper_bound(bad);

	if (ftIt != ftMap.end() && stdIt != stdMap.end())
		printOneStruct(ftIt, stdIt, "upper_bound(bad)", "Struct", 11);
	else
	{
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
		std::cout << YELLOW << "Test " << MAGENTA << "Struct" << YELLOW << " #[" << MAGENTA << 11 << YELLOW << "]: " << "ft::map and std::map: " << "upper_bound(bad)" << std::endl << std::endl;
		std::cout << MAGENTA << "[" << GREEN << "key was not found in the ft::map" << BLUE << " and std::map" << MAGENTA << "] \n" << std::endl;
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	}

	// Test 12: upper_bound
	ftIt = ftMap.upper_bound(map3[2]);
	stdIt = stdMap.upper_bound(map3[2]);

	if (ftIt != ftMap.end() && stdIt != stdMap.end())
		printOneStruct(ftIt, stdIt, "upper_bound(map3[2])", "Struct", 12);
	else
	{
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
		std::cout << YELLOW << "Test " << MAGENTA << "Struct" << YELLOW << " #[" << MAGENTA << 12 << YELLOW << "]: " << "ft::map and std::map: " << "upper_bound(map3[2])" << std::endl << std::endl;
		std::cout << MAGENTA << "[" << GREEN << "key was not found in the ft::map" << BLUE << " and std::map" << MAGENTA << "] \n" << std::endl;
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	}
	
	
	// Test 13: ftMap.equal_range(bad)
	ft::pair<ft::map<StructA, StructA>::iterator, ft::map<StructA, StructA>::iterator> ftPair = ftMap.equal_range(bad);
	std::pair<std::map<StructA, StructA>::iterator, std::map<StructA, StructA>::iterator> stdPair = stdMap.equal_range(bad);
	
	if (ftPair.first != ftMap.end() && stdPair.first != stdMap.end())
		printOneStruct(ftIt, stdIt, "equal_range(bad)", "Struct", 13);
	else
	{
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
		std::cout << YELLOW << "Test " << MAGENTA << "Struct" << YELLOW << " #[" << MAGENTA << 13 << YELLOW << "]: " << "ft::map and std::map: " << "equal_range(bad)" << std::endl << std::endl;
		std::cout << MAGENTA << "[" << GREEN << "key was not found in the ft::map" << BLUE << " and std::map" << MAGENTA << "] \n" << std::endl;
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	}


	// Test 14: equal_range
	ftPair = ftMap.equal_range(map3[1]);
	stdPair = stdMap.equal_range(map3[1]);

	if (ftPair.first != ftMap.end() && stdPair.first != stdMap.end())
		printOneStruct(ftIt, stdIt, "equal_range(map3[1])", "Struct", 14);
	else
	{
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
		std::cout << YELLOW << "Test " << MAGENTA << "Struct" << YELLOW << " #[" << MAGENTA << 14 << YELLOW << "]: " << "ft::map and std::map: " << "equal_range(map3[1])" << std::endl << std::endl;
		std::cout << MAGENTA << "[" << GREEN << "key was not found in the ft::map" << BLUE << " and std::map" << MAGENTA << "] \n" << std::endl;
		std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	}


	printClassMap(ftMap, stdMap, "Print Map", "Struct", 0, 0);

	// Test 15: erase(bad)
	ftMap.erase(bad);
	stdMap.erase(bad);
	printClassMap(ftMap, stdMap, "erase(bad)", "Struct", 15, 0);

	// Test 16: erase(map3[1])
	ftMap.erase(map3[1]);
	stdMap.erase(map3[1]);
	printClassMap(ftMap, stdMap, "erase(map3[1])", "Struct", 16, 0);

	// Test 17: clear()
	ftMap.clear();
	stdMap.clear();
	printClassMap(ftMap, stdMap, "clear()", "Struct", 17, 0);

	std::cout << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << GREEN << "------------------------ END TESTS MAP -------------------------" << RESET << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;


	std::string input;
	
	std::cout << "Press ENTER to continue" << std::endl;
	std::getline(std::cin, input);
	std::cout << "\e[1;1H\e[2J";
}
