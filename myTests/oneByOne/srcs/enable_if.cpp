/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:34:30 by dracken24         #+#    #+#             */
/*   Updated: 2023/03/04 14:45:24 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.hpp"

template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
print(T value)
{
	std::cout << BLUE << "std: The value is an integer." << std::endl;
	std::cout << YELLOW << "\n<---------------------------------------------------------------------->" << std::endl;
}

template <typename T>
typename std::enable_if<std::is_pointer<T>::value, void>::type
print(T value)
{
	std::cout << BLUE << "std: The value is a pointer." << std::endl;
	std::cout << YELLOW << "\n<---------------------------------------------------------------------->" << std::endl;
}

template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
print(const std::vector<T>& vec)
{
	std::cout << BLUE << "std: The vector contains integers." << MAGENTA << std::endl;
	for (const auto& elem : vec)
	{
		std::cout << elem << " ";
	}
	std::cout << YELLOW << "\n\n<---------------------------------------------------------------------->" << std::endl;
	std::cout << RESET << std::endl;
}

template <typename T>
typename std::enable_if<!std::is_integral<T>::value, void>::type
print(const std::vector<T>& vec)
{
	std::cout << BLUE << "std: The vector does not contain integers." << MAGENTA << std::endl;
	for (const auto& elem : vec)
	{
		std::cout << elem << " ";
	}
	std::cout << YELLOW << "\n\n<---------------------------------------------------------------------->" << std::endl;
	std::cout << RESET << std::endl;
}


//------------------------------------------------------------------------//

template <typename T>
typename ft::enable_if<std::is_integral<T>::value, void>::type
printFt(T value)
{
	std::cout << GREEN << "ft: The value is an integer." << std::endl;
}

template <typename T>
typename ft::enable_if<std::is_pointer<T>::value, void>::type
printFt(T value)
{
	std::cout << GREEN << "ft: The value is a pointer." << std::endl;
}

template <typename T>
typename ft::enable_if<std::is_integral<T>::value, void>::type
printFt(const std::vector<T>& vec)
{
	std::cout << GREEN << "ft: The vector contains integers." << MAGENTA << std::endl;
	for (const auto& elem : vec)
	{
		std::cout << elem << " ";
	}
	std::cout << RESET << std::endl;
}

template <typename T>
typename ft::enable_if<!std::is_integral<T>::value, void>::type
printFt(const std::vector<T>& vec)
{
	std::cout << GREEN << "ft: The vector does not contain integers." << MAGENTA << std::endl;
	for (const auto& elem : vec)
	{
		std::cout << elem << " ";
	}
	std::cout << RESET << std::endl;
}

//------------------------------------------------------------------------//

void	enable_ifTests(void)
{
	std::cout << YELLOW << "enable_if tests" << std::endl;
	std::cout << RED << "<---------------------------------------------------------------------->\n" << std::endl;

	int		nbr[1] = {333};
	std::vector<int>	vecInt({22, 645, -46, 6});
	std::vector<float>	vecFloat({44.67, 87.09, 2.2});

	std::cout << YELLOW << "4424" << std::endl;
	printFt(4224);
	print(4224);

	std::cout << YELLOW << "\nUnicorn" << std::endl;
	printFt("Unicorn");
	print("Unicorn");

	std::cout << YELLOW << "\nC" << std::endl;
	printFt('C');
	print('C');

	std::cout << YELLOW << "\nnbr *" << std::endl;
	printFt(nbr);
	print(nbr);

	std::cout << YELLOW << "\n-42" << std::endl;
	printFt(-42);
	print(-42);

	std::cout << YELLOW << "\nvector<int>" << std::endl;
	printFt(vecInt);
	print(vecInt);

	std::cout << YELLOW << "vector<float>" << std::endl;	
	printFt(vecFloat);
	print(vecFloat);

	std::cout << std::endl;


	std::string input;
	std::cout << "\nPress ENTER to continue" << std::endl;
	std::getline(std::cin, input);
	std::getline(std::cin, input);
	std::cout << "\e[1;1H\e[2J";
}
