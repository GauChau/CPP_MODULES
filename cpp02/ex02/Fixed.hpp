/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:45:44 by gchauvot          #+#    #+#             */
/*   Updated: 2025/02/13 17:33:40 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <functional>
#include <stdio.h>
#include <fstream>
#include <filesystem>
#include <cmath>

class Fixed
{

	private:
		int _fpoint;
		static const int _fracbit = 8;

	public:
		// Constructors
		Fixed();
		Fixed(const Fixed &copy);
		Fixed(const int val);
		Fixed(const float val);

		// Destructor
		~Fixed();

		// Operators
		Fixed & operator=(const Fixed &assign);
		bool  operator<(const Fixed &assign);
		bool  operator>(const Fixed &assign);
		bool  operator>=(const Fixed &assign);
		bool  operator<=(const Fixed &assign);
		bool  operator==(const Fixed &assign);
		bool  operator!=(const Fixed &assign);
		Fixed operator+(const Fixed &assign);
		Fixed operator-(const Fixed &assign);
		Fixed operator*(const Fixed &assign);
		Fixed operator/(const Fixed &assign);
		Fixed operator++(int);
		Fixed operator--(int);
		Fixed & operator++();
		Fixed & operator--();

		static Fixed const &min( Fixed const& a,  Fixed const &b);
		static Fixed const &max(const Fixed &a, const Fixed &b);
		static Fixed &min(Fixed& a, Fixed &b);
		static Fixed &max(Fixed& a, Fixed &b);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat(void)const;
		int toInt(void)const;
};



#endif