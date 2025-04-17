#include "Pmerge.hpp"
#include <algorithm>
#include <iostream>
#include <list>



void Pmerge::fillseq(std::string input)
{
	std::cout <<"fillseq"<< std::endl;
	std::stringstream s_input(input);
	std::string buffer;
	int x, i = 0;
	this->_listed = new std::list<int>;

	while (std::getline(s_input, buffer, ' '))
	{
		x = std::atoi(buffer.c_str());
		this->_listed->push_back(x);
		this->_vectored.push_back(x);
		i++;
	}
	this->_n = i;
}

void printlist(std::list<int> joe)
{
	for(std::list<int>::iterator i=joe.begin(); i!=joe.end();i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl<< "-----------"<< std::endl;
}

void Pmerge::mergelist(int pairsize, std::list<int> &seq)
{
	// std::cout <<"mergelistse123q, pairsize: "<< pairsize<< std::endl;
	// printlist(seq);
	if (pairsize>2)
		mergelist(pairsize/2, seq);
	std::list<int>::reverse_iterator iterb = seq.rbegin(), itera;
	// std::cout <<"b4 conpare ";
	// printlist(seq);
	while (iterb != seq.rend())
	{
		itera=iterb;
		std::advance(itera, (pairsize/2));
		// std::cout <<"pairsize:"<< pairsize<< " advance:"<< pairsize/2 << " itera:"<< *itera<< " ,iterb:"<<*iterb<<std::endl;
		if (*iterb < *itera)
		{
			std::iter_swap(itera,iterb);
		}
		for (int x=0; x<pairsize;x++)
		{
			iterb++;
			if (iterb == seq.rend())
				break;
		}
		// std::cout <<"toaster, pairsize: "<< pairsize<< std::endl;
	}
	// std::cout <<"after conpare ";
	// printlist(seq);
	
}























// Constructors
Pmerge::Pmerge()
{
}

Pmerge::Pmerge(const Pmerge &copy)
{
}

Pmerge::Pmerge(std::pair<int,int> merge)
{
}


// Destructor
Pmerge::~Pmerge()
{
}


// Operators
Pmerge & Pmerge::operator=(const Pmerge &assign)
{
	return *this;
}


// Getters / Setters
std::pair<int,int> Pmerge::getMerge() const
{
}


// Exceptions
const char * Pmerge::BadInput::what() const throw()
{
	return "Pmerge: Bad Input";
}

