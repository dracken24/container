/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainOne.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:59:25 by dracken24         #+#    #+#             */
/*   Updated: 2023/03/04 16:09:14 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.hpp"

int	main(void)
{
	std::string input;
	
	while (input.compare("q") != 0 || input.compare("Q") != 0)
	{
		std::cout << "\e[1;1H\e[2J";
		
		std::cout << std::endl;
		std::cout << MAGENTA << "-----------------------------------------" << std::endl;
		std::cout << "|            Make a choice              |" << std::endl;
		std::cout << "-----------------------------------------" << GREEN  << std::endl << std::endl;

		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "Pair" << RESET << GREEN \
			<<" tests,             enter:  " << MAGENTA << "1" << std::endl;
		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "is_integral" << RESET << GREEN \
			<<" tests,      enter:  " << MAGENTA << "2" << std::endl;
        std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "is_same" << RESET << GREEN \
			<<" tests,          enter:  " << MAGENTA << "3" << std::endl;
		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "enable_if" << RESET << GREEN \
			<<" tests,        enter:  " << MAGENTA << "4\n" << std::endl;
		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "Lexico and equal" << RESET << GREEN \
			<<" tests, enter:  " << MAGENTA << "5" << std::endl;
		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "Iterators" << RESET << GREEN \
			<<" tests,        enter:  " << MAGENTA << "6" << std::endl;

		std::cout << RED << "\nEnter: 'Q' for quit\n" << RESET << std::endl;
		
		std::cout << "Choice: "; 
		std::cin >> input;
		std::cout << std::endl;
		
		if (input[0] >= '1' && input[0] <= '6')
		{
			switch (input[0])
			{
				case '1':
					pairTests();
					break ;
				case '2':
					is_integralTests();
					break ;
                case '3':
					is_sameTests();
					break ;
				case '4':
					enable_ifTests();
					break ;
				case '5':
					lexicoTests();
					break ;
				case '6':
					iteratorsTests();
					break ;
			}
		}
		else
		{
			if (input[0] == 'q' || input[0] == 'Q')
				return (0);
			else
				std::cout << RED << "Invalid input" << RESET << std::endl;
		}
		
	}
	
	return (0);
}
