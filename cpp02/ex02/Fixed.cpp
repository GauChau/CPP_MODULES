/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:45:40 by gchauvot          #+#    #+#             */
/*   Updated: 2025/02/13 17:34:27 by gchauvot         ###   ########.fr       */
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
	(void) copy;
	this->_fpoint = copy._fpoint;
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
bool  Fixed::operator<(const Fixed &assign)
{
	if (this->_fpoint < assign._fpoint)
		return true;
	else
		return false;
}

bool  Fixed::operator>(const Fixed &assign)
{
	if (this->_fpoint > assign._fpoint)
		return true;
	else
		return false;
}
bool  Fixed::operator<=(const Fixed &assign)
{
	if (this->_fpoint <= assign._fpoint)
		return true;
	else
		return false;
}
bool  Fixed::operator>=(const Fixed &assign)
{
	if (this->_fpoint >= assign._fpoint)
		return true;
	else
		return false;
}
bool  Fixed::operator==(const Fixed &assign)
{
	if (this->_fpoint == assign._fpoint)
		return true;
	else
		return false;
}
bool  Fixed::operator!=(const Fixed &assign)
{
	if (this->_fpoint != assign._fpoint)
		return true;
	else
		return false;
}
Fixed  Fixed::operator+(const Fixed &assign)
{
	return Fixed(this->toFloat() + assign.toFloat());
}
Fixed  Fixed::operator-(const Fixed &assign)
{
	return Fixed(this->toFloat() - assign.toFloat());
}
Fixed  Fixed::operator*(const Fixed &assign)
{
	return Fixed(this->toFloat() * assign.toFloat());
}
Fixed  Fixed::operator/(const Fixed &assign)
{
	return Fixed(this->toFloat() / assign.toFloat());
}
Fixed &Fixed::operator++()
{
	this->_fpoint++;
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed temp;

	temp._fpoint = this->_fpoint;
	this->_fpoint++;
	return temp;
}
Fixed &Fixed::operator--()
{
	this->_fpoint--;
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed temp;

	temp._fpoint = this->_fpoint;
	this->_fpoint--;
	return temp;
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


Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return b;
}

Fixed &Fixed::max( Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return b;
}
Fixed const &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a._fpoint < b._fpoint)
		return (a);
	else
		return b;
}
Fixed const &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a._fpoint > b._fpoint)
		return (a);
	else
		return b;
}