/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:19:35 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/17 21:57:42 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/container.hpp"

void	printStack(ft::stack<int> stack_FT)
{
	std::cout << BLUE << "stack_FT.empty(): " << stack_FT.empty() << std::endl;
	std::cout << "stack_FT.size(): " << stack_FT.size() << std::endl;
	std::cout << "stack_FT.top(): " << stack_FT.top() << std::endl;
	for (size_t i = 0; i < stack_FT.size(); i++)
	{
		std::cout << stack_FT.top() << " ";
		stack_FT.pop();
	}
	std::cout << RESET << std::endl;
}

void	printStackSTD(std::stack<int> stack_STD)
{
	std::cout << GREEN << "stack_STD.empty(): " << stack_STD.empty() << std::endl;
	std::cout << "stack_STD.size(): " << stack_STD.size() << std::endl;
	std::cout << "stack_STD.top(): " << stack_STD.top() << std::endl;
	for (size_t i = 0; i < stack_STD.size(); i++)
	{
		std::cout << stack_STD.top() << " ";
		stack_STD.pop();
	}
	std::cout << RESET << std::endl;
}

int main(void)
{	
	std::cout << std::boolalpha;
	
	std::cout << std::endl;
	std::cout << RED << "/*******************************" << GREEN << " STACK " << RED << "*******************************/" << RESET << std::endl;
	std::cout << std::endl;
	
	ft::stack<int> stack_FT;
	std::stack<int> stack_STD;

	std::cout << YELLOW << "ft::stack<int> stack_FT;" << std::endl;
	std::cout << "----------------------------------------" << RESET  << std::endl;
	std::cout << BLUE << "stack_FT.empty(): " << stack_FT.empty() << std::endl;
	std::cout << "stack_FT.size(): " << stack_FT.size() << RESET << std::endl << std::endl;
	
	std::cout << YELLOW << "std::stack<int> stack_STD;" << std::endl;
	std::cout << "----------------------------------------" << RESET  << std::endl;
	std::cout << GREEN << "stack_STD.empty(): " << stack_STD.empty() << std::endl;
	std::cout << "stack_STD.size(): " << stack_STD.size() << RESET << std::endl << std::endl;
//
	std::cout << RED << "----------------------------------------------------------------" << RESET  << std::endl;
	
	stack_FT.push(12);
	std::cout << YELLOW << "stack_FT.push(12)" << std::endl;
	std::cout << "----------------------------------------" << RESET  << std::endl;
	printStack(stack_FT);
	std::cout << std::endl;

	stack_STD.push(12);
	std::cout << YELLOW << "stack_STD.push(12)" << std::endl;
	std::cout << "----------------------------------------" << RESET  << std::endl;
	printStackSTD(stack_STD);
//
	std::cout << RED << "----------------------------------------------------------------" << RESET  << std::endl << std::endl;

	stack_FT.push(3);
	std::cout <<  YELLOW <<"stack_FT.push(3)" << std::endl;
	std::cout << "----------------------------------------" << RESET  << std::endl;
	printStack(stack_FT);
	std::cout << std::endl;

	stack_STD.push(3);
	std::cout <<  YELLOW <<"stack_STD.push(3)" << std::endl;
	std::cout << "----------------------------------------" << RESET  << std::endl;
	printStackSTD(stack_STD);
//
	std::cout << RED << "----------------------------------------------------------------" << RESET  << std::endl << std::endl;

	for (int i = 0; i < 5; i++)
		stack_FT.push(i * 4);
	std::cout << YELLOW << "stack_FT.push(i * 4)" << std::endl;
	std::cout << "----------------------------------------" << RESET  << std::endl;
	printStack(stack_FT);
	std::cout << std::endl;

	for (int i = 0; i < 5; i++)
		stack_STD.push(i * 4);
	std::cout << YELLOW << "stack_STD.push(i * 4)" << std::endl;
	std::cout << "----------------------------------------" << RESET  << std::endl;
	printStackSTD(stack_STD);
//
	std::cout << RED << "----------------------------------------------------------------" << RESET  << std::endl << std::endl;

	for (int i = 0; i < 5; i++)
		stack_FT.push((i * 2) + 60);
	std::cout << YELLOW << "stack_FT.push((i * 2) + 60)" << std::endl;
	std::cout << "----------------------------------------" << RESET  << std::endl;
	printStack(stack_FT);
	std::cout << std::endl;

	for (int i = 0; i < 5; i++)
		stack_STD.push((i * 2) + 60);
	std::cout << YELLOW << "stack_STD.push((i * 2) + 60)" << std::endl;
	std::cout << "----------------------------------------" << RESET  << std::endl;
	printStackSTD(stack_STD);
//
	std::cout << RED << "----------------------------------------------------------------" << RESET  << std::endl << std::endl;
	
	return 0;
}
