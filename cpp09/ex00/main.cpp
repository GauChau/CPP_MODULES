/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautierchauvot <gautierchauvot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 02:05:23 by gautierchau       #+#    #+#             */
/*   Updated: 2025/04/14 18:31:20 by gautierchau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <ctime>
#include <sstream>
#include <iomanip>
#include <iostream>


int main(int argc, char **argv)
{

	if (argc != 2)
		return 0;

	
	BitcoinExchange tester("data.csv");
	std::ifstream sinput;
	std::string data;
	sinput.open(argv[1]);
	if (!sinput.is_open())
	{
		std::cerr << "Error: could not open file " << argv[1] << std::endl;
		return 1;
	}

	while (std::getline(sinput,data))
	{
		try
		{
			tester.Convert(data);
		}
		catch(std::exception& e)
		{
			if(dynamic_cast<BitcoinExchange::InvalidInput*>(&e))
				std::cerr << e.what()<< " : "<< data << '\n';
			else if(dynamic_cast<BitcoinExchange::InvalidDate*>(&e))
				std::cerr << e.what()<< " : "<< data.substr(0,10) << '\n';
			else if(dynamic_cast<BitcoinExchange::InvalidValue*>(&e))
				std::cerr << e.what()<< " : "<< data .substr(13)<< '\n';
			else
				std::cerr << e.what()<< '\n';
		}
		
	}

	std::cerr << "We all have GREAT REGRETS.\n";
	return 1;
}