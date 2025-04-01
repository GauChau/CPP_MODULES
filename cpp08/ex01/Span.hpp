/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautierchauvot <gautierchauvot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:28:34 by gchauvot          #+#    #+#             */
/*   Updated: 2025/04/01 14:10:07 by gautierchau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <cstddef>
#include <algorithm>
#include <vector>

class Span
{
	public:
		// Constructors
		Span(unsigned int N);
		Span(const Span &copy);

		// Destructor
		~Span();

		// Operators
		Span & operator=(const Span &assign);

		// Exceptions
		class NotEnough : public std::exception {
			virtual const char* what() const throw();
		};
		class ArrayFull : public std::exception {
			virtual const char* what() const throw();
		};

		//members
		void addNumber(int x);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan(void);
		int longestSpan(void);

	private:
		std::vector<int> array;
		unsigned int N;
		unsigned int lowest;
		unsigned int longest;
		Span();

};

#endif