/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:19:35 by dracken24         #+#    #+#             */
/*   Updated: 2023/01/10 22:13:05 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/templates/VectorIterator.hpp"
#include "../includes/templates/Vector.hpp"

int main(void)
{
	int *arr = new int[5];
	arr[0] = 49;
	arr[1] = -8;
	arr[2] = 74;
	arr[3] = 336;
	arr[4] = 5;
	ft::Vector<int> vector(arr, arr + 5);
	// ft::Vector<int>(5, 42);

	return 0;
}
