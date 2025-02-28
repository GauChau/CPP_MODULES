/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:39:53 by gchauvot          #+#    #+#             */
/*   Updated: 2025/02/19 11:02:11 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap()
{
	this->_Hp = 10;
	this->_Ep = 10;
	this->_Ad = 0;
	this->_Name = "CL4P";
	std::cout << "P0"<<std::endl;
	std::cout << "\e[0;33mDefault Constructor called of ClapTrap\e[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	this->_Name = copy.get_Name();
	this->_Hp = copy.get_Hp();
	this->_Ep = copy.get_Ep();
	this->_Ad = copy.get_Ad();

	std::cout << "\e[0;33mCopy Constructor called of ClapTrap\e[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string Name)
{
	this->_Hp = 10;
	this->_Ep = 10;
	this->_Ad = 0;
	this->_Name = Name;
	std::cout << "\e[0;33mName Constructor called of ClapTrap\e[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string const Name, unsigned int _Hp, unsigned int _Ep, unsigned int _Ad)
{
	this->_Hp = _Hp;
	this->_Ep = _Ep;
	this->_Ad = _Ad;
	this->_Name = Name;
	std::cout << "\e[0;33mFull Constructor called of ClapTrap\e[0m" << std::endl;
}
// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "\e[0;31mDestructor called of ClapTrap\e[0m" << std::endl;
}


// Operators
ClapTrap & ClapTrap::operator=(const ClapTrap &assign)
{
	this->_Ad = assign.get_Ad();
	this->_Ep = assign.get_Ep();
	this->_Hp = assign.get_Hp();
	this->_Name = assign.get_Name();
	return *this;
}

std::string ClapTrap::get_Name(void) const
{
	return (this->_Name);
}

unsigned int ClapTrap::get_Ad(void)const
{
	return (this->_Ad);
}
unsigned int ClapTrap::get_Hp(void)const
{
	return (this->_Hp);
}
unsigned int ClapTrap::get_Ep(void)const
{
	return (this->_Ep);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_Ep > 0 && this->_Hp > 0)
	{
		this->_Ep--;
		std::cout << "\e[0;33m"
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
}


void ClapTrap::takeDamage(unsigned int amount)
{
	if(this->_Hp <= 0)
	{
		std::cout << this->_Name
			<< " is already dead."
			<< std::endl;
		return ;
	}
	std::cout << this->_Name
		<< " got hit for \e[0;31m"
		<< amount
		<<	"\e[0m points of damage!"
		<< std::endl;
	if(this->_Hp <= amount)
	{
		std::cout << this->_Name
			<< " has died."
			<< std::endl;
	}
	this->_Hp -= amount;

}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(this->_Hp <= 0)
	{
		std::cout << this->_Name
			<< " is already dead."
			<< std::endl;
		return ;
	}
	else if (this->_Ep > 0)
	{
		this->_Ep--;
		std::cout << this->_Name
		<< " healed for \e[0;32m"
		<< amount
		<<	"\e[0m HP!"
		<< std::endl;
	}
	else
	{
		std::cout << this->_Name
			<< " has not enough energy to Repair."
			<< std::endl;
	}
}

