#include "Pmerge.hpp"
#include <algorithm>
#include <iostream>
#include <list>



long _jacobsthal_number(long n) { return round((pow(2, n + 1) + pow(-1, n)) / 3); }

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

void printlist(std::list<int> joe, int size)
{
	int x =0;
	std::cout << "------ n:"<<size<<" jacob:"<<_jacobsthal_number(size)<< std::endl;
	for(std::list<int>::reverse_iterator i=joe.rbegin(); i!=joe.rend();i++)
	{


		if (x%size >size/2-1)
		{
			std::cout << "\e[0;33m"<< *i << " "<<"\e[0m";
		}
		else if(x%size <=size/2)
			std::cout << "\e[0;32m"<< *i << " "<<"\e[0m";
		else if(x == joe.size()/2)
			std::cout << "\e[0;31m"<< *i << " "<<"\e[0m";
		x++;
	}
	std::cout << std::endl<< "-----------"<< std::endl;
}

void	Pmerge::sortmlist(int pairsize, std::list<int>::iterator &pstart, std::list<int>::iterator &pend)
{

	std::list<int>::iterator next = pstart, memo = pstart;

	if (std::distance(pstart, pend) > 1)
	{
		std::advance(next, 2);
		while (next != pend)
		{
			if (*pstart > *next)
			{
				std::iter_swap(pstart, next);
				pstart = memo;
				continue ;
			}
			std::advance(pstart, 2);
		}
	}
	else
	{

	}
}

template <typename T>
int swap_pair(T block, typename T::iterator a1, typename T::iterator b1, int size)
{
	typename T::iterator a2=a1, b2=b1;

	a2 = std::advance(a2, 1);
	b2 = std::advance(b2, 1);
	if (a2 == block.rend() || b2 == block.rend())
		return 1;
	std::iter_swap(a1,b1);
	std::iter_swap(a2,b2);
	return 0;
}

void Pmerge::mergelist(int pairsize, std::list<int> &seq)
{
	// std::cout <<"mergelistse123q, pairsize: "<< pairsize<< std::endl;
	// printlist(seq);

	std::list<int>::reverse_iterator iterb = seq.rbegin(), itera, iterc, iterd;
	if (pairsize>1)
		mergelist(pairsize/2, seq);
	// std::cout<< seq.size() <<" b4 conpare   :\n";
	// printlist(seq);
	while (iterb != seq.rend()&& std::distance(iterb, seq.rend())>=pairsize)
	{
		itera=iterb;
		iterc=iterb;
		if(iterb != seq.rend())
			std::advance(iterc, 2);
		else
			iterc=seq.rend();
		
		std::advance(itera, (pairsize/2));
		if(pairsize==2)// if(std::distance(iterb,iterc) == 0)
		{
			if (*iterb < *itera)
			{
				// std::cout << " | SWAPED";
				std::iter_swap(itera,iterb);
			}
		}
		else 
		{
			if(pairsize==4)
			{
				if (*iterb < *itera)
				{
					std::swap_ranges(iterb,itera,itera);
				}
			}
			else
			{
				iterd=itera;
				std::advance(iterd, pairsize/4);
				for(int k = 1; k<pairsize/2;k+2)
				{

				}
			}
		}
		
		for (int x=0; x<pairsize;x++)
		{
			iterb++;
			if (iterb == seq.rend())
				break;

		}
		// std::cout <<"toaster, pairsize: "<< pairsize<< std::endl;
		std::cout<<std::endl;
	}

// 	std::cout<<std::endl<< seq.size() <<" after conpare: \n";
	printlist(seq, pairsize);

}


// void Pmerge::mergelist(int pairsize, std::list<int> &seq)
// {
// 	// std::cout <<"mergelistse123q, pairsize: "<< pairsize<< std::endl;
// 	// printlist(seq);

// 	std::list<int>::reverse_iterator iterb = seq.rbegin(), itera, iterc;
// 	if (pairsize>2)
// 		mergelist(pairsize/2, seq);
// 	// std::cout<< seq.size() <<" b4 conpare   :\n";
// 	// printlist(seq);
// 	while (iterb != seq.rend()&& std::distance(iterb, seq.rend())>=pairsize)
// 	{
// 		itera=iterb;
// 		iterc=iterb;
// 		std::advance(iterc, (pairsize/2)-1);//std::advance(iterc, 1);
// 		std::advance(itera, (pairsize/2));
// 		std::cout <<"pairl_"<< pairsize<< " step"<< pairsize/2 << " b:"
// 				<< *iterb<< " ,a:"<<*itera<< " ,c:"<<*iterc;
// 		if (*iterb < *itera)
// 		{
// 			// std::cout << "distance AB: "<<std::distance(iterb,itera)<<"\n";
// 			// if (pairsize>1)
// 			// 	mergelist(pairsize/2, seq);
// 			if(pairsize==2)// if(std::distance(iterb,iterc) == 0)
// 			{
// 				std::cout << " | SWAPED";
// 				std::iter_swap(itera,iterb);
// 			}
// 			else
// 			{
// 				std::cout <<"pairl_"<< pairsize<< " step"<< pairsize/2 << " b:"
// 				<< *iterb<< " ,a:"<<*itera<< " ,c:"<<*iterc;
// 				std::cout << " | RANGESWAPED";
// 				std::swap_ranges(itera,iterc,iterb);

// 				std::cout<<std::endl<< seq.size() <<" after RANGESWAPe: \n";

// 				std::cout <<"pairl_"<< pairsize<< " step"<< pairsize/2 << " b:"
// 				<< *iterb<< " ,a:"<<*itera<< " ,c:"<<*iterc;

// 				printlist(seq);
// 			}
// 		}
// 		for (int x=0; x<pairsize;x++)
// 		{
// 			iterb++;
// 			if (iterb == seq.rend())
// 				break;

// 		}
// 		// std::cout <<"toaster, pairsize: "<< pairsize<< std::endl;
// 		std::cout<<std::endl;
// 	}

// // 	std::cout<<std::endl<< seq.size() <<" after conpare: \n";
// // 	printlist(seq);

// }























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




