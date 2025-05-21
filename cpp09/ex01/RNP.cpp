/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:33:03 by gautierchau       #+#    #+#             */
/*   Updated: 2025/05/21 16:38:57 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RNP.hpp"

static int strisfloatable(std::string &src)
{
	int point = 0;

	if(src.length() == 1)
		return (0);
    for (unsigned long i = 0; i < src.length(); i++)
	{
		if(!isdigit(src[i]))
		{
			if(i == 0 && src[i]=='-')
				continue;
			if(src[i] == '.' && i !=0 && i != src.length()-1 && !point)
			{
				point = 1;
				continue ;
			}
			if(src[i] == 'f' && i == src.length()-1)
				continue ;
			return -1;
		}
	}
	if (!point && src.c_str()[src.length()-1] == 'f')
		return (-1);
	if (point && src.c_str()[src.length()-1] == 'f')
		return (2);
	else if(point)
		return 3;
	return 1;
}

static int isstrdigit(std::string str)
{
	std::string::iterator iter = str.begin();
	while(iter != str.end())
	{
		// std::cout<< "loop:" << *iter<< "intcast:"<< (int)*iter<<std::endl;
		if(!std::isdigit(*iter))
		{
			// std::cout<< "not dig:" << *iter<< "intcast:"<< (int)*iter<<std::endl;
			return 0;
		}
		iter++;
	}
	return 1;
}

static int operatordetect(std::string str)
{
	if (str.length() != 1)
		return 0;
	if (str == "+" || str == "-" || str == "*" || str == "/")
		return 1;
	return 0;
}
// Constructors
RNP::RNP(std::string input) : _expression(input){}

RNP::RNP(const RNP &copy){*this = copy;}
// Destructor
RNP::~RNP()
{
}

// Operators
RNP & RNP::operator=(const RNP &assign)
{
	this->_expression = assign._expression;
	return *this;
}

void RNP::Calculate(std::string oper)
{
	if (this->_pile.size() < 2)
		throw BadSyntax();
	float b = this->_pile.top();
	this->_pile.pop();
	float a = this->_pile.top();
	this->_pile.pop();
	float c;

	if (oper == "+")
		c = a + b;
	else if (oper == "-")
		c = a - b;
	else if (oper == "*")
		c = a * b;
	else if (oper == "/")
		c = a / b;
	this->_pile.push(c);
		return ;
}

void RNP::Compute()
{
	std::istringstream instream(this->_expression);
	std::string	buffer;

	while(getline(instream, buffer, ' '))
	{
		if (buffer.length()==0)
			continue ;
		if((atof(buffer.c_str()) == 0 && !isstrdigit(buffer) && buffer != "-0" && !operatordetect(buffer))
			//|| this->_pile.size() > 2
			|| strisfloatable(buffer)<0 )
				throw BadSyntax();
		else if(operatordetect(buffer))
			this->Calculate(buffer);
		else
			this->_pile.push(atof(buffer.c_str()));
	}
	if (this->_pile.size()!=1)
		throw BadSyntax();
	std::cout << "RNP result: " << this->_pile.top()<<std::endl;
}

// Exceptions
const char * RNP::BadSyntax::what() const throw()
{
	return "RPN Error: Bad syntax";
}

const char * RNP::test1::what() const throw()
{
	return "RPN Error: TEST1";
}
