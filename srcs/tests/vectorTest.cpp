/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorTest.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:19:35 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/19 22:27:35 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.hpp"

void	printStack(ft::Vector<int> *stack_FT, std::vector<int> *stack_STD, std::string str)
{
	static int i = 1;
	
	std::cout << YELLOW << "Test Vector #["<< RED << i << YELLOW << "]: " << str << std::endl;
	std::cout << "----------------------------------------------------------------" << RESET  << std::endl;
	
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

void	vectorTestint(void)
{	
	std::cout << std::boolalpha;
	
	std::cout << std::endl;
	std::cout << RED << "/*******************************" << GREEN << " Vector<int> " << RED << "*******************************/" << RESET << std::endl;
	std::cout << std::endl;

	int		myints[] = {75, 223, 65, 42, 113};
	int		myints2[] = {2, 4, 6, 8, 10};
	
	// Test 1 //
	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;
	
	// Init vector //
	ft::Vector<int>		vector_FT(myints, myints + 5);
	ft::Vector<int>		vector_FT2(myints2, myints2 + 5);
	std::vector<int>	vector_STD(myints, myints + 5);
	std::vector<int>	vector_STD2(myints2, myints2 + 5);
	
	printStack(&vector_FT, &vector_STD, "Add: {75, 223, 65, 42, 113} to vector");

	// Test 2 //
	vector_FT.resize(14);
	vector_STD.resize(14);
	printStack(&vector_FT, &vector_STD, "resize(14)");

	// Test 3 //
	vector_FT.push_back(4224);
	vector_STD.push_back(4224);
	printStack(&vector_FT, &vector_STD, "push_back(4224)");

	// Test 4 //
	vector_FT.pop_back();
	vector_STD.pop_back();
	printStack(&vector_FT, &vector_STD, "pop_back()");

	// Test 5 //
	vector_FT.insert(vector_FT.begin() + 9, 99);
	vector_STD.insert(vector_STD.begin() + 9, 99);
	printStack(&vector_FT, &vector_STD, "insert(vector_FT.begin() + 9, 99)");
	
	// Test 6 //
	vector_FT.reserve(33);
	vector_STD.reserve(33);
	printStack(&vector_FT, &vector_STD, "reserve(33)");

	// Test 7 //
	vector_FT.erase(vector_FT.begin() + 3);
	vector_STD.erase(vector_STD.begin() + 3);
	printStack(&vector_FT, &vector_STD, "erase(vector_FT.begin() + 3)");

	// Test 8 //
	vector_FT.erase(vector_FT.begin() + 3, vector_FT.begin() + 5);
	vector_STD.erase(vector_STD.begin() + 3, vector_STD.begin() + 5);
	printStack(&vector_FT, &vector_STD, "erase(vector_FT.begin() + 3, vector_FT.begin() + 5)");

	// Test 9 //
	vector_FT.assign(5, 42);
	vector_STD.assign(5, 42);
	printStack(&vector_FT, &vector_STD, "assign(5, 42)");

	// Test 10 //
	vector_FT.resize(3);
	vector_STD.resize(3);
	printStack(&vector_FT, &vector_STD, "resize(3)");
	
	// Test 11 //
	vector_FT.swap(vector_FT2);
	vector_STD.swap(vector_STD2);
	printStack(&vector_FT, &vector_STD, "swap(vector_FT2 = {2, 4, 6, 8, 10})");

	// Test 12 //
	vector_FT.clear();
	vector_STD.clear();
	printStack(&vector_FT, &vector_STD, "clear()");
	
	std::cout << GREEN << "--------------------- END VECTOR TESTS<int> --------------------" << RESET << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;

}
