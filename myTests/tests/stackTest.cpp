/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackTest.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:49:34 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/07 23:12:40 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.hpp"

template <typename T>
void	printOperators(ft::stack<T> stackFT, ft::stack<T> stackFT2, std::stack<T> stackSTD,
						std::stack<T> stackSTD2, std::string type, std::string str, int nbr)
{
	(void)stackFT2;
	(void)stackFT;
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test Stack<" << MAGENTA << type << YELLOW <<"> #["
		<< MAGENTA << nbr << YELLOW << "]: " << str << std::endl;
	std::cout << "----------------------------------------" << RESET  << std::endl;
	std::cout << GREEN << "ft::Stack == ft::Stack2 : " << MAGENTA << (stackFT == stackFT2) << std::endl;
	std::cout << GREEN << "ft::Stack != ft::Stack2 : " << MAGENTA << (stackFT != stackFT2) << std::endl;
	std::cout << GREEN << "ft::Stack < ft::Stack2  : " << MAGENTA << (stackFT < stackFT2) << std::endl;
	std::cout << GREEN << "ft::Stack <= ft::Stack2 : " << MAGENTA << (stackFT <= stackFT2) << std::endl;
	std::cout << GREEN << "ft::Stack > ft::Stack2  : " << MAGENTA << (stackFT > stackFT2) << std::endl;
	std::cout << GREEN << "ft::Stack >= ft::Stack2 : " << MAGENTA << (stackFT >= stackFT2) << std::endl;
	std::cout << std::endl;

	std::cout << BLUE << "std::Stack == std::Stack2 : " << MAGENTA << (stackSTD == stackSTD2) << std::endl;
	std::cout << BLUE << "std::Stack != std::Stack2 : " << MAGENTA << (stackSTD != stackSTD2) << std::endl;
	std::cout << BLUE << "std::Stack < std::Stack2  : " << MAGENTA << (stackSTD < stackSTD2) << std::endl;
	std::cout << BLUE << "std::Stack <= std::Stack2 : " << MAGENTA << (stackSTD <= stackSTD2) << std::endl;
	std::cout << BLUE << "std::Stack > std::Stack2  : " << MAGENTA << (stackSTD > stackSTD2) << std::endl;
	std::cout << BLUE << "std::Stack >= std::Stack2 : " << MAGENTA << (stackSTD >= stackSTD2) << std::endl;
	std::cout << RESET << std::endl << std::endl;
}

template <typename T>
void	printStack(ft::stack<T> stackFT, std::stack<T> stackSTD, std::string str, std::string type, int i)
{
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test Stack<" << MAGENTA << type << YELLOW <<"> #["
		<< MAGENTA << i << YELLOW << "]: " << str << std::endl;
	std::cout << "----------------------------------------" << RESET  << std::endl;
	
	std::cout << GREEN << "ft::Stack size     : " << MAGENTA << stackFT.size() << std::endl;
	std::cout << GREEN << "ft::Stack top      : " << MAGENTA << stackFT.top() << std::endl;
	std::cout << GREEN << "ft::Stack content : " << MAGENTA;
	while (!stackFT.empty())
	{
		std::cout << "[" << stackFT.top() << "] ";
		stackFT.pop();
	}
	std::cout << std::endl << std::endl;
	
	std::cout << BLUE << "std::Stack size    : " << MAGENTA << stackSTD.size() << std::endl;
	std::cout << BLUE << "std::Stack top     : " << MAGENTA << stackSTD.top() << std::endl;
	std::cout << BLUE << "std::Stack content: " << MAGENTA;
	while (!stackSTD.empty())
	{
		std::cout << "[" << stackSTD.top() << "] ";
		stackSTD.pop();
	}
	std::cout << RESET << std::endl << std::endl;
}

/********************************************************************************************/
// Stack<int> test
void    stackIntTest(void)
{
	std::cout << std::boolalpha;
	
	std::cout << std::endl;
	std::cout << RED << "/*******************************" << GREEN << " Stack<int> " \
		<< RED << "*******************************/" << RESET << std::endl;
	std::cout << std::endl;

	// Init stack //
	ft::stack<int> stackFT;
	ft::stack<int> stackFT2;
	std::stack<int> stackSTD;
	std::stack<int> stackSTD2;

	// Test 1: push() //
	for (int i = 0; i < 5; i++)
	{
		stackFT.push(i * 2);
		stackFT2.push(i * 4);
		stackSTD.push(i * 2);
		stackSTD2.push(i * 4);
	}
	printStack(stackFT, stackSTD, "Init stack", "int", 1);

	// Test 2: pop() //
	for (int i = 0; i < 2; i++)
	{
		stackFT.pop();
		stackSTD.pop();
	}
	printStack(stackFT, stackSTD, "2 * pop()", "int", 2);

	// Test 3: relational operators //
	printOperators(stackFT, stackFT2, stackSTD, stackSTD2, "int", "relational operators", 3);

	// Test 4: stack1 = stack2 //
	stackFT = stackFT2;
	stackSTD = stackSTD2;
	printStack(stackFT, stackSTD, "stack1 = stack2", "int", 4);
	printOperators(stackFT, stackFT2, stackSTD, stackSTD2, "int", "stack1 = stack2", 4);

	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << GREEN << "------------ END TESTS Stack< INT > -------------" << RESET << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;


	std::string input;
	
	std::cout << "Press ENTER to continue" << std::endl;
	std::getline(std::cin, input);
	std::getline(std::cin, input);
	std::cout << "\e[1;1H\e[2J";
}

/********************************************************************************************/
// Stack<float> test
void    stackFloatTest(void)
{
	std::cout << std::boolalpha;
	
	std::cout << std::endl;
	std::cout << RED << "/*******************************" << GREEN << " Stack<float> " \
		<< RED << "*******************************/" << RESET << std::endl;
	std::cout << std::endl;

	// Init stack //
	ft::stack<float> stackFT;
	ft::stack<float> stackFT2;
	std::stack<float> stackSTD;
	std::stack<float> stackSTD2;

	// Test 1: push() //
	for (int i = 0; i < 5; i++)
	{
		stackFT.push(i * 2.54f);
		stackFT2.push(i * 4.42f);
		stackSTD.push(i * 2.54f);
		stackSTD2.push(i * 4.42f);
	}
	printStack(stackFT, stackSTD, "Init stack", "float", 1);

	// Test 2: pop() //
	for (int i = 0; i < 2; i++)
	{
		stackFT.pop();
		stackSTD.pop();
	}
	printStack(stackFT, stackSTD, "2 * pop()", "float", 2);

	// Test 3: relational operators //
	printOperators(stackFT, stackFT2, stackSTD, stackSTD2, "float", "relational operators", 3);

	// Test 4: stack1 = stack2 //
	stackFT = stackFT2;
	stackSTD = stackSTD2;
	printStack(stackFT, stackSTD, "stack1 = stack2", "float", 4);
	printOperators(stackFT, stackFT2, stackSTD, stackSTD2, "float", "stack1 = stack2", 4);

	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << GREEN << "------------ END TESTS Stack< float > -------------" << RESET << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;
	

	std::string input;
	
	std::cout << "Press ENTER to continue" << std::endl;
	std::getline(std::cin, input);
	std::getline(std::cin, input);
	std::cout << "\e[1;1H\e[2J";
}

/********************************************************************************************/
// Stack<class> test

template <typename T>
void	printStackClass(ft::stack<T> stackFT, std::stack<T> stackSTD, std::string str,
						std::string type, int i, int reset)
{
	static int		ct = 1;
	std::string		input = "";

	if (ct == 1)
	{
		std::cout << "       Press 'A' to all tests" << std::endl;
		std::cout << "                 or" << std::endl;
		std::cout << "Press enter to continue to next test" << std::endl;
		
		std::getline(std::cin, input);
		if (input == "A" || input == "a")
			ct = 0;
	}
	if (reset == 1)
		ct = 1;
	
	std::cout << RED << "----------------------------------------------------------------"
		<< RESET  << std::endl << std::endl;
	std::cout << YELLOW << "Test Stack<" << MAGENTA << type << YELLOW <<"> #["
		<< MAGENTA << i << YELLOW << "]: " << str << std::endl;
	std::cout << "----------------------------------------" << RESET  << std::endl;
	
	std::cout << GREEN << "ft::Stack size     : " << MAGENTA << stackFT.size() << std::endl;
	std::cout << BLUE << "std::Stack size    : " << MAGENTA << stackSTD.size() << std::endl << std::endl;
	
	size_t k = stackFT.size() - 1;
	while (!stackFT.empty() || !stackSTD.empty())
	{
		T tmp = stackFT.top();

		std::cout << GREEN << "Place in array #: " << CYAN << k << std::endl << std::endl;
			
		std::cout << GREEN << "ft::Stack<" << MAGENTA << type << GREEN"> nbr:        " \
			<< MAGENTA << tmp._nbr << std::endl;
		std::cout << GREEN << "ft::Stack<" << MAGENTA << type << GREEN"> str:        " \
			<< MAGENTA << tmp._str << std::endl;
		std::cout << GREEN << "ft::Stack<" << MAGENTA << type << GREEN"> vec2.x:     " \
			<< MAGENTA << tmp._vec.x \
			<< GREEN << "  vec2.y: " << MAGENTA << tmp._vec.y << RESET << std::endl;
		std::cout << YELLOW << "----------------------------------------------------------------" \
			<< RESET << std::endl << std::endl;
		stackFT.pop();

		tmp = stackSTD.top();
		std::cout << BLUE << "Place in array #: " << CYAN << k << std::endl << std::endl;
			
		std::cout << BLUE << "std::Stack<" << MAGENTA << type << BLUE"> nbr:        " \
			<< MAGENTA << tmp._nbr << std::endl;
		std::cout << BLUE << "std::Stack<" << MAGENTA << type << BLUE"> str:        " \
			<< MAGENTA << tmp._str << std::endl;
		std::cout << BLUE << "std::Stack<" << MAGENTA << type << BLUE"> vec2.x:     " \
			<< MAGENTA << tmp._vec.x \
			<< BLUE << "  vec2.y: " << MAGENTA << tmp._vec.y << RESET << std::endl;
		std::cout << YELLOW << "----------------------------------------------------------------" \
			<< RESET << std::endl << std::endl;	
		stackSTD.pop();
		
		k--;
	}
	
	std::cout << RESET << std::endl << std::endl;
}

/********************************************************************************************/
// Stack<struct> test
void    stackStructTest(void)
{
	std::cout << std::boolalpha;
	
	std::cout << std::endl;
	std::cout << RED << "/*******************************" << GREEN << " Stack<Struct> " 
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
	
	std::cout << RED << "----------------------------------------------------------------" 
		<< RESET << std::endl << std::endl;
	
	// Init stack //
	ft::stack<StructA>	stackFT;
	ft::stack<StructA>	stackFT2;
	std::stack<StructA>	stackSTD;
	std::stack<StructA>	stackSTD2;

	StructA	tmp =	StructA("Banana", 27, (Vector2){12, 14});
	StructA	tmp2 =	StructA("Encore", 11, (Vector2){55, 55});
	StructA	tmp3 =	StructA("BbyShark", 71, (Vector2){69, 69});
	StructA	tmp4 =	StructA("BANKAI", 88, (Vector2){9999, 9999});

	for (int i = 0; i < 6; i++)
	{
		stackFT.push(myStruct[i]);
		stackSTD.push(myStruct[i]);
	}
	for (int i = 0; i < 9; i++)
	{
		stackFT2.push(myStruct2[i]);
		stackSTD2.push(myStruct2[i]);
	}
	printStackClass(stackFT, stackSTD, "Init stack", "struct", 1, 0);

	// Test 2: pop() //
	for (int i = 0; i < 2; i++)
	{
		stackFT.pop();
		stackSTD.pop();
	}
	printStackClass(stackFT, stackSTD, "2 * pop()", "struct", 2, 0);

	// Test 3: stack1 = stack2 //
	stackFT = stackFT2;
	stackSTD = stackSTD2;
	printStackClass(stackFT, stackSTD, "stack1 = stack2", "struct", 3, 1);

	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << GREEN << "------------ END TESTS Stack< struct > -------------" << RESET << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;


	std::string input;
	
	std::cout << "Press ENTER to continue" << std::endl;
	std::getline(std::cin, input);
	std::getline(std::cin, input);
	std::cout << "\e[1;1H\e[2J";
}

// Stack<Class> test
void    stackClassTest(void)
{
	std::cout << std::boolalpha;
	
	std::cout << std::endl;
	std::cout << RED << "/*******************************" << GREEN << " Stack<class> " 
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
	
	std::cout << RED << "----------------------------------------------------------------" 
		<< RESET << std::endl << std::endl;
	
	// Init stack //
	ft::stack<A>	stackFT;
	ft::stack<A>	stackFT2;
	std::stack<A>	stackSTD;
	std::stack<A>	stackSTD2;

	A	tmp = A("Banana", 27, (Vector2){12, 14});
	A	tmp2 = A("Encore", 11, (Vector2){55, 55});
	A	tmp3 = A("BbyShark", 71, (Vector2){69, 69});
	A	tmp4 = A("BANKAI", 88, (Vector2){9999, 9999});

	for (int i = 0; i < 6; i++)
	{
		stackFT.push(myStruct[i]);
		stackSTD.push(myStruct[i]);
	}
	for (int i = 0; i < 9; i++)
	{
		stackFT2.push(myStruct2[i]);
		stackSTD2.push(myStruct2[i]);
	}

	printStackClass(stackFT, stackSTD, "Init stack", "class", 1, 0);

	// Test 2: pop() //
	for (int i = 0; i < 2; i++)
	{
		stackFT.pop();
		stackSTD.pop();
	}
	printStackClass(stackFT, stackSTD, "2 * pop()", "class", 2, 0);

	// Test 3: stack1 = stack2 //
	stackFT = stackFT2;
	stackSTD = stackSTD2;
	printStackClass(stackFT, stackSTD, "stack1 = stack2", "class", 3, 1);

	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << GREEN << "------------ END TESTS Stack< class > -------------" << RESET << std::endl << std::endl;
	std::cout << RED << "----------------------------------------------------------------" << RESET << std::endl << std::endl;


	std::string input;
	
	std::cout << "Press ENTER to continue" << std::endl;
	std::getline(std::cin, input);
	std::getline(std::cin, input);
	std::cout << "\e[1;1H\e[2J";
}
