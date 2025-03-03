/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:45:40 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/03 15:58:47 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
		<< std::endl;
}

void Harl::info(void)
{
	std::cout <<"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
		<< std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
		<< std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now."
		<< std::endl;

}

void Harl::complain(std::string level)
{

	std::string tab[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*ptr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	Harl func_p;

	for(int i = 0; i < 4; i++)
	{
		if(level == tab[i])
		{
			(func_p.*ptr[i])();
		}
	}

}

// void Harl::complain(std::string level)
// {

// 	std::string tab[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
// 	void (Harl::*ptr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
// 	Harl func_p;
// 	enum values{DEBUG, INFO, WARNING, ERROR} ;
// 	values a=DEBUG;

// 	// for(int i = 0; i < 4; i++)
// 	// {
// 	// 	if(level == tab[i])
// 	// 	{
// 	// 		a = tab[i];
// 	// 	}
// 	// }
// 	if(level == "DEBUG")
// 		a=DEBUG;
// 	if(level == "INFO")
// 		a=INFO;
// 	if(level == "WARNING")
// 		a=WARNING;
// 	if(level == "ERROR")
// 		a=ERROR;
// 	switch (a)
// 	{
// 		case DEBUG:
// 			(func_p.*ptr[a])();
// 		case INFO:
// 			(func_p.*ptr[a])();
// 		case WARNING:
// 			(func_p.*ptr[a])();
// 		case ERROR:
// 			(func_p.*ptr[a])();

// 	}

// }