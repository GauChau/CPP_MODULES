/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:28:32 by gchauvot          #+#    #+#             */
/*   Updated: 2025/05/21 17:34:45 by gchauvot         ###   ########.fr       */
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
	longest = 0;
	this->array = std::vector<int>();
	this->array.reserve(N);
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
	// std::cout<< "size: "<<this->array.size()<< "x: "<< x<<std::endl;
	if (this->array.size()< N)
		this->array.push_back(x);
	else
		throw ArrayFull();
}


void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->array.size() + std::distance(begin, end) < N)
		this->array.insert(this->array.begin(), begin, end);
	else
		throw ArrayFull();
}


int Span::shortestSpan(void)
{
	if (this->array.size() < 2)
		throw NotEnough();
	std::sort(this->array.begin(),this->array.end());
	std::vector<int> result(this->array.size());

	std::vector<int>::iterator
		InBegin = this->array.begin(),
		InLast = this->array.end(),
		OuBegin = result.begin(),
		OuEnd = result.begin();

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
	if (this->array.size() <2)
		throw NotEnough();
	std::sort(this->array.begin(),this->array.end());
	int min = this->array.front();
	int max = this->array.back();
	this->longest = max - min;
	return (this->longest);
}



// Exceptions
const char * Span::NotEnough::what() const throw()
{
	return "Span: Not Enough Numbers";
}

const char * Span::ArrayFull::what() const throw()
{
	return "Span: ArrayFull";
}
