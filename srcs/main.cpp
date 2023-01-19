/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:03:27 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/18 19:28:23 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/container.hpp"

void	chooseContainerStackTests(void)
{
	std::string input;
	
	while (input.compare("q") != 0 || input.compare("Q") != 0)
	{
		std::cout << std::endl;
		std::cout << MAGENTA << "----------------------------------------" << std::endl;
		std::cout << "Make a choice for Stack test" << std::endl;
		std::cout << "----------------------------------------" << GREEN  << std::endl;

		std::cout << "For " << ITALIC << UNDERLINE << "Vector" << RESET << GREEN <<" tests, enter: 1" << std::endl;
		// std::cout << "For " << ITALIC << UNDERLINE << "queue" << RESET << GREEN <<" tests, enter: 2" << std::endl << std::endl;
		std::cout << std::endl;
		std::cout << RED << "Enter: 'Q' for return" << RESET << std::endl;
		
		std::cout << "Choice: "; 
		std::cin >> input;
		std::cout << std::endl;

		switch (input[0])
		{
			case '1':
				vectorTest();
				break;
			// case '2':
			// 	queueTest();
			// 	break;
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
		std::cout << MAGENTA << "----------------------------------------" << std::endl;
		std::cout << "Make a choice for Iterator test" << std::endl;
		std::cout << "----------------------------------------" << GREEN  << std::endl;

		std::cout << "For " << ITALIC << UNDERLINE << "random_access_iterator<int>" << RESET << GREEN <<" tests, enter: 1" << std::endl;
		std::cout << "For " << ITALIC << UNDERLINE << "random_access_iterator<float>" << RESET << GREEN <<" tests, enter: 2" << std::endl << std::endl;
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
				randomAccessIteratorTestFloat();
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

// void	choosefunctionsTest()
// {
// 	std::string input;
	
// 	while (input.compare("q") != 0 || input.compare("Q") != 0)
// 	{
// 		std::cout << std::endl;
// 		std::cout << MAGENTA << "----------------------------------------" << std::endl;
// 		std::cout << "Make a choice for Functions test" << std::endl;
// 		std::cout << "----------------------------------------" << GREEN  << std::endl;

// 		std::cout << "For " << ITALIC << UNDERLINE << "swap" << RESET << GREEN <<" tests, enter: 1" << std::endl;
// 		std::cout << "For " << ITALIC << UNDERLINE << "iter_swap" << RESET << GREEN <<" tests, enter: 2" << std::endl << std::endl;
// 		std::cout << std::endl;
// 		std::cout << RED << "Enter: 'Q' for return" << RESET << std::endl;
		
// 		std::cout << "Choice: "; 
// 		std::cin >> input;
// 		std::cout << std::endl;

// 		switch (input[0])
// 		{
// 			case '1':
// 				swapTest();
// 				break ;
// 			case '2':
// 				iter_swapTest();
// 				break ;
// 			case 'q':
// 			case 'Q':
// 				return ;
// 			default:
// 				std::cout << RED << "Wrong input" << RESET << std::endl;
// 				break ;
// 		}
// 	}
// }

int	main(void)
{
	std::string input;
	
	while (input.compare("q") != 0 || input.compare("Q") != 0)
	{
		std::cout << std::endl;
		std::cout << MAGENTA << "----------------------------------------" << std::endl;
		std::cout << "Make a choice" << std::endl;
		std::cout << "----------------------------------------" << GREEN  << std::endl;

		std::cout << "For " << ITALIC << UNDERLINE << "Vector" << RESET << GREEN <<" tests, enter: 1" << std::endl;
		std::cout << "For " << ITALIC << UNDERLINE << "Iterator" << RESET << GREEN <<" tests, enter: 2" << std::endl << std::endl;
		std::cout << "For " << ITALIC << UNDERLINE << "Functions" << RESET << GREEN <<" tests, enter: 5" << std::endl << std::endl;
		std::cout << RED << "Enter: 'Q' for quit" << RESET << std::endl;
		
		std::cout << "Choice: "; 
		std::cin >> input;
		std::cout << std::endl;

		switch (input[0])
		{
			case '1':
				chooseContainerStackTests();
				break ;
			case '2':
				chooseIteratorTests();
				break ;
			// case '5':
			// 	choosefunctionsTest();
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
