/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorTest.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:19:35 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/18 20:16:45 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.hpp"

// void	printStack(ft::stack<int> stack_FT)
// {
// 	std::cout << BLUE << "stack_FT.empty(): " << stack_FT.empty() << std::endl;
// 	std::cout << "stack_FT.size(): " << stack_FT.size() << std::endl;
// 	std::cout << "stack_FT.top(): " << stack_FT.top() << std::endl;
// 	for (size_t i = 0; i < stack_FT.size(); i++)
// 	{
// 		std::cout << stack_FT.top() << " ";
// 		stack_FT.pop();
// 	}
// 	std::cout << RESET << std::endl;
// }

// void	printStackSTD(std::stack<int> stack_STD)
// {
// 	std::cout << GREEN << "stack_STD.empty(): " << stack_STD.empty() << std::endl;
// 	std::cout << "stack_STD.size(): " << stack_STD.size() << std::endl;
// 	std::cout << "stack_STD.top(): " << stack_STD.top() << std::endl << std::endl;
// 	for (size_t i = 0; i < stack_STD.size(); i++)
// 	{
// 		std::cout << stack_STD.top() << " ";
// 		stack_STD.pop();
// 	}
// 	std::cout << RESET << std::endl;
// }

void	printStack(ft::Vector<int> *stack_FT, std::vector<int> *stack_STD, std::string str)
{
	static int i = 1;
	
	std::cout << YELLOW << "Test Vector #[" << i << "]: " << str << std::endl;
	std::cout << "----------------------------------------" << RESET  << std::endl;
	
	std::cout << BLUE << "vector_FT.size(): " << stack_FT->size() << std::endl;
	std::cout << "vector_FT.max_size(): " << stack_FT->max_size() << std::endl;
	std::cout << "vector_FT.capacity(): " << stack_FT->capacity() << MAGENTA << std::endl;
	for (size_t i = 0; i < stack_FT->size(); i++)
		std::cout << stack_FT->at(i) << " ";

	std::cout << std::endl << std::endl;

	std::cout << GREEN << "vector_STD.size(): " << stack_STD->size() << std::endl;
	std::cout << "vector_STD.max_size(): " << stack_STD->max_size() << std::endl;
	std::cout << "vector_STD.capacity(): " << stack_STD->capacity() << MAGENTA << std::endl;
	for (size_t i = 0; i < stack_STD->size(); i++)
		std::cout << stack_STD->at(i) << " ";

	std::cout << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET  << std::endl;
	std::cout << std::endl;

	i++;
}

void	vectorTest(void)
{	
	std::cout << std::boolalpha;
	
	std::cout << std::endl;
	std::cout << RED << "/*******************************" << GREEN << " Vector " << RED << "*******************************/" << RESET << std::endl;
	std::cout << std::endl;

	int		myints[] = {75, 223, 65, 42, 113};
	
	// Test 1 //
	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;
	ft::Vector<int>		vector_FT(myints, myints + 5);
	std::vector<int>	vector_STD(myints, myints + 5);
	printStack(&vector_FT, &vector_STD, "Add: {75, 223, 65, 42, 113} to vector");

	// Test 2 //
	vector_FT.resize(14);
	vector_STD.resize(14);
	printStack(&vector_FT, &vector_STD, "resize(24)");

	// Test 3 //
	vector_FT.push_back(4224);
	vector_STD.push_back(4224);
	printStack(&vector_FT, &vector_STD, "push_back(4224)");

	// Test 4 //
	vector_FT.pop_back();
	vector_STD.pop_back();
	printStack(&vector_FT, &vector_STD, "pop_back()");

	// Test 5 //
	// vector_FT.insert(vector_FT.begin() + 9, 99);
	// vector_STD.insert(vector_STD.begin() + 9, 99);
	
}
