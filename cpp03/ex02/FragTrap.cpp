/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:28:10 by gchauvot          #+#    #+#             */
/*   Updated: 2025/02/19 10:59:21 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap() : ClapTrap("FR4GTR4P", 100, 100, 30)
{
	std::cout << "\e[0;33mDefault Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(std::string Name) : ClapTrap(Name, 100, 100, 30)
{
	std::cout << "\e[0;33mName ScavTrap Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	this->_Name = copy.get_Name();
	this->_Hp = copy.get_Hp();
	this->_Ep = copy.get_Ep();
	this->_Ad = copy.get_Ad();
	std::cout << "\e[0;33mCopy Constructor called of FragTrap\e[0m" << std::endl;
}


// Destructor
FragTrap::~FragTrap()
{
	std::cout << "\e[0;31mDestructor called of FragTrap\e[0m" << std::endl;
}


// Operators
FragTrap & FragTrap::operator=(const FragTrap &assign)
{
	this->_Hp = assign.get_Hp();
	this->_Ep = assign.get_Ep();
	this->_Ad = assign.get_Ad();
	this->_Name = assign.get_Name();
	return *this;
}


void FragTrap::highFivesGuys(void)
{
	std::cout << "HIGH FIVE ?" << std::endl;
}

