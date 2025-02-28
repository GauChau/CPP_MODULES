/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:45:40 by gchauvot          #+#    #+#             */
/*   Updated: 2025/02/28 15:40:33 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors
Fixed::Fixed()
{
	_fpoint = 0;
	std::cout << "\e[0;33mDefault Constructor called of Fixed\e[0m" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of Fixed\e[0m"<< std::endl;
}

Fixed::Fixed(const int val)
{
	std::cout << "\e[0;33mInt Constructor called of Fixed\e[0m"<< std::endl;
	this->_fpoint = val << this->_fracbit;
}


Fixed::Fixed(const float val)
{
	std::cout << "\e[0;33mFloat Constructor called of Fixed\e[0m"<< std::endl;
	this->_fpoint = (int)roundf(val * (1 << this->_fracbit));
}


// Destructor
Fixed::~Fixed()
{
	std::cout << "\e[0;31mDestructor called of Fixed\e[0m" << std::endl;
}


// Operators
Fixed & Fixed::operator=(const Fixed &assign)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->_fpoint = assign._fpoint;
	return *this;
}

//func
int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fpoint);
}

void Fixed::setRawBits( int const raw )
{
	this->_fpoint = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fpoint / (1 << this->_fracbit));
}
int Fixed::toInt(void) const
{
	return ((int)this->_fpoint >> this->_fracbit);
}