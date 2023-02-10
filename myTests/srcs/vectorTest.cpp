/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorTest.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:19:35 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/10 15:24:31 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/container.hpp"
#include <vector>

template <typename T>
void	printStack(ft::vector<T> *stack_FT, std::vector<T> *stack_STD,
					std::string str, std::string type, int reset)
{
	static int i = 1;

	if (reset == 1)
		i = 1;
	
	std::cout << YELLOW << "Test " << BLUE << type << YELLOW << " #["<< RED << i \
		<< YELLOW << "]: " << str << std::endl;
	std::cout << "----------------------------------------------------------------" \
		<< RESET  << std::endl;
	
	std::cout << GREEN << "vector_FT.size(): " << stack_FT->size() << std::endl;
	std::cout << "vector_FT.capacity(): " << stack_FT->capacity() << MAGENTA << std::endl;
	for (size_t i = 0; i < stack_FT->size(); i++)
		std::cout << "[" << stack_FT->at(i) << "] ";

	std::cout << std::endl << std::endl;

	std::cout << BLUE << "vector_STD.size(): " << stack_STD->size() << std::endl;
	std::cout << "vector_STD.capacity(): " << stack_STD->capacity() << MAGENTA << std::endl;
	for (size_t i = 0; i < stack_STD->size(); i++)
		std::cout << "[" << stack_STD->at(i) << "] ";

	std::cout << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" \
		<< RESET  << std::endl;
	std::cout << std::endl;

	i++;
}

/****************************************************************************************************/
// Test Int //
void	vectorTestint(int flag)
{	
	std::cout << std::boolalpha;
	
	std::cout << std::endl;
	std::cout << RED << "/*******************************" << GREEN << " Vector<int> " \
		<< RED << "*******************************/" << RESET << std::endl;
	std::cout << std::endl;

	int		myints[] = {75, 223, 65, 42, 113};
	int		myints2[] = {2, 4, 6, 8, 10};
	
	std::cout << RED << "----------------------------------------------------------------" \
		<< RESET << std::endl << std::endl;
	
	// Init vector //
	ft::vector<int>		vector_FT(myints, myints + 5);
	ft::vector<int>		vector_FT2(myints2, myints2 + 5);
	std::vector<int>	vector_STD(myints, myints + 5);
	std::vector<int>	vector_STD2(myints2, myints2 + 5);

	struct timeval	time;

	gettimeofday(&time, NULL);
	long int msTime = time.tv_sec * 1000 + time.tv_usec / 1000;
	
	// Test 1 //
	if (flag == 1)
		printStack(&vector_FT, &vector_STD, "Add: {75, 223, 65, 42, 113} to vector", "int", 1);

	// Test 2 //
	vector_FT.resize(14);
	vector_STD.resize(14);
	if (flag == 1)
		printStack(&vector_FT, &vector_STD, "resize(14)", "int", 0);

	// Test 3 //
	vector_FT.push_back(4224);
	vector_FT.push_back(101);
	vector_STD.push_back(4224);
	vector_STD.push_back(101);
	if (flag == 1)
		printStack(&vector_FT, &vector_STD, "push_back(4224) && push_back(101)", "int", 0);

	// Test 4 //
	vector_FT.pop_back();
	vector_STD.pop_back();
	if (flag == 1)
		printStack(&vector_FT, &vector_STD, "pop_back()", "int", 0);

	// Test 5 //
	vector_FT.insert(vector_FT.begin() + 9, 99);
	vector_STD.insert(vector_STD.begin() + 9, 99);
	if (flag == 1)
		printStack(&vector_FT, &vector_STD, "insert(vector_FT.begin() + 9, 99)", "int", 0);
	
	// Test 6 //
	vector_FT.reserve(33);
	vector_STD.reserve(33);
	if (flag == 1)
		printStack(&vector_FT, &vector_STD, "reserve(33)", "int", 0);

	// Test 7 //
	vector_FT.erase(vector_FT.begin() + 3);
	vector_STD.erase(vector_STD.begin() + 3);
	if (flag == 1)
		printStack(&vector_FT, &vector_STD, "erase(vector_FT.begin() + 3)", "int", 0);

	// Test 8 //
	vector_FT.erase(vector_FT.begin() + 3, vector_FT.begin() + 5);
	vector_STD.erase(vector_STD.begin() + 3, vector_STD.begin() + 5);
	if (flag == 1)
		printStack(&vector_FT, &vector_STD, "erase(vector_FT.begin() + 3, vector_FT.begin() + 5)", "int", 0);

	// Test 9 //
	vector_FT.assign(5, 42);
	vector_STD.assign(5, 42);
	if (flag == 1)
		printStack(&vector_FT, &vector_STD, "assign(5, 42)", "int", 0);

	// Test 10 //
	vector_FT.resize(3);
	vector_STD.resize(3);
	if (flag == 1)
		printStack(&vector_FT, &vector_STD, "resize(3)", "int", 0);
	
	// Test 11 //
	vector_FT.swap(vector_FT2);
	vector_STD.swap(vector_STD2);
	if (flag == 1)
		printStack(&vector_FT, &vector_STD, "swap(vector_FT2 = {2, 4, 6, 8, 10})", "int", 0);

	// Test 12 //
	vector_FT.clear();
	vector_STD.clear();
	if (flag == 1)
		printStack(&vector_FT, &vector_STD, "clear()", "int", 0);

	if (flag == 0)
	{
		struct timeval	time2;

		gettimeofday(&time2, NULL);
		std::cout << "Time in ms: " << (time2.tv_sec * 1000 + time2.tv_usec / 1000) - msTime << std::endl;
	}
	

	std::cout << std::endl << std::endl;
	std::cout << RED << "--------------------------------------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << GREEN << "------------------------- END TESTS Vector<int> --------------------------" << RESET << std::endl << std::endl;
	std::cout << RED << "--------------------------------------------------------------------------" << RESET << std::endl << std::endl;

	
	std::string input;
	
	std::cout << "Press ENTER to continue" << std::endl;
	std::getline(std::cin, input);
	std::getline(std::cin, input);
	std::cout << "\e[1;1H\e[2J";
}

/****************************************************************************************************/
// Test double //
void	vectorTestDouble(void)
{	
	std::cout << std::boolalpha;
	
	std::cout << std::endl;
	std::cout << RED << "/*******************************" << GREEN << " Vector<DOUBLE> " \
		<< RED << "*******************************/" << RESET << std::endl;
	std::cout << std::endl;

	double	myints[] = {75, 223.44, 65, 42.42, 113};
	double	myints2[] = {2, 4.998, 6, 8.0625, 10};
	
	std::cout << RED << "----------------------------------------------------------------" \
		<< RESET << std::endl << std::endl;
	
	// Init vector //
	ft::vector<double>		vector_FT(myints, myints + 5);
	ft::vector<double>		vector_FT2(myints2, myints2 + 5);
	std::vector<double>		vector_STD(myints, myints + 5);
	std::vector<double>		vector_STD2(myints2, myints2 + 5);
	
	// Test 1 //
	printStack(&vector_FT, &vector_STD, "Add: {75, 223.44, 65, 42.42, 113} to vector", "double", 1);

	// Test 2 //
	vector_FT.resize(14);
	vector_STD.resize(14);
	printStack(&vector_FT, &vector_STD, "resize(14)", "double", 0);

	// Test 3 //
	vector_FT.push_back(422.47);
	vector_FT.push_back(101);
	vector_STD.push_back(422.47);
	vector_STD.push_back(101);
	printStack(&vector_FT, &vector_STD, "push_back(422.47) && push_back(101)", "double", 0);

	// Test 4 //
	vector_FT.pop_back();
	vector_STD.pop_back();
	printStack(&vector_FT, &vector_STD, "pop_back()", "double", 0);

	// Test 5 //
	vector_FT.insert(vector_FT.begin() + 9, 99);
	vector_STD.insert(vector_STD.begin() + 9, 99);
	printStack(&vector_FT, &vector_STD, "insert(vector_FT.begin() + 9, 99)", "double", 0);
	
	// Test 6 //
	vector_FT.reserve(33);
	vector_STD.reserve(33);
	printStack(&vector_FT, &vector_STD, "reserve(33)", "double", 0);

	// Test 7 //
	vector_FT.erase(vector_FT.begin() + 3);
	vector_STD.erase(vector_STD.begin() + 3);
	printStack(&vector_FT, &vector_STD, "erase(vector_FT.begin() + 3)", "double", 0);

	// Test 8 //
	vector_FT.erase(vector_FT.begin() + 3, vector_FT.begin() + 5);
	vector_STD.erase(vector_STD.begin() + 3, vector_STD.begin() + 5);
	printStack(&vector_FT, &vector_STD, "erase(vector_FT.begin() + 3, vector_FT.begin() + 5)", "double", 0);

	// Test 9 //
	vector_FT.assign(5, 42);
	vector_STD.assign(5, 42);
	printStack(&vector_FT, &vector_STD, "assign(5, 42)", "double", 0);

	// Test 10 //
	vector_FT.resize(3);
	vector_STD.resize(3);
	printStack(&vector_FT, &vector_STD, "resize(3)", "double", 0);
	
	// Test 11 //
	vector_FT.swap(vector_FT2);
	vector_STD.swap(vector_STD2);
	printStack(&vector_FT, &vector_STD, "swap(vector_FT2 = {2, 4.998, 6, 8.0625, 10})", "double", 0);

	// Test 12 //
	vector_FT.clear();
	vector_STD.clear();
	printStack(&vector_FT, &vector_STD, "clear()", "double", 0);
	
	std::cout << std::endl << std::endl;
	std::cout << RED << "---------------------------------------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << GREEN << "------------------------ END TESTS Vector<double> -------------------------" << RESET << std::endl << std::endl;
	std::cout << RED << "---------------------------------------------------------------------------" << RESET << std::endl << std::endl;
	

	std::string input;
	
	std::cout << "Press ENTER to continue" << std::endl;
	std::getline(std::cin, input);
	std::getline(std::cin, input);
	std::cout << "\e[1;1H\e[2J";
}

/****************************************************************************************************/
// Test string //
void	vectorTestString(void)
{	
	std::cout << std::boolalpha;
	
	std::cout << std::endl;
	std::cout << RED << "/*******************************" << GREEN << " Vector<STRING> " \
		<< RED << "*******************************/" << RESET << std::endl;
	std::cout << std::endl;

	std::string	myStrings[] = {"Hello", "World", "This", "Is", "A", "Test"};
	std::string	myStrings2[] = {"I", "dont", "know", "what", "i'm", "doing", "right", "now", "!!!"};
	
	std::cout << RED << "----------------------------------------------------------------" \
		<< RESET << std::endl << std::endl;
	
	// Init vector //
	ft::vector<std::string>		vector_FT(myStrings, myStrings + 6);
	ft::vector<std::string>		vector_FT2(myStrings2, myStrings2 + 9);
	std::vector<std::string>	vector_STD(myStrings, myStrings + 6);
	std::vector<std::string>	vector_STD2(myStrings2, myStrings2 + 9);
	
	// Test 1 //
	printStack(&vector_FT, &vector_STD, "Add: {Hello, World, This, Is, A, Test} to vector", "string", 1);

	// Test 2 //
	vector_FT.resize(14);
	vector_STD.resize(14);
	printStack(&vector_FT, &vector_STD, "resize(14)", "string", 0);

	// Test 3 //
	vector_FT.push_back("BbyShark");
	vector_FT.push_back("DooDooDooDooDoo");
	vector_STD.push_back("BbyShark");
	vector_STD.push_back("DooDooDooDooDoo");
	printStack(&vector_FT, &vector_STD, "push_back(BbyShark) && push_back(DooDooDooDooDoo)", "string", 0);

	// Test 4 //
	vector_FT.pop_back();
	vector_STD.pop_back();
	printStack(&vector_FT, &vector_STD, "pop_back()", "string", 0);

	// Test 5 //
	vector_FT.insert(vector_FT.begin() + 4, "Chuck Noris");
	vector_STD.insert(vector_STD.begin() + 4, "Chuck Noris");
	printStack(&vector_FT, &vector_STD, "insert(vector_FT.begin() + 4, Chuck Noris)", "string", 0);
	
	// Test 6 //
	vector_FT.reserve(33);
	vector_STD.reserve(33);
	printStack(&vector_FT, &vector_STD, "reserve(33)", "string", 0);

	// Test 7 //
	vector_FT.erase(vector_FT.begin() + 3);
	vector_STD.erase(vector_STD.begin() + 3);
	printStack(&vector_FT, &vector_STD, "erase(vector_FT.begin() + 3)", "string", 0);

	// Test 8 //
	vector_FT.erase(vector_FT.begin() + 3, vector_FT.begin() + 5);
	vector_STD.erase(vector_STD.begin() + 3, vector_STD.begin() + 5);
	printStack(&vector_FT, &vector_STD, "erase(vector_FT.begin() + 3, vector_FT.begin() + 5)", "string", 0);

	// Test 9 //
	vector_FT.assign(5, "BANKAI");
	vector_STD.assign(5, "BANKAI");
	printStack(&vector_FT, &vector_STD, "assign(5, BANKAI)", "string", 0);

	// Test 10 //
	vector_FT.resize(3);
	vector_STD.resize(3);
	printStack(&vector_FT, &vector_STD, "resize(3)", "string", 0);
	
	// Test 11 //
	vector_FT.swap(vector_FT2);
	vector_STD.swap(vector_STD2);
	printStack(&vector_FT, &vector_STD, "swap(vector_FT2 = {I, dont, know, what, i'm, doing, right, now, !!!})", "string", 0);

	// Test 12 //
	vector_FT.clear();
	vector_STD.clear();
	printStack(&vector_FT, &vector_STD, "clear()", "string", 0);
	
	std::cout << std::endl << std::endl;
	std::cout << RED << "---------------------------------------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << GREEN << "------------------------ END TESTS Vector<string> -------------------------" << RESET << std::endl << std::endl;
	std::cout << RED << "---------------------------------------------------------------------------" << RESET << std::endl << std::endl;

	
	std::string input;
	
	std::cout << "Press ENTER to continue" << std::endl;
	std::getline(std::cin, input);
	std::getline(std::cin, input);
	std::cout << "\e[1;1H\e[2J";
}

/****************************************************************************************************/

template <typename T>
void	printStructStack(ft::vector<T> *vector_FT, std::vector<T> *vector_STD,
						std::string str, std::string type, int nbr, int reset)
{
	static int		i = 1;
	static int		ct = 1;
	std::string		input = "";

	if (reset == 1)
	{
		i = 1;
		ct = 1;
	}
	if (ct == 1)
	{
		std::cout << "       Press 'A' to all tests" << std::endl;
		std::cout << "                 or" << std::endl;
		std::cout << "Press enter to continue to next test" << std::endl;
		
		std::getline(std::cin, input);
		if (input == "A" || input == "a")
			ct = 0;
	}

	std::cout << RED << "----------------------------------------------------------------" \
		<< RESET << std::endl << std::endl;
	std::cout << YELLOW << "Test " << BLUE << type << YELLOW << "#[" << MAGENTA << i
		<< YELLOW << "]: " << str << std::endl << std::endl;
	std::cout << "----------------------------------------------------------------" \
		<< RESET << std::endl << std::endl;
	
	for (int k = 0; k < nbr; k++)
	{
		std::cout << GREEN << "Place in array #: " << CYAN << k << std::endl << std::endl;
			
		std::cout << GREEN << "ft::Vector<" << MAGENTA << type << GREEN">.size():     " \
			<< MAGENTA << vector_FT->size() << std::endl;
		std::cout << GREEN << "ft::Vector<" << MAGENTA << type << GREEN">.capacity(): " \
			<< MAGENTA << vector_FT->capacity() << std::endl;
		std::cout << GREEN << "ft::Vector<" << MAGENTA << type << GREEN"> nbr:        " \
			<< MAGENTA << vector_FT->at(k)._nbr << std::endl;
		std::cout << GREEN << "ft::Vector<" << MAGENTA << type << GREEN"> str:        " \
			<< MAGENTA << vector_FT->at(k)._str << std::endl;
		std::cout << GREEN << "ft::Vector<" << MAGENTA << type << GREEN"> vec2.x:     " \
			<< MAGENTA << vector_FT->at(k)._vec.x \
			<< GREEN << "  vec2.y: " << MAGENTA << vector_FT->at(k)._vec.y << RESET << std::endl;
		std::cout << YELLOW << "----------------------------------------------------------------" \
			<< RESET << std::endl << std::endl;
		
		std::cout << GREEN << "Place in array #: " << CYAN << k << std::endl << std::endl;
		
		std::cout << BLUE << "std::Vector<" << MAGENTA << type << BLUE">.size():     " \
			<< MAGENTA << vector_STD->size() << std::endl;
		std::cout << BLUE << "std::Vector<" << MAGENTA << type << BLUE">.capacity(): " \
			<< MAGENTA << vector_STD->capacity() << std::endl;
		std::cout << BLUE << "std::Vector<" << MAGENTA << type << BLUE"> nbr:        " \
			<< MAGENTA << vector_STD->at(k)._nbr << std::endl;
		std::cout << BLUE << "std::Vector<" << MAGENTA << type << BLUE"> str:        " \
			<< MAGENTA << vector_STD->at(k)._str << std::endl;
		std::cout << BLUE << "std::Vector<" << MAGENTA << type << BLUE"> vec2.x:     " \
			<< MAGENTA << vector_STD->at(k)._vec.x \
			<< BLUE << "  vec2.y: " << MAGENTA << vector_STD->at(k)._vec.y << RESET << std::endl;
		std::cout << YELLOW << "----------------------------------------------------------------" \
			<< RESET << std::endl << std::endl;
	}
	
	std::cout << RED << "----------------------------------------------------------------" \
			<< RESET << std::endl << std::endl;
	i++;
}

// Test struct //
void	vectorTestStruct(void)
{	
	std::cout << std::boolalpha;
	
	std::cout << std::endl;
	std::cout << RED << "/*******************************" << GREEN << " Vector<STRUCT> " \
		<< RED << "*******************************/" << RESET << std::endl;
	std::cout << std::endl;

	StructA		myStruct[] = {StructA("Hello", 1, (Vector2){2, 4}), StructA("World", 2, (Vector2){3, 5}),
					StructA("This", 3, (Vector2){4, 6}), StructA("Is", 4, (Vector2){5, 7}),
					StructA("A", 5, (Vector2){6, 8}), StructA("Test", 6, (Vector2){7, 9})};
					
	StructA		myStruct2[] = {StructA("I", 1, (Vector2){22, 44}), StructA("dont", 2, (Vector2){33, 55}),
					StructA("know", 3, (Vector2){44, 66}), StructA("what", 4, (Vector2){55, 77}),
					StructA("i'm", 5, (Vector2){66, 88}), StructA("doing", 6, (Vector2){77, 99}),
					StructA("right", 7, (Vector2){88, 100}), StructA("now", 8, (Vector2){99, 101}),
					StructA("!!!", 9, (Vector2){100, 102})};
	
	std::cout << RED << "----------------------------------------------------------------" \
		<< RESET << std::endl << std::endl;
	
	// Init vector //
	ft::vector<StructA>		vector_FT(myStruct, myStruct + 5);
	ft::vector<StructA>		vector_FT2(myStruct2, myStruct2 + 9);
	std::vector<StructA>	vector_STD(myStruct, myStruct + 5);
	std::vector<StructA>	vector_STD2(myStruct2, myStruct2 + 9);

	StructA			tmp = StructA("Banana", 27, (Vector2){12, 14});
	StructA			tmp2 = StructA("Encore", 11, (Vector2){55, 55});
	StructA			tmp3 = StructA("BbyShark", 71, (Vector2){69, 69});
	StructA			tmp4 = StructA("BANKAI", 88, (Vector2){9999, 9999});
	
	// Test 1 //
	printStructStack(&vector_FT, &vector_STD, "Add 5 struct like: StructA(Hello, 1, (Vector2){2, 4})", "struct", 5, 1);

	// Test 2 //
	vector_FT.resize(14);
	vector_STD.resize(14);
	printStructStack(&vector_FT, &vector_STD, "resize(14)", "struct", 14, 0);

	// Test 3 //
	vector_FT.push_back(tmp);
	vector_FT.push_back(tmp2);
	vector_STD.push_back(tmp);
	vector_STD.push_back(tmp2);
	printStructStack(&vector_FT, &vector_STD, "push_back(StructA tmp) && push_back(StructA tmp2)", "struct", 16, 0);

	// Test 4 //
	vector_FT.pop_back();
	vector_STD.pop_back();
	printStructStack(&vector_FT, &vector_STD, "pop_back()", "struct", 15, 0);

	// Test 5 //
	vector_FT.insert(vector_FT.begin() + 4, tmp3);
	vector_STD.insert(vector_STD.begin() + 4, tmp3);
	printStructStack(&vector_FT, &vector_STD, "insert(vector_FT.begin() + 4, StructA tmp3)", "struct", 16, 0);
	
	// Test 6 //
	vector_FT.reserve(33);
	vector_STD.reserve(33);
	printStructStack(&vector_FT, &vector_STD, "reserve(33)", "struct", 16, 0);

	// Test 7 //
	vector_FT.erase(vector_FT.begin() + 3);
	vector_STD.erase(vector_STD.begin() + 3);
	printStructStack(&vector_FT, &vector_STD, "erase(vector_FT.begin() + 3)", "struct", 15, 0);

	// Test 8 //
	vector_FT.erase(vector_FT.begin() + 3, vector_FT.begin() + 5);
	vector_STD.erase(vector_STD.begin() + 3, vector_STD.begin() + 5);
	printStructStack(&vector_FT, &vector_STD, "erase(vector_FT.begin() + 3, vector_FT.begin() + 5)", "struct", 13, 0);

	// Test 9 //
	vector_FT.assign(5, tmp4);
	vector_STD.assign(5, tmp4);
	printStructStack(&vector_FT, &vector_STD, "assign(5, StructA tmp4)", "struct", 5, 0);

	// Test 10 //
	vector_FT.resize(3);
	vector_STD.resize(3);
	printStructStack(&vector_FT, &vector_STD, "resize(3)", "struct", 3, 0);
	
	// Test 11 //
	vector_FT.swap(vector_FT2);
	vector_STD.swap(vector_STD2);
	printStructStack(&vector_FT, &vector_STD, "swap(vector_FT2 with another struct array)", "struct", 3, 0);

	// Test 12 //
	vector_FT.clear();
	vector_STD.clear();
	printStructStack(&vector_FT, &vector_STD, "clear()", "struct", 0, 0);
	
	std::cout << std::endl << std::endl;
	std::cout << RED << "---------------------------------------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << GREEN << "------------------------ END TESTS Vector<struct> -------------------------" << RESET << std::endl << std::endl;
	std::cout << RED << "---------------------------------------------------------------------------" << RESET << std::endl << std::endl;
	

	std::string input;
	
	std::cout << "Press ENTER to continue" << std::endl;
	std::getline(std::cin, input);
	std::cout << "\e[1;1H\e[2J";
}

/****************************************************************************************************/
// Test class //

void	vectorTestClass(void)
{	
	std::cout << std::boolalpha;
	
	std::cout << std::endl;
	std::cout << RED << "/*******************************" << GREEN << " Vector<CLASS> " \
		<< RED << "*******************************/" << RESET << std::endl;
	std::cout << std::endl;

	A	myStruct[] = {A("Hello", 1, (Vector2){2, 4}), A("World", 2, (Vector2){3, 5}),
			A("This", 3, (Vector2){4, 6}), A("Is", 4, (Vector2){5, 7}),
			A("A", 5, (Vector2){6, 8}), A("Test", 6, (Vector2){7, 9})};
					
	A	myStruct2[] = {A("I", 1, (Vector2){22, 44}), A("dont", 2, (Vector2){33, 55}),
			A("know", 3, (Vector2){44, 66}), A("what", 4, (Vector2){55, 77}),
			A("i'm", 5, (Vector2){66, 88}), A("doing", 6, (Vector2){77, 99}),
			A("right", 7, (Vector2){88, 100}), A("now", 8, (Vector2){99, 101}),
			A("!!!", 9, (Vector2){100, 102})};
	
	std::cout << RED << "----------------------------------------------------------------" \
		<< RESET << std::endl << std::endl;
	
	// Init vector //
	ft::vector<A>		vector_FT(myStruct, myStruct + 5);
	ft::vector<A>		vector_FT2(myStruct2, myStruct2 + 9);
	std::vector<A>		vector_STD(myStruct, myStruct + 5);
	std::vector<A>		vector_STD2(myStruct2, myStruct2 + 9);

	A	tmp = A("Banana", 27, (Vector2){12, 14});
	A	tmp2 = A("Encore", 11, (Vector2){55, 55});
	A	tmp3 = A("BbyShark", 71, (Vector2){69, 69});
	A	tmp4 = A("BANKAI", 88, (Vector2){9999, 9999});
	
	// Test 1 //
	printStructStack(&vector_FT, &vector_STD, "Add 5 class like: A(Hello, 1, (Vector2){2, 4})", "class", 5, 1);

	// Test 2 //
	vector_FT.resize(14);
	vector_STD.resize(14);
	printStructStack(&vector_FT, &vector_STD, "resize(14)", "class", 14, 0);

	// Test 3 //
	vector_FT.push_back(tmp);
	vector_FT.push_back(tmp2);
	vector_STD.push_back(tmp);
	vector_STD.push_back(tmp2);
	printStructStack(&vector_FT, &vector_STD, "push_back(A tmp) && push_back(A tmp2)", "class", 16, 0);

	// Test 4 //
	vector_FT.pop_back();
	vector_STD.pop_back();
	printStructStack(&vector_FT, &vector_STD, "pop_back()", "class", 15, 0);

	// Test 5 //
	vector_FT.insert(vector_FT.begin() + 4, tmp3);
	vector_STD.insert(vector_STD.begin() + 4, tmp3);
	printStructStack(&vector_FT, &vector_STD, "insert(vector_FT.begin() + 4, A tmp3)", "class", 16, 0);
	
	// Test 6 //
	vector_FT.reserve(33);
	vector_STD.reserve(33);
	printStructStack(&vector_FT, &vector_STD, "reserve(33)", "class", 16, 0);

	// Test 7 //
	vector_FT.erase(vector_FT.begin() + 3);
	vector_STD.erase(vector_STD.begin() + 3);
	printStructStack(&vector_FT, &vector_STD, "erase(vector_FT.begin() + 3)", "class", 15, 0);

	// Test 8 //
	vector_FT.erase(vector_FT.begin() + 3, vector_FT.begin() + 5);
	vector_STD.erase(vector_STD.begin() + 3, vector_STD.begin() + 5);
	printStructStack(&vector_FT, &vector_STD, "erase(vector_FT.begin() + 3, vector_FT.begin() + 5)", "class", 13, 0);

	// Test 9 //
	vector_FT.assign(5, tmp4);
	vector_STD.assign(5, tmp4);
	printStructStack(&vector_FT, &vector_STD, "assign(5, A tmp4)", "class", 5, 0);

	// Test 10 //
	vector_FT.resize(3);
	vector_STD.resize(3);
	printStructStack(&vector_FT, &vector_STD, "resize(3)", "class", 3, 0);
	
	// Test 11 //
	vector_FT.swap(vector_FT2);
	vector_STD.swap(vector_STD2);
	printStructStack(&vector_FT, &vector_STD, "swap(vector_FT2 with another class array)", "class", 3, 0);

	// Test 12 //
	vector_FT.clear();
	vector_STD.clear();
	printStructStack(&vector_FT, &vector_STD, "clear()", "class", 0, 0);
	
	std::cout << std::endl << std::endl;
	std::cout << RED << "--------------------------------------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << GREEN << "------------------------ END TESTS Vector<class> -------------------------" << RESET << std::endl << std::endl;
	std::cout << RED << "--------------------------------------------------------------------------" << RESET << std::endl << std::endl;

	
	std::string input;
	
	std::cout << "Press ENTER to continue" << std::endl;
	std::getline(std::cin, input);
	std::cout << "\e[1;1H\e[2J";
}
