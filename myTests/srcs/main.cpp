/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:03:27 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/10 17:46:01 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/container.hpp"

void	chooseMapTests(void)
{
	std::string input;
	
	while (input.compare("q") != 0 || input.compare("Q") != 0)
	{
		std::cout << "\e[1;1H\e[2J";
		
		std::cout << std::endl;
		std::cout << MAGENTA << "----------------------------------------" << std::endl;
		std::cout << "|      Make a choice for Map test      |" << std::endl;
		std::cout << "----------------------------------------" << std::endl << std::endl;

		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "Map" << RESET << GREEN << "<" \
			<< BLUE << " int " << GREEN <<"> tests,    enter: " << MAGENTA << "1" << std::endl;
		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "Map" << RESET << GREEN << "<" \
			<< BLUE << " string " << GREEN <<"> tests, enter: " << MAGENTA << "2" << std::endl << std::endl;

		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "Map" << RESET << GREEN << "<" \
			<< BLUE << " class " << GREEN <<"> tests,    enter: " << MAGENTA << "3" << std::endl;
		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "Map" << RESET << GREEN << "<" \
			<< BLUE << " struct " << GREEN <<"> tests,   enter: " << MAGENTA << "4" << std::endl;

		std::cout << std::endl;
		std::cout << RED << "Enter: 'Q' for return" << RESET << std::endl;
		
		std::cout << "Choice: "; 
		std::cin >> input;
		std::cout << std::endl;

		switch (input[0])
		{
			case '1':
				mapTestInt();
				break;
			case '2':
				mapTestString();
				break;
			case '3':
				mapTestClass();
				break;
			case '4':
				mapTestStruct();
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

void	chooseStackTests(void)
{
	std::string input;
	
	while (input.compare("q") != 0 || input.compare("Q") != 0)
	{
		std::cout << "\e[1;1H\e[2J";
		
		std::cout << std::endl;
		std::cout << MAGENTA << "----------------------------------------" << std::endl;
		std::cout << "|     Make a choice for Stack test     |" << std::endl;
		std::cout << "----------------------------------------" << std::endl << std::endl;

		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "Stack" << RESET << GREEN << "<" \
			<< BLUE << " int " << GREEN <<"> tests,    enter: " << MAGENTA << "1" << std::endl;
		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "Stack" << RESET << GREEN << "<" \
			<< BLUE << " float " << GREEN <<"> tests,  enter: " << MAGENTA << "2" << std::endl << std::endl;
			
		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "Stack" << RESET << GREEN << "<" \
			<< BLUE << " struct " << GREEN <<"> tests, enter: " << MAGENTA << "3" << std::endl;
		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "Stack" << RESET << GREEN << "<" \
			<< BLUE << " class " << GREEN <<"> tests,  enter: " << MAGENTA << "4" << std::endl;

		std::cout << std::endl;
		std::cout << RED << "Enter: 'Q' for return" << RESET << std::endl;
		
		std::cout << "Choice: "; 
		std::cin >> input;
		std::cout << std::endl;

		switch (input[0])
		{
			case '1':
				stackIntTest();
				break;
			case '2':
				stackFloatTest();
				break;
			case '3':
				stackStructTest();
				break;
			case '4':
				stackClassTest();
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

void	chooseVectorTests(int flag)
{
	std::string input;
	
	while (input.compare("q") != 0 || input.compare("Q") != 0)
	{
		std::cout << "\e[1;1H\e[2J";
		
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
			<< BLUE << " class " << GREEN <<"> tests,  enter: " << MAGENTA << "5" << std::endl;

		std::cout << std::endl;
		std::cout << RED << "Enter: 'Q' for return" << RESET << std::endl;
		
		std::cout << "Choice: "; 
		std::cin >> input;
		std::cout << std::endl;

		if (flag == 0)
		{	
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
}

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

		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "Vector" << RESET << GREEN \
			<<" tests,   enter:  " << MAGENTA << "1" << std::endl;
		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "Stack" << RESET << GREEN \
			<<" tests,    enter:  " << MAGENTA << "2" << std::endl;
		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "Map" << RESET << GREEN \
			<<" tests,      enter:  " << MAGENTA << "3" << std::endl << std::endl;

		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "Vector Timout" << RESET << GREEN \
			<<" tests,      enter:  " << MAGENTA << "4" << std::endl;
		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "Stack Timout" << RESET << GREEN \
			<<" tests,       enter:  " << MAGENTA << "5" << std::endl;
		std::cout << GREEN << "For " << ITALIC << UNDERLINE << MAGENTA << "Map Timout" << RESET << GREEN \
			<<" tests,         enter:  " << MAGENTA << "6" << std::endl << std::endl;

		std::cout << RED << "Enter: 'Q' for quit" << RESET << std::endl;
		
		std::cout << "Choice: "; 
		std::cin >> input;
		std::cout << std::endl;
		
		if (input[0] >= '4' && input[0] <= '6')
		{
			switch (input[0])
			{
				case '4':
					vectorTimeOutTestInt();
					break ;
				case '5':
					chooseStackTestsInt();
					break ;
				case '6':
					chooseMapTestsInt();
					break ;
			}
		}
		else if (input[0] >= '1' && input[0] <= '3')
		{
			switch (input[0])
			{
				case '1':
					chooseVectorTests(0);
					break ;
				case '2':
					chooseStackTests();
					break ;
				case '3':
					chooseMapTests();
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
