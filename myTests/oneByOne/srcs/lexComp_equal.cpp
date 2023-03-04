/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexComp_equal.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:50:10 by dracken24         #+#    #+#             */
/*   Updated: 2023/03/04 13:15:43 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.hpp"

template<typename T, typename U>
void	print(std::vector<char> const& v, T suffix, U color)
{
	for (char c : v)
		std::cout << color << c << ' ';
	std::cout << YELLOW << suffix;
}

void	printEqual(std::string str1, std::string str2)
{
	std::cout << MAGENTA << str1 << YELLOW << " Is equal to " << MAGENTA << str2 << std::endl << std::endl;
	std::cout << GREEN << "ft::equal  "<< MAGENTA << ft::equal(str1.begin(), str1.end(), str2.begin()) << std::endl;
	std::cout << YELLOW << "<---------------------------------------------------------------------->" << std::endl;
	std::cout << BLUE << "std::equal " << MAGENTA << std::equal(str1.begin(), str1.end(), str2.begin()) << std::endl << std::endl;
	if (str1 == "Chuck Noris")
		std::cout << MAGENTA << "Chuck Noris is better than God !!\n" << RESET << std::endl;
	std::cout << RED << "<---------------------------------------------------------------------->\n" << RESET << std::endl;
}

void	equalTests(void)
{
	std::cout << std::boolalpha;

	std::cout << YELLOW << "Equal tests" << std::endl;
	std::cout << RED << "<---------------------------------------------------------------------->" << std::endl;

	std::string	str1 = {"Banana"};
	std::string	str2 = {"Minions"};

	printEqual("Banana", "Minions");
	printEqual("Banana", "Banana");
	printEqual("Baby shark", "Chuck Noris");
	printEqual("Chuck Noris", "God");
	printEqual("Chuck Noris !", "Chuck Noris !");
	
}

void	lexicoTests(void)
{
	std::cout << std::boolalpha;
	std::cout << "\e[1;1H\e[2J";
	
	std::vector<char>	std_v1{'a', 'b', 'c', 'd'};
	std::vector<char>	std_v2{'a', 'b', 'c', 'd'};
	std::mt19937 g{std::random_device{}()};

	std::cout << YELLOW << "Lexicographical_compair tests" << std::endl;
	std::cout << RED << "<---------------------------------------------------------------------->" << std::endl;
	
	for (int i = 1; i < 11; i++)
	{
		std::cout << GREEN << "ft::  ";	
		print(std_v1, "< ", GREEN);
		print(std_v2, ' ', GREEN);
		std::cout << MAGENTA << ft::lexicographical_compare(std_v1.begin(), std_v1.end(),
			std_v2.begin(), std_v2.end()) << std::endl;
		
		std::cout << BLUE << "std:: ";
		print(std_v1, "< ", BLUE);
		print(std_v2, ' ', BLUE);
		std::cout << MAGENTA << std::lexicographical_compare(std_v1.begin(), std_v1.end(),
			std_v2.begin(), std_v2.end()) << std::endl << std::endl;
		
		std::shuffle(std_v1.begin(), std_v1.end(), g);
		std::shuffle(std_v2.begin(), std_v2.end(), g);

		if (i % 5 == 0)
			std::cout << YELLOW << "<---------------------------------------------------------------------->" << std::endl;

	}

	std::cout << RESET << std::endl;
	std::string input;
	
	std::cout << "Press ENTER to continue" << std::endl;
	std::getline(std::cin, input);
	std::getline(std::cin, input);
	std::cout << "\e[1;1H\e[2J";

	equalTests();

	std::cout << RESET << std::endl;
	
	std::cout << "Press ENTER to continue" << std::endl;
	std::getline(std::cin, input);
	std::cout << "\e[1;1H\e[2J";
}
