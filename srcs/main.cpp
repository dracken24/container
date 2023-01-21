/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:03:27 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/20 22:44:18 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/container.hpp"

void	chooseVectorTests(void)
{
	std::string input;
	
	while (input.compare("q") != 0 || input.compare("Q") != 0)
	{
		std::cout << std::endl;
		std::cout << MAGENTA << "-----------------------------------------" << std::endl;
		std::cout << "|     Make a choice for Vector test     |" << std::endl;
		std::cout << "-----------------------------------------" << std::endl << std::endl;

		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "Vector" << RESET << GREEN << "<" \
			<< BLUE << " int " << GREEN <<"> tests,    enter: " << MAGENTA << "1" << std::endl;
		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "Vector" << RESET << GREEN << "<" \
			<< BLUE << " double " << GREEN <<"> tests, enter: " << MAGENTA << "2" << std::endl;
		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "Vector" << RESET << GREEN << "<" \
			<< BLUE << " string " << GREEN <<"> tests, enter: " << MAGENTA << "3" << std::endl << std::endl;
			
		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "Vector" << RESET << GREEN << "<" \
			<< BLUE << " struct " << GREEN <<"> tests, enter: " << MAGENTA << "4" << std::endl;
			std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "Vector" << RESET << GREEN << "<" \
			<< BLUE << " class " << GREEN <<"> tests, enter: " << MAGENTA << "5" << std::endl;

		std::cout << std::endl;
		std::cout << RED << "Enter: 'Q' for return" << RESET << std::endl;
		
		std::cout << "Choice: "; 
		std::cin >> input;
		std::cout << std::endl;

		switch (input[0])
		{
			case '1':
				vectorTestint();
				break;
			case '2':
				vectorTestDouble();
				break;
			case '3':
				vectorTestString();
				break;
			case '4':
				vectorTestStruct();
				break;
			case '5':
				vectorTestClass();
				break;
			case 'q':
			case 'Q':
				return;
			default:
				std::cout << RED << "Wrong input!" << RESET << std::endl;
				break;
		}
	}
}

void	chooseIteratorTests(void)
{
	std::string input;
	
	while (input.compare("q") != 0 || input.compare("Q") != 0)
	{
		std::cout << std::endl;
		std::cout << MAGENTA << "-----------------------------------------" << std::endl;
		std::cout << "|    Make a choice for Iterator test    |" << std::endl;
		std::cout << "-----------------------------------------" << GREEN  << std::endl << std::endl;

		std::cout << "For " << ITALIC << UNDERLINE << MAGENTA << "random_access_iterator" << RESET \
			<< GREEN "<" << BLUE << " int "<< GREEN << "> tests,    enter: " << MAGENTA << "1" << std::endl;
		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "random_access_iterator" << RESET \
			<< GREEN "<" << BLUE << " double "<< GREEN << "> tests, enter: " << MAGENTA << "2" << std::endl;
		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "random_access_iterator" << RESET \
			<< GREEN "<" << BLUE << " class "<< GREEN << "> tests,  enter: " << MAGENTA << "3" << std::endl;
		std::cout << std::endl;
		std::cout << RED << "Enter: 'Q' for return" << RESET << std::endl;
		
		std::cout << "Choice: "; 
		std::cin >> input;
		std::cout << std::endl;

		switch (input[0])
		{
			case '1':
				randomAccessIteratorTestInt();
				break ;
			case '2':
				randomAccessIteratorTestDouble();
				break ;
			case '3':
				randomAccessIteratorTestClass();
				break ;
			case 'q':
			case 'Q':
				return ;
			default:
				std::cout << RED << "Wrong input" << RESET << std::endl;
				break ;
		}
	}
}

int	main(void)
{
	std::string input;
	
	while (input.compare("q") != 0 || input.compare("Q") != 0)
	{
		std::cout << std::endl;
		std::cout << MAGENTA << "-----------------------------------------" << std::endl;
		std::cout << "|            Make a choice              |" << std::endl;
		std::cout << "-----------------------------------------" << GREEN  << std::endl << std::endl;

		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "Iterator" << RESET \
			<< GREEN <<" tests, enter:  " << MAGENTA << "1" << std::endl << std::endl;
		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "Vector" << RESET << GREEN \
			<<" tests,   enter:  " << MAGENTA << "2" << std::endl << std::endl;

		std::cout << RED << "Enter: 'Q' for quit" << RESET << std::endl;
		
		std::cout << "Choice: "; 
		std::cin >> input;
		std::cout << std::endl;

		switch (input[0])
		{
			case '1':
				chooseIteratorTests();
				break ;
			case '2':
				chooseVectorTests();
				break ;
			case 'q':
			case 'Q':
				return (0);
			default:
				std::cout << RED << "Invalid input" << RESET << std::endl;
		}
			
		std::cout << std::endl;
		input.empty();
	}
		
	return (0);
}
