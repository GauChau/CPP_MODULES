/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:06:14 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/31 15:12:10 by gchauvot         ###   ########.fr       */
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

	try
	{
		{
			std::vector<int>::iterator target;
			target = easyfind(A, 14);
			target = easyfind(A, 1);
			target = easyfind(A, 45);
			target = easyfind(A, 214);
		}

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	return 0;
}