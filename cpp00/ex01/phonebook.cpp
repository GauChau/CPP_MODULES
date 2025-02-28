/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:26:10 by gchauvot          #+#    #+#             */
/*   Updated: 2025/02/26 14:08:00 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <string>
#include <iostream>
#include "pbook.hpp"

void PhoneBook::init(void)
{
	this->i = 0;
	this->total = 0;
}

void PhoneBook::aligner(std::string src)
{
	std::string line;

	std::cout << "|";
	if (src.length() > 10)
	{
		std::cout << src.substr(0, 9) << ".";
	}
	else if(src.length() <= 10)
	{
		line.insert(0, 10 - src.length(), ' ');
		std::cout << line << src;
	}
}

void PhoneBook::display(int id)
{
	std::cout << "ID: " << std::to_string(id) << "\n"
	<< "firstname: " << this->array[id].get_fname() << "\n"
	<< "last name: " << this->array[id].get_lname() << "\n"
	<< "nickname: " << this->array[id].get_nickname() << "\n"
	<< "phone number: " << this->array[id].get_pnumber() << "\n"
	<< "darkest secret: " << this->array[id].get_secret() << "\n";
}

void PhoneBook::ADD(void)
{
	std::string temp;
	if(this->i > 7)
		this->i = 0;

	std::cout << "ADD CONTACT. EMPTY FIELD NOT ALLOWED\n";
	do
	{
		std::cout << "firstname: ";
		if(!std::getline(std::cin, temp))
			return ;
	}
	while (temp.length() == 0);
	this->array[this->i].w_fname(temp);

	do
	{
		std::cout << "lastname: ";
		if(!std::getline(std::cin, temp))
			return ;
	}
	while (temp.length() == 0);
	this->array[this->i].w_lname(temp);

	do
	{
		std::cout << "nickname: ";
		if(!std::getline(std::cin, temp))
			return ;
	}
	while (temp.length() == 0);
	this->array[this->i].w_nickname(temp);

	do
	{
		std::cout << "pnumber: ";
		if(!std::getline(std::cin, temp))
			return ;
	}
	while (temp.length() == 0);
	this->array[this->i].w_pnumber(temp);

	do
	{
		std::cout << "secret: ";
		if(!std::getline(std::cin, temp))
			return ;
	}
	while (temp.length() == 0);
	this->array[this->i].w_secret(temp);

	this->i++;
	this->total++;

}

void PhoneBook::SEARCH(void)
{
	int range;
	std::string id;

	if(this->total < 8)
		range = this->i;
	else
		range = 8;
	std::cout << "|ID|first name| last name|  nickname|   pnumber|\n";
	std::cout << "------------------------------------------------\n";
	// std::cout << "___________________________________________________________\n";
	for(int j = 0; j < range; j++)
	{
		std::cout << "| " << std::to_string(j);
		aligner(array[j].get_fname());
		aligner(array[j].get_lname());
		aligner(array[j].get_nickname());
		aligner(array[j].get_pnumber());
		std::cout << "|\n";
	}
	std::cout << "CHOOSE ID TO ACCESS TO: ";
	std::cin >> id;
	if (id.length() == 1
		&& (*id.cbegin() >= '0' && *id.cbegin() <= '7' && (*id.cbegin() -'0') <= range -1))
	{
		display(*id.cbegin() - '0');
	}
	else if (id.length() == 1
		&& (*id.cbegin() >= '0' && *id.cbegin() <= '7'))
	{
		std::cerr << "CONTACT NOT SET\n";
	}
	else
	{
		std::cerr << "WRONG ID, NUMBERS FROM 0 TO 7 ONLY.\n";
	}

}

int PhoneBook::RUNNER(std::string prompt)
{
	if (prompt.compare("SEARCH") == 0)
	{
		this->SEARCH();
		return (0);
	}
	else if (prompt.compare("ADD") == 0)
	{
		this->ADD();
		return (0);
	}
	else if (prompt.compare("EXIT") == 0)
	{
		return (-1);
	}
	else
	{
		std::cerr << "Wrong entry. Valid commands are: ADD, SEARCH and EXIT.\n";
		return (1);
	}
	return (1);
}

int	main()
{
	PhoneBook joe;
	std::string line;

	joe.init();
	std::cout << "My Awesome Phonebook\n";
	std::cout << "Type ADD, SEARCH or EXIT\n";
	while (1)
	{
		std::getline(std::cin, line);
		if(!std::cin)
			return(0);
		if (line.length() > 0)
		{
			if(joe.RUNNER(line) == -1)
				break ;
		}
	}
	return 0;
}