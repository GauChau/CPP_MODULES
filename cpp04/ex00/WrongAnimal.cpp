/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:50:02 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/24 11:35:32 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructors
WrongAnimal::WrongAnimal()
{
	std::cout << "\e[0;33mDefault Constructor called of WrongAnimal\e[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	this->type = copy.type;
	std::cout << "\e[0;33mCopy Constructor called of WrongAnimal\e[0m" << std::endl;
}


// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "\e[0;31mDestructor called of WrongAnimal\e[0m" << std::endl;
}


// Operators
WrongAnimal & WrongAnimal::operator=(const WrongAnimal &assign)
{
	this->type = assign.type;
	return *this;
}
void WrongAnimal::makeSound()const
{
	std::cout << "\e[0;34mWrong Strange Noise\e[0m" << std::endl;
}
std::string WrongAnimal::getType()const
{
	return(this->type);
}
