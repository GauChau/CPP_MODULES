/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautierchauvot <gautierchauvot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:06:14 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/27 20:49:26 by gautierchau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <cstddef>
#include "easyfind.hpp"
#include <vector>

// template <typename T>
int main() 
{
    std::vector<int> A;

	A.push_back(14);
	A.push_back(1);
	A.push_back(24);
	A.push_back(214);
	A.push_back(134);

	std::vector<int>::iterator target = easyfind(A, 4);
	if(target == A.end())
	{
		std::cout << "target not found" << std::endl;

	}
	else
	{
		std::cout << *easyfind(A, 4) << std::endl;

	}
	
       return 0;
}