/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 02:05:23 by gautierchau       #+#    #+#             */
/*   Updated: 2025/04/09 15:58:33 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <ctime>
#include <sstream>
#include <iomanip>
#include <iostream>

int		DateChecker(std::string date)
{
	t_date dday;
	size_t dash =0;

	dash = date.find("-");
	if(dash != std::string::npos)
	{
		dday.year = date.substr(0,dash);
		date = date.substr(dash+1);
		dash = date.find("-");
		if(dash != std::string::npos)
		{
			dday.month = date.substr(0, dash);
			dday.day = date.substr(dash+1);
			dash = dday.day.find(" ");
			if(dash != std::string::npos)
			{
				std::string::reverse_iterator riter = dday.day.rbegin();
				while (riter != dday.day.rend() && *riter == ' ')
				{
					*riter = '\0';
					++riter;
				}
			}
		}
	}

	// std::cout << "dday.year: "<< dday.year << " dday.month: "<< dday.month << " dday.day: "<< dday.day<< "emd: " << std::endl;

	return 0;
}

void	_displayTimestamp( void )
{
	std::time_t time = std::time(0);
	std::tm now = *std::localtime(&time);
	// std::cout
	// 	<< "["
	// 	<< (now.tm_year + 1900)
	// 	<< std::setfill('-')
	// 	<< std::setw(2) << now.tm_mon + 1
	// 	<< std::setw(2) << now.tm_mday //<< "_"
	// 	// << std::setw(2) << now.tm_hour
	// 	// << std::setw(2) << now.tm_min
	// 	// << std::setw(2) << now.tm_sec
	// 	<< "] ";
}


int main()
{
	BitcoinExchange tester("data.csv");
	DateChecker("2010--120-333          2  ");

	_displayTimestamp();

	return 1;
	// std::cout <<
}