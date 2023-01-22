/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapTest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:47:12 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/21 23:57:01 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/container.hpp"

template <class T>
void	printMap(ft::map<T, int> &map, std::map<T, int> &stdMap)
{
	std::cout << "std::map: " << std::endl;
	for (typename std::map<T, T>::iterator it = stdMap.begin(); it != stdMap.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;
	std::cout << "ft::map: " << std::endl;
	for (typename ft::map<T, T>::iterator it = map.begin(); it != map.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;
}

void	mapTestInt()
{
	std::string		buffer;
	
	ft::map<int, int>	ftMap;
	// ft::map<int, int>	ftMap2;
	std::map<int, int>	stdMap;
	// std::map<int, int>	stdMap2;
	
	for (int i = 0; i < 7; i++)
	{
		// std::cin >> buffer;
		std::cout << "Inserting " << i * 2 << " " << i << std::endl;
		ftMap.insert(ft::make_pair(i * 2, i));
		stdMap.insert(std::make_pair(i * 2, i));
	}
	// printMap<int>(ftMap, stdMap);
}
