/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeOut.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:28:13 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/11 18:27:49 by dracken24        ###   ########.fr       */
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
	for (int i = 0; i < 5000000; i++)
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
	for (int i = 0; i < 5000000; i++)
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
	for (int i = 0; i < 10000000; i++)
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
	for (int i = 0; i < 10000000; i++)
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

void    chooseStackTestsClass(void)
{
	std::cout << std::boolalpha;
	
	std::cout << std::endl;
	std::cout << RED << "/*******************************" << GREEN << " Stack<class> " \
		<< RED << "*******************************/" << RESET << std::endl;
	std::cout << std::endl;
	
	// Init Stack //
	
	A	myStruct[] = {A("Hello", 1, (Vector2){2, 4}), A("World", 2, (Vector2){3, 5}),
			A("This", 3, (Vector2){4, 6}), A("Is", 4, (Vector2){5, 7}),
			A("A", 5, (Vector2){6, 8}), A("Test", 6, (Vector2){7, 9})};

	// Init stack //
	ft::stack<A>	stackFT;
	std::stack<A>	stackSTD;

	A	tmp = A("Banana", 27, (Vector2){12, 14});
	A	tmp2 = A("Encore", 11, (Vector2){55, 55});
	A	tmp3 = A("BbyShark", 71, (Vector2){69, 69});
	A	tmp4 = A("BANKAI", 88, (Vector2){9999, 9999});

	for (int i = 0; i < 6; i++)
	{
		stackFT.push(myStruct[i]);
		stackSTD.push(myStruct[i]);
	}
	
	struct timeval	time;

	gettimeofday(&time, NULL);
	
	long int start = time.tv_sec * 1000 + time.tv_usec / 1000;

	// ft tests //
	for (int i = 0; i < 20000000; i++)
	{
		stackFT.push(tmp);
		stackFT.push(tmp2);
		stackFT.push(tmp3);
		stackFT.push(tmp4);
		stackFT.top();
		stackFT.top();
		stackFT.pop();
	}

	stackFT.empty();

	gettimeofday(&time, NULL);

	long int end = time.tv_sec * 1000 + time.tv_usec / 1000;

	std::cout << GREEN << "Time for ft::stack<class>: " << end - start << " ms" << std::endl;

	start = end;

	// std tests //
	for (int i = 0; i < 20000000; i++)
	{
		stackSTD.push(tmp);
		stackSTD.push(tmp2);
		stackSTD.push(tmp3);
		stackSTD.push(tmp4);
		stackSTD.top();
		stackSTD.top();
		stackSTD.pop();
	}
	
	gettimeofday(&time, NULL);

	end = time.tv_sec * 1000 + time.tv_usec / 1000;

	std::cout << BLUE << "Time for std::stack<class>: " << end - start << " ms" << std::endl;
}

void    chooseStackTestsInt(void)
{
	std::cout << std::boolalpha;
	
	std::cout << std::endl;
	std::cout << RED << "/*******************************" << GREEN << " Stack<int> " \
		<< RED << "*******************************/" << RESET << std::endl;
	std::cout << std::endl;
	
	// Init vector //
	ft::stack<int> stackFT;
	std::stack<int> stackSTD;
	
	struct timeval	time;

	gettimeofday(&time, NULL);
	
	long int start = time.tv_sec * 1000 + time.tv_usec / 1000;

	// ft tests //
	for (int i = 0; i < 20000000; i++)
	{
		stackFT.push(42);
		stackFT.push(4224);
		stackFT.push(101);
		stackFT.pop();
		stackFT.top();
		stackFT.size();
		stackFT.push(482);
		stackFT.push(4904);
		stackFT.push(1661);
		stackFT.empty();
	}

	stackFT.empty();

	gettimeofday(&time, NULL);

	long int end = time.tv_sec * 1000 + time.tv_usec / 1000;

	std::cout << GREEN << "Time for ft::stack<int>: " << end - start << " ms" << std::endl;

	start = end;

	// std tests //
	for (int i = 0; i < 20000000; i++)
	{
		stackSTD.push(42);
		stackSTD.push(4224);
		stackSTD.push(101);
		stackSTD.pop();
		stackSTD.top();
		stackSTD.size();
		stackFT.push(482);
		stackFT.push(4904);
		stackFT.push(1661);
		stackSTD.empty();
	}
	
	gettimeofday(&time, NULL);

	end = time.tv_sec * 1000 + time.tv_usec / 1000;

	std::cout << BLUE << "Time for std::stack<int>: " << end - start << " ms" << std::endl;

	chooseStackTestsClass();

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

void	chooseMapTestsClass(void)
{
	std::cout << std::boolalpha;
	
	std::cout << std::endl;
	std::cout << RED << "/*******************************" << GREEN << " Map<class> " \
		<< RED << "*******************************/" << RESET << std::endl;
	std::cout << std::endl;

	// Init Map //
	StructA	map[] = 
	{
		StructA("Monkey", 24, (Vector2){24, 48}),
		StructA("Unicorn", 42, (Vector2){42, 84}),
		StructA("Pony", 96, (Vector2){96, 192}),
		StructA("Zombie", 666, (Vector2){666, 1332}),
		StructA("Squirrel", 77, (Vector2){777, 154}),
	};

	StructA	map2[] = 
	{
		StructA("Bubble", 45, (Vector2){264, 483}),
		StructA("Tracteur", 6, (Vector2){452, 884}),
		StructA("Avion", 567, (Vector2){986, 1942}),
		StructA("Jedi", 85, (Vector2){6566, 13392}),
		StructA("AAAAAAAAA", 476, (Vector2){7577, 654}),
	};

	StructA	bad("Bad", 777, (Vector2){777, 777});


	ft::map<StructA, StructA>	ftMap;
	std::map<StructA, StructA>	stdMap;
	
	struct timeval	time;

	gettimeofday(&time, NULL);
	
	long int start = time.tv_sec * 1000 + time.tv_usec / 1000;
	
	// ft tests //
	for (int i = 0; i < 10000000; i++)
	{
		ftMap.insert(ft::pair<StructA, StructA>(map[0], map2[0]));
		ftMap.insert(ft::pair<StructA, StructA>(map[1], map2[1]));
		ftMap.insert(ft::pair<StructA, StructA>(map[2], map2[2]));
		ftMap.insert(ft::pair<StructA, StructA>(map[3], map2[3]));
		ftMap.insert(ft::pair<StructA, StructA>(map[4], map2[4]));
		ftMap.equal_range(map[0]);
		ftMap.count(map[0]);
		ftMap.find(map[0]);
		ftMap.erase(map[0]);
		ftMap.lower_bound(map[0]);
		ftMap.upper_bound(map[0]);
		ftMap.begin();
		ftMap.end();
		ftMap.rbegin();
		ftMap.rend();
		ftMap.empty();
	}

	ftMap.clear();

	
	struct timeval	time2;

	gettimeofday(&time2, NULL);
	long int end = time2.tv_sec * 1000 + time2.tv_usec / 1000;

	std::cout << GREEN << "Time for ft::map<class>: " << end - start << " ms" << std::endl;
	
	start = end;
	
	// std tests //
	for (int i = 0; i < 10000000; i++)
	{
		stdMap.insert(std::pair<StructA, StructA>(map[0], map2[0]));
		stdMap.insert(std::pair<StructA, StructA>(map[1], map2[1]));
		stdMap.insert(std::pair<StructA, StructA>(map[2], map2[2]));
		stdMap.insert(std::pair<StructA, StructA>(map[3], map2[3]));
		stdMap.insert(std::pair<StructA, StructA>(map[4], map2[4]));
		stdMap.equal_range(map[0]);
		stdMap.count(map[0]);
		stdMap.find(map[0]);
		stdMap.erase(map[0]);
		stdMap.lower_bound(map[0]);
		stdMap.upper_bound(map[0]);
		stdMap.begin();
		stdMap.end();
		stdMap.rbegin();
		stdMap.rend();
		stdMap.empty();
	}

	stdMap.clear();

	gettimeofday(&time, NULL);

	end = time.tv_sec * 1000 + time.tv_usec / 1000;

	std::cout << BLUE << "Time for std::map<class>: " << end - start << " ms" << std::endl;
}

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
	for (int i = 0; i < 3000000; i++)
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
	}

	ftMap.clear();

	
	struct timeval	time2;

	gettimeofday(&time2, NULL);
	long int end = time2.tv_sec * 1000 + time2.tv_usec / 1000;

	std::cout << GREEN << "Time for ft::map<int>: " << end - start << " ms" << std::endl;
	
	start = end;
	
	// std tests //
	for (int i = 0; i < 3000000; i++)
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
	}

	stdMap.clear();

	gettimeofday(&time, NULL);

	end = time.tv_sec * 1000 + time.tv_usec / 1000;

	std::cout << BLUE << "Time for std::map<int>: " << end - start << " ms" << std::endl;

	chooseMapTestsClass();

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
