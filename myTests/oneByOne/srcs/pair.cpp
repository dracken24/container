/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:20:22 by dracken24         #+#    #+#             */
/*   Updated: 2023/03/04 11:03:00 by dracken24        ###   ########.fr       */
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

template<typename T, typename U>
void	printBool(ft::pair<T, U> ft_pair, std::pair<T, U> std_pair, ft::pair<T, U> ft_pair2,
			std::pair<T, U> std_pair2, std::string str1, std::string str2, int nbr)
{
	printPair(ft_pair, std_pair, str1, nbr);
	printPair(ft_pair2, std_pair2, str2, nbr);

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

	std::cout << RED << "<---------------------------------------------------------------------->\n" << std::endl;
}

void	pairTests(void)
{
	std::cout << std::boolalpha;

	ft::pair<int, std::string>	ft_pair(42, "Unicorn");
	ft::pair<int, std::string>	ft_pair2(24, "Bonbon");
	std::pair<int, std::string>	std_pair(42, "Unicorn");
	std::pair<int, std::string>	std_pair2(24, "Bonbon");
	

	printBool(ft_pair, std_pair, ft_pair2, std_pair2, " Value  : Init with 42 and Unicorn",
		" Compair: Init with 24 and Bonbon", 1);
		
	std::string input;
	
	std::cout << "Press ENTER to continue or Q for quit" << std::endl;
	std::getline(std::cin, input);
	std::getline(std::cin, input);
	if (input[0] == 'q' || input[0] == 'Q')
		return ;
	std::cout << "\e[1;1H\e[2J";
	
//--------------------------------------------------------------------------------------------//	

	ft_pair = ft_pair2;
	std_pair = std_pair2;

	printBool(ft_pair, std_pair, ft_pair2, std_pair2, " Value  : 24 and Bonbon",
		" Compair: 24 and Bonbon", 2);

	std::cout << "Press ENTER to continue or Q for quit" << std::endl;
	std::getline(std::cin, input);
	if (input[0] == 'q' || input[0] == 'Q')
		return ;
	std::cout << "\e[1;1H\e[2J";

//--------------------------------------------------------------------------------------------//	
	
	ft_pair = ft::make_pair(42, "Unicorn");
	ft_pair2 = ft::make_pair(42, "Bonbon");
	std_pair = std::make_pair(42, "Unicorn");
	std_pair2 = std::make_pair(42, "Bonbon");
	
	printBool(ft_pair, std_pair, ft_pair2, std_pair2, " Value  : 42 and Unicorn",
		" Compair: 42 and Bonbon", 3);
	
	std::cout << "Press ENTER to continue or Q for quit" << std::endl;
	std::getline(std::cin, input);
	if (input[0] == 'q' || input[0] == 'Q')
		return ;
	std::cout << "\e[1;1H\e[2J";

//--------------------------------------------------------------------------------------------//
	
	ft_pair = ft::make_pair(42, "Unicorn");
	ft_pair2 = ft::make_pair(24, "Unicorn");
	std_pair = std::make_pair(42, "Unicorn");
	std_pair2 = std::make_pair(24, "Unicorn");
	
	printBool(ft_pair, std_pair, ft_pair2, std_pair2, " Value  : 42 and Unicorn",
		" Compair: 24 and Unicorn", 4);
	
	std::cout << "Press ENTER to continue or Q for quit" << std::endl;
	std::getline(std::cin, input);
	if (input[0] == 'q' || input[0] == 'Q')
		return ;
	std::cout << "\e[1;1H\e[2J";
}
