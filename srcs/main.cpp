/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:03:27 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/17 23:03:00 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/container.hpp"

int	main(void)
{
	std::string input;
	
	while (input.compare("q") != 0 || input.compare("Q") != 0)
	{
		std::cout << std::endl;
		std::cout << YELLOW << "Make a choice" << std::endl;
		std::cout << "----------------------------------------" << GREEN  << std::endl;
		std::cout << "For Stack tests, enter: 1" << GREEN << std::endl << std::endl;
		std::cout << RED << "Enter: 'Q' for quit" << RESET << std::endl;
		std::cin >> input;
		std::cout << std::endl;
		
		if (input.compare("1") == 0)
			system("make stack");
		if (input.compare("q") == 0 || input.compare("Q") == 0)
			break ;
		else
			std::cout << RED << "Invalid input" << RESET << std::endl;
			
		std::cout << std::endl;
		input.empty();
	}
		
	return (0);
}
