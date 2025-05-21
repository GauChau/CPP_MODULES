/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:06:14 by gchauvot          #+#    #+#             */
/*   Updated: 2025/05/21 17:46:31 by gchauvot         ###   ########.fr       */
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

	try{
		{
			std::cout<<"No numbers:";
			Span dpan(50);
			std::cout << "shortest: "<< dpan.shortestSpan()
				<< " longest: "<< dpan.longestSpan()<<std::endl;
		}
	}
	catch(const std::exception& e){std::cerr << e.what() << '\n';}

	try{

		{
			std::cout<<"One number:";
			Span dpan(50);
			dpan.addNumber(90);
			std::cout << "shortest: "<< dpan.shortestSpan()
				<< " longest: "<< dpan.longestSpan()<<std::endl;
		}
	}
	catch(const std::exception& e){std::cerr << e.what() << '\n';}

	try{
		{
			std::cout<<"\nseveral number:\n";
			Span dpan(50);
			dpan.addNumber(90);
			dpan.addNumber(190);
			dpan.addNumber(1090);
			dpan.addNumber(9);
			dpan.addNumber(2);
			std::cout << "shortest: "<< dpan.shortestSpan()
				<< " longest: "<< dpan.longestSpan()<<std::endl;
			std::cout<<"\n";
		}
	}
	catch(const std::exception& e){std::cerr << e.what() << '\n';}

	try{
		{
			std::cout<<"add range number:\n";
			Span dpan(50);
			dpan.addNumber(A.begin(), A.end());
			std::cout << "shortest: "<< dpan.shortestSpan()
				<< " longest: "<< dpan.longestSpan()<<std::endl;
		}
	}
	catch(const std::exception& e){std::cerr << e.what() << '\n';}


	return 0;
}