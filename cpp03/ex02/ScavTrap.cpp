/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:39:53 by gchauvot          #+#    #+#             */
/*   Updated: 2025/02/19 10:57:17 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap()
{
	std::cout << "\e[0;33mDefault ScavTrap Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy):ClapTrap(copy)
{
	this->_ggate = copy._ggate;
	std::cout << "\e[0;33mCopy ScavTrap Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name, 100, 50, 20)
{
	this->_ggate = false;
	std::cout << "\e[0;33mName ScavTrap Constructor called of ScavTrap\e[0m" << std::endl;
}


// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "\e[0;31mScavTrap Destructor called of ScavTrap\e[0m" << std::endl;
}


// Operators
ScavTrap & ScavTrap::operator=(const ScavTrap &assign)
{
	this->_Hp = assign.get_Hp();
	this->_Ep = assign.get_Ep();
	this->_Ad = assign.get_Ad();
	this->_Name = assign.get_Name();
	this->_ggate = assign._ggate;
	return *this;
}


void ScavTrap::guardGate()
{
	this->_ggate = true;
	std::cout << "\e[0;34mScavTrap \e[0;33m" << this->get_Name() << "\e[0;34m is now in Gate Keeper Mode.\e[0m"  << std::endl;

}

void ScavTrap::attack(const std::string& target)
{
	if (this->_Ep > 0 && this->_Hp > 0)
	{
		this->_Ep--;
		std::cout << "Scavtrap \e[0;33m"
			<< this->_Name
			<< "\e[0m attacks \e[0;31m"
			<< target
			<< "\e[0m, causing \e[0;31m"
			<< this->get_Ad()
			<<	"\e[0m points of damage!"
			<< std::endl;
	}
	else if(this->_Hp > 0)
	{
		std::cout << this->_Name
			<< " lacks energy to perform an attack!"
			<< std::endl;
	}
	else if(this->_Hp <= 0)
	{
		std::cout << "\e[0;33m" << this->_Name << "\e[0m"
			<< " is unalive."
			<< std::endl;
	}
}


