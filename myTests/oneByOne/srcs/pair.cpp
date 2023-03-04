/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:20:22 by dracken24         #+#    #+#             */
/*   Updated: 2023/03/03 19:18:03 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.hpp"

template<typename T, typename U>
void	printPair(ft::pair<T, U> ft_pair, std::pair<T, U> std_pair, std::string str, int nbr)
{
	std::cout << RED << "<---------------------------------------------------------------------->" << std::endl;
	std::cout << YELLOW << "Test # " << MAGENTA << nbr << YELLOW << str << "\n" << std::endl;
	std::cout << GREEN << "ft_first : " << MAGENTA << ft_pair._first << GREEN << "  ft_second : " << MAGENTA << ft_pair._second << std::endl;
	std::cout << YELLOW << "<---------------------------------------------------------------------->" << std::endl;
	std::cout << BLUE << "std_first: " << MAGENTA << std_pair.first << BLUE << "  std_second: " << MAGENTA << std_pair.second << RESET << std::endl;
	std::cout << YELLOW << "<---------------------------------------------------------------------->\n" << std::endl;
}

void	pairTests(void)
{
	std::cout << std::boolalpha;

	ft::pair<int, std::string>	ft_pair(42, "Unicorn");
	ft::pair<int, std::string>	ft_pair2(24, "Bonbon");
	std::pair<int, std::string>	std_pair(42, "Unicorn");
	std::pair<int, std::string>	std_pair2(24, "Bonbon");

	ft::pair<int, std::string> ft_makePair = ft::make_pair(96, "Make Pair");
	std::pair<int, std::string> std_makePair = std::make_pair(96, "Make Pair");

	printPair(ft_pair, std_pair, " Value  : Init with 42 and Unicorn", 1);
	printPair(ft_pair2, std_pair2, " Compair: Init with 24 and Bonbon", 1);
	
	printPair(ft_makePair, std_makePair, " Make_pair with 96 and Make Pair", 2);

	std::cout << GREEN << "ft_pair == ft_pair2  : " << MAGENTA << (ft_pair == ft_pair2) << std::endl;
	std::cout << BLUE << "std_pair == std_pair2: " << MAGENTA << (std_pair == std_pair2) << std::endl << std::endl;

	std::cout << GREEN << "ft_pair != ft_pair2  : " << MAGENTA << (ft_pair != ft_pair2) << std::endl;
	std::cout << BLUE << "std_pair != std_pair2: " << MAGENTA << (std_pair != std_pair2) << std::endl << std::endl;
	
	std::cout << GREEN << "ft_pair < ft_pair2  : " << MAGENTA << (ft_pair < ft_pair2) << std::endl;
	std::cout << BLUE << "std_pair < std_pair2: " << MAGENTA << (std_pair < std_pair2) << std::endl << std::endl;

	std::cout << GREEN << "ft_pair <= ft_pair2  : " << MAGENTA << (ft_pair <= ft_pair2) << std::endl;
	std::cout << BLUE << "std_pair <= std_pair2: " << MAGENTA << (std_pair <= std_pair2) << std::endl << std::endl;

	std::cout << GREEN << "ft_pair > ft_pair2  : " << MAGENTA << (ft_pair > ft_pair2) << std::endl;
	std::cout << BLUE << "std_pair > std_pair2: " << MAGENTA << (std_pair > std_pair2) << std::endl << std::endl;

	std::cout << GREEN << "ft_pair >= ft_pair2  : " << MAGENTA << (ft_pair >= ft_pair2) << std::endl;
	std::cout << BLUE << "std_pair >= std_pair2: " << MAGENTA << (std_pair >= std_pair2) << std::endl << std::endl;

	std::string input;
	
	std::cout << "Press ENTER to continue" << std::endl;
	std::getline(std::cin, input);
	std::getline(std::cin, input);
	std::cout << "\e[1;1H\e[2J";
}
