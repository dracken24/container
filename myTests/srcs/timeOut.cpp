/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeOut.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:28:13 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/10 18:28:22 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/container.hpp"

#include <vector>

void vectorTimeOutTestClass(void)
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
	
	// Init vector //
	// Init vector //
	ft::vector<A>		vector_FT(myStruct, myStruct + 5);
	ft::vector<A>		vector_FT2(myStruct2, myStruct2 + 9);
	std::vector<A>		vector_STD(myStruct, myStruct + 5);
	std::vector<A>		vector_STD2(myStruct2, myStruct2 + 9);

	A	tmp = A("Banana", 27, (Vector2){12, 14});
	A	tmp2 = A("Encore", 11, (Vector2){55, 55});
	A	tmp3 = A("BbyShark", 71, (Vector2){69, 69});
	A	tmp4 = A("BANKAI", 88, (Vector2){9999, 9999});
	
	struct timeval	time;

	gettimeofday(&time, NULL);
	
	long int start = time.tv_sec * 1000 + time.tv_usec / 1000;
	
	// ft tests //
	for (int i = 0; i < 100000; i++)
	{
		vector_FT.resize(14);
		vector_FT.push_back(tmp);
		vector_FT.push_back(tmp2);
		vector_FT.pop_back();
		vector_FT.insert(vector_FT.begin() + 4, tmp3);
		vector_FT.reserve(33);
		vector_FT.erase(vector_FT.begin() + 3);
		vector_FT.erase(vector_FT.begin() + 3, vector_FT.begin() + 5);
		vector_FT.assign(5, tmp4);
		vector_FT.resize(3);
		vector_FT.swap(vector_FT2);
		vector_FT.clear();
	}

	vector_FT.clear();

	
	struct timeval	time2;

	gettimeofday(&time2, NULL);
	long int end = time2.tv_sec * 1000 + time2.tv_usec / 1000;

	std::cout << GREEN << "Time for ft::vector<class>: " << end - start << " ms" << std::endl;
	
	start = end;
	
	// std tests //
	for (int i = 0; i < 100000; i++)
	{
		vector_STD.resize(14);
		vector_STD.push_back(tmp);
		vector_STD.push_back(tmp2);
		vector_STD.pop_back();
		vector_STD.insert(vector_STD.begin() + 4, tmp3);
		vector_STD.reserve(33);
		vector_STD.erase(vector_STD.begin() + 3);
		vector_STD.erase(vector_STD.begin() + 3, vector_STD.begin() + 5);
		vector_STD.assign(5, tmp4);
		vector_STD.resize(3);
		vector_STD.swap(vector_STD2);
		vector_STD.clear();
	}

	vector_STD.clear();

	gettimeofday(&time, NULL);

	end = time.tv_sec * 1000 + time.tv_usec / 1000;

	std::cout << BLUE << "Time for std::vector<class>: " << end - start << " ms" << std::endl;
}

void vectorTimeOutTestInt(void)
{
	std::cout << std::boolalpha;
	
	std::cout << std::endl;
	std::cout << RED << "/*******************************" << GREEN << " Vector<int> " \
		<< RED << "*******************************/" << RESET << std::endl;
	std::cout << std::endl;

	int		myints[] = {75, 223, 65, 42, 113};
	int		myints2[] = {2, 4, 6, 8, 10};
	
	// Init vector //
	ft::vector<int>		vector_FT(myints, myints + 5);
	ft::vector<int>		vector_FT2(myints2, myints2 + 5);
	std::vector<int>	vector_STD(myints, myints + 5);
	std::vector<int>	vector_STD2(myints2, myints2 + 5);
	
	struct timeval	time;

	gettimeofday(&time, NULL);
	
	long int start = time.tv_sec * 1000 + time.tv_usec / 1000;
	
	// ft tests //
	for (int i = 0; i < 100000; i++)
	{
		vector_FT.push_back(42);
		vector_FT.resize(14);
		vector_FT.push_back(4224);
		vector_FT.push_back(101);
		vector_FT.pop_back();
		vector_FT.insert(vector_FT.begin() + 9, 99);
		vector_FT.reserve(33);
		vector_FT.erase(vector_FT.begin() + 3);
		vector_FT.erase(vector_FT.begin() + 3, vector_FT.begin() + 5);
		vector_FT.assign(5, 42);
		vector_FT.resize(3);
		vector_FT.swap(vector_FT2);
	}

	vector_FT.clear();

	
	struct timeval	time2;

	gettimeofday(&time2, NULL);
	long int end = time2.tv_sec * 1000 + time2.tv_usec / 1000;

	std::cout << GREEN << "Time for ft::vector<int>: " << end - start << " ms" << std::endl;
	
	start = end;
	
	// std tests //
	for (int i = 0; i < 100000; i++)
	{
		vector_STD.push_back(42);
		vector_STD.resize(14);
		vector_STD.push_back(4224);
		vector_STD.push_back(101);
		vector_STD.pop_back();
		vector_STD.insert(vector_STD.begin() + 9, 99);
		vector_STD.reserve(33);
		vector_STD.erase(vector_STD.begin() + 3);
		vector_STD.erase(vector_STD.begin() + 3, vector_STD.begin() + 5);
		vector_STD.assign(5, 42);
		vector_STD.resize(3);
		vector_STD.swap(vector_STD2);
	}

	vector_STD.clear();

	gettimeofday(&time, NULL);

	end = time.tv_sec * 1000 + time.tv_usec / 1000;

	std::cout << BLUE << "Time for std::vector<int>: " << end - start << " ms" << std::endl;

	vectorTimeOutTestClass();

	std::cout << std::endl;
	std::cout << RED << "--------------------------------------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << GREEN << "----------------------- END TESTS Vector timeout -------------------------" << RESET << std::endl << std::endl;
	std::cout << RED << "--------------------------------------------------------------------------" << RESET << std::endl << std::endl;
	
	
	std::string input;
	
	std::cout << "Press ENTER to continue" << std::endl;
	std::getline(std::cin, input);
	std::getline(std::cin, input);
	std::cout << "\e[1;1H\e[2J";
}

/***************************************************************************************************/

void    chooseStackTestsInt(void)
{
	std::cout << std::boolalpha;
	
	std::cout << std::endl;
	std::cout << RED << "/*******************************" << GREEN << " Stack<int> " \
		<< RED << "*******************************/" << RESET << std::endl;
	std::cout << std::endl;
	
	// Init vector //
	ft::stack<int> stackFT;
	ft::stack<int> stackFT2;
	std::stack<int> stackSTD;
	std::stack<int> stackSTD2;
	
	struct timeval	time;

	gettimeofday(&time, NULL);
	
	long int start = time.tv_sec * 1000 + time.tv_usec / 1000;
	
	// ft tests //
	for (int i = 0; i < 5000; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			stackFT.push(k * 2);
			stackFT2.push(k * 4);
		}
		for (int j = 0; j < 2; j++)
			stackFT.pop();
		stackFT = stackFT2;
	}

	
	struct timeval	time2;

	gettimeofday(&time2, NULL);
	long int end = time2.tv_sec * 1000 + time2.tv_usec / 1000;

	std::cout << GREEN << "Time for ft::stack<int>: " << end - start << " ms" << std::endl;
	
	start = end;
	
	// std tests //
	for (int i = 0; i < 5000; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			stackSTD.push(k * 2);
			stackSTD2.push(k * 4);
		}
		for (int j = 0; j < 2; j++)
			stackSTD.pop();
		stackSTD = stackSTD2;
	}

	gettimeofday(&time, NULL);

	end = time.tv_sec * 1000 + time.tv_usec / 1000;

	std::cout << BLUE << "Time for std::stack<int>: " << end - start << " ms" << std::endl;

	// vectorTimeOutTestClass();

	std::cout << std::endl;
	std::cout << RED << "--------------------------------------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << GREEN << "------------------------ END TESTS Stack timeout -------------------------" << RESET << std::endl << std::endl;
	std::cout << RED << "--------------------------------------------------------------------------" << RESET << std::endl << std::endl;
	
	
	std::string input;
	
	std::cout << "Press ENTER to continue" << std::endl;
	std::getline(std::cin, input);
	std::getline(std::cin, input);
	std::cout << "\e[1;1H\e[2J";
}

/***************************************************************************************************/

void	chooseMapTestsInt(void)
{
	std::cout << std::boolalpha;
	
	std::cout << std::endl;
	std::cout << RED << "/*******************************" << GREEN << " Map<int> " \
		<< RED << "*******************************/" << RESET << std::endl;
	std::cout << std::endl;

	int		myints[] = {75, 223, 65, 42, 113};
	int		myints2[] = {2, 4, 6, 8, 10};
	
	// Init vector //
	ft::map<int, int>	ftMap;
	ft::map<int, int>	ftMap2;
	std::map<int, int>	stdMap;
	std::map<int, int>	stdMap2;

	for (int i = 0; i < 7; i++)
	{
		int nbr = rand() % 1000;
		int nbr2 = rand() % 1000;
		
		ftMap.insert(ft::make_pair(nbr, nbr2));
		stdMap.insert(std::make_pair(nbr, nbr2));

		nbr = rand() % 500;
		nbr2 = rand() % 500;

		ftMap2.insert(ft::make_pair(nbr, i * nbr2));
		stdMap2.insert(std::make_pair(nbr, i * nbr2));
	}
	
	struct timeval	time;

	gettimeofday(&time, NULL);
	
	long int start = time.tv_sec * 1000 + time.tv_usec / 1000;
	
	// ft tests //
	for (int i = 0; i < 10000; i++)
	{
		ftMap.insert(ft::pair<int, int>(i, 1 * 2));
		ftMap.insert(ft::pair<int, int>(i * 3, 1 * 6));
		ftMap.insert(ft::pair<int, int>(i * 6, 1 * 5));
		ftMap.erase(ftMap.begin());
		ftMap.find(5);
		ftMap.find(277);
		ftMap.count(5);
		ftMap.count(277);
		ftMap.lower_bound(277);
		ftMap.upper_bound(277);
		ftMap.swap(ftMap2);
		// std::cout << "I: " << i << std::endl;
	}

	ftMap.clear();

	
	struct timeval	time2;

	gettimeofday(&time2, NULL);
	long int end = time2.tv_sec * 1000 + time2.tv_usec / 1000;

	std::cout << GREEN << "Time for ft::map<int>: " << end - start << " ms" << std::endl;
	
	start = end;
	
	// std tests //
	for (int i = 0; i < 10000; i++)
	{
		stdMap.insert(std::pair<int, int>(i, 1 * 2));
		stdMap.insert(std::pair<int, int>(i * 3, 1 * 6));
		stdMap.insert(std::pair<int, int>(i * 6, 1 * 5));
		stdMap.erase(stdMap.begin());
		stdMap.find(5);
		stdMap.find(277);
		stdMap.count(5);
		stdMap.count(277);
		stdMap.lower_bound(277);
		stdMap.upper_bound(277);
		stdMap.swap(stdMap2);
		// std::cout << "I: " << i << std::endl;
	}

	stdMap.clear();

	gettimeofday(&time, NULL);

	end = time.tv_sec * 1000 + time.tv_usec / 1000;

	std::cout << BLUE << "Time for std::map<int>: " << end - start << " ms" << std::endl;

	// vectorTimeOutTestClass();

	std::cout << std::endl;
	std::cout << RED << "--------------------------------------------------------------------------" << RESET << std::endl << std::endl;
	std::cout << GREEN << "----------------------- END TESTS Map timeout -------------------------" << RESET << std::endl << std::endl;
	std::cout << RED << "--------------------------------------------------------------------------" << RESET << std::endl << std::endl;
	
	
	std::string input;
	
	std::cout << "Press ENTER to continue" << std::endl;
	std::getline(std::cin, input);
	std::getline(std::cin, input);
	std::cout << "\e[1;1H\e[2J";
}
