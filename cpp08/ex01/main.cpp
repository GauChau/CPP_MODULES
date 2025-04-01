/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautierchauvot <gautierchauvot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:06:14 by gchauvot          #+#    #+#             */
/*   Updated: 2025/04/01 14:13:09 by gautierchau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <cstddef>
#include "Span.hpp"
#include <vector>

// template <typename T>
int main()
{
    std::vector<int> A;

	A.push_back(6);
	A.push_back(3);
	A.push_back(17);
	A.push_back(9);
	A.push_back(11);

	try
	{
		{
			Span dpan(50);
			// dpan.addNumber(A.begin(), A.end());
			// dpan.addNumber(90);
			dpan.addNumber(190);
			dpan.addNumber(191);
			dpan.addNumber(90);
			std::cout << dpan.shortestSpan()<<std::endl;
			std::cout << dpan.longestSpan()<<std::endl;
		}

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	return 0;
}