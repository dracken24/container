/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:19:35 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/11 10:21:10 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/templates/VectorIterator.hpp"
#include "../includes/templates/Vector.hpp"

int main(void)
{
	int arr[5];
	arr[0] = 49;
	arr[1] = -8;
	arr[2] = 74;
	arr[3] = 336;
	arr[4] = 5;
	ft::Vector<int> v1(arr, arr + 5);
	// ft::Vector<int>(5, 42);

	return 0;
}
