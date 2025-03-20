/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:06:14 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/20 14:06:55 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
# include <iostream>
# include <string>
#include <fstream>
#include <filesystem>
#include <cstdlib>


void increment(int& n) {
    n += 10;  // Modifies the original element in the array
}

int main( void )
{
	int arr[] = {1, 2, 3, 4, 5};

	iter(arr, 5, increment);
	std::cout << "After iter:  ";
	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << " ";  // Output: 11 12 13 14 15
	}
	std::cout << std::endl;
return 0;
}