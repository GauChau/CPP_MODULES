/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:28:32 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/31 17:25:41 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Constructors
Span::Span()
{
}

Span::Span(unsigned int N): N(N)
{
	lowest = 0;
	longest=0;
	this->array = std::vector<int>();
}

Span::Span(const Span &copy)
{
	*this=copy;
}


// Destructor
Span::~Span()
{
}


// Operators
Span & Span::operator=(const Span &assign)
{
	this->N = assign.N;
	this->lowest = assign.lowest;
	this->longest = assign.longest;
	this->array = std::vector<int>(assign.array);

	return *this;
}

// Members
void Span::addNumber(int x)
{
	this->array.push_back(x);
}


void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	this->array.insert(this->array.begin(), begin, end);
}


int Span::shortestSpan(void)
{

	if (this->N<2)
		throw OutOfBounds();
	std::sort(this->array.begin(),this->array.end());
	std::vector<int> result(this->array.size());

	std::vector<int>::iterator InBegin = this->array.begin();
	std::vector<int>::iterator InLast = this->array.end();
	std::vector<int>::iterator OuBegin = result.begin();
	std::vector<int>::iterator OuEnd = result.begin();

	// *OuBegin = *InBegin;
	InBegin++;
	// OuBegin++;

	while(InBegin != InLast)
	{
		*OuEnd =abs(*InBegin - *(InBegin-1));
		InBegin++;
		OuEnd++;
	}
	this->lowest = *std::min_element(OuBegin, OuEnd);
	return (this->lowest);


}


int Span::longestSpan(void)
{
	if (N<2)
		throw OutOfBounds();
	std::sort(this->array.begin(),this->array.end());
	int min = this->array.front();
	int max = this->array.back();
	this->longest = max - min;
	return (this->longest);
}



// Exceptions
const char * Span::OutOfBounds::what() const throw()
{
	return "Span: Out Of Bounds";
}
