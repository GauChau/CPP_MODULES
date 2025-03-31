/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:06:14 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/31 17:23:50 by gchauvot         ###   ########.fr       */
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

	A.push_back(14);
	A.push_back(1);
	A.push_back(24);
	A.push_back(214);
	A.push_back(134);

	try
	{
		{
			Span dpan(5);
			dpan.addNumber(A.begin(), A.end());
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