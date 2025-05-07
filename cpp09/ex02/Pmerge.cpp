#include "Pmerge.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>



template <typename T>
bool _compare(T lv, T rv)
{
	return *lv < *rv;
}


long _jacobsthal_number(long n)
{
	return round((pow(2, n + 1) + pow(-1, n)) / 3);
}
long next_jack(long n)
{
	int prev =0;

	int res=0;
	for(int i=0;res<n;i++)
	{
		prev = res;
		res = _jacobsthal_number(i);
	}
	return(prev);
}

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
template <typename T>
void printlist(T joe, int size, int unit_nbr)
{
	int x =1;
	bool color=0;
	std::cout <<"ctn len: "<< joe.size() << " n:"<<size<<" jacob:"<<next_jack(joe.size())<< std::endl;
	for(typename T::iterator i=joe.begin(); i!=joe.end();i++,x++)
	{


		if (color)
		{
			std::cout << "\e[0;33m"<< *i << " "<<"\e[0m";
		}
		else
			std::cout << "\e[0;32m"<< *i << " "<<"\e[0m";
		// else if(x == joe.size()/2)
		// 	std::cout << "\e[0;31m"<< *i << " "<<"\e[0m";
		if(x == size)
		{
			color = !color;
			x = 0;
		}
	}
	std::cout << std::endl;
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
int swap_pair(T block, typename T::iterator a, typename T::iterator b, int size)
{

	for(int i=0; i <size;i++)
	{
		if (a == block.end() || b == block.end())
			return 1;
		std::iter_swap(a,b);
		std::advance(a, -1);
		std::advance(b, -1);
	}
	return 0;
}
template <typename T>
void Pmerge::mergelist(int level, T &seq)
{
	int pairsize = pow(2,level-1), unit_nbr = seq.size() / pairsize;
	int impair = (unit_nbr %2);
	typename T::iterator a, b, a_end, b_end;

	std::cout<<"\nB4 psize: "<<pairsize<<", unit_nbr: "<<unit_nbr<<std::endl;
	if (unit_nbr < 2)
		return ;
	a = seq.begin();
	b = a;
	std::advance(a, 2*pairsize-1);
	std::advance(b, pairsize-1);
	int x;
	for (x =0; x < unit_nbr /2;x++)
	{
		std::cout<< "unit nbr/2: "<< unit_nbr/2<<" for x: "<<x
				<< " a: "<<*a<<" b: "<<*b<<std::endl;
		if (*a < *b)
		{
			std::cout<<"SWAP a: "<<*a<<" b: "<<*b<<std::endl;
			swap_pair(seq, b, a, pairsize);
		}
		std::advance(a, pairsize*2);
		std::advance(b, pairsize*2);
	}
	std::cout<<"AF psize: "<<pairsize<<", unit_nbr: "<<unit_nbr<<", x ="<<x<<std::endl;
	printlist(seq, pairsize, unit_nbr);
	mergelist(level+1, seq);

	a = seq.begin();
	b = a;
	std::advance(a, 2*pairsize-1);
	std::advance(b, pairsize-1);



	//aend and bend are like a.end() they are the * after the value to determine end., so the element a is in the range b_end..a,
	// typename T::iterator main, pend, rest;
	std::vector<typename T::iterator> main,pend,rest;
	main.insert(main.end(), b);
	main.insert(main.end(), a);

	for  (int i =0;i<((unit_nbr-3)/2);i++)
	{
		std::advance(b, pairsize*2);
		pend.insert(pend.end(), b);
		std::advance(a, pairsize*2);
		main.insert(main.end(), a);
	}
	if(rest.size()>=(pairsize))
	{
		for(int i=0;i<pairsize;i++)
		{
			pend.insert(pend.end(), *rest.begin());
			rest.erase(rest.begin());
		}
	}
	if (pairsize==1)
	{
		pend.insert(pend.end(),rest.begin(),rest.end());
		rest.erase(rest.begin(), rest.end());
	}


	int jackval = 1, prevjack = 1;
	for(int k = 1;k < 15; k++, prevjack=jackval, jackval=_jacobsthal_number(k))
	{
		std::cout<<"k: "<<k<< " jackval=" << jackval << " prevjack: "<<prevjack<<std::endl;
		std::vector<typename T::iterator> insert_point, topush = pend.begin();

		for(int x = 0; x<prevjack-jackval;x++)
		{
			insert_point = std::upper_bound(main.begin(), main.end(), topush, _compare);
			main.insert(insert_point, *topush);
			std::advance(topush,1);
		}
	}
	std::cout<< "MAINV2: ";
	printlist(main, pairsize, unit_nbr);
	std::cout<< "PENDV2: ";
	printlist(pend, pairsize, unit_nbr);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//V2 V2 V2
// template <typename T>
// void Pmerge::mergelist(int level, T &seq)
// {
// 	int pairsize = pow(2,level-1), unit_nbr = seq.size() / pairsize;
// 	int impair = (unit_nbr %2);
// 	typename T::iterator a, b, a_end, b_end;

// 	std::cout<<"\nB4 psize: "<<pairsize<<", unit_nbr: "<<unit_nbr<<std::endl;
// 	if (unit_nbr < 2)
// 		return ;
// 	a = seq.begin();
// 	b = a;
// 	std::advance(a, 2*pairsize-1);
// 	std::advance(b, pairsize-1);
// 	int x;
// 	for (x =0; x < unit_nbr /2;x++)
// 	{
// 		std::cout<< "unit nbr/2: "<< unit_nbr/2<<" for x: "<<x
// 				<< " a: "<<*a<<" b: "<<*b<<std::endl;
// 		if (*a < *b)
// 		{
// 			std::cout<<"SWAP a: "<<*a<<" b: "<<*b<<std::endl;
// 			swap_pair(seq, b, a, pairsize);
// 		}
// 		std::advance(a, pairsize*2);
// 		std::advance(b, pairsize*2);
// 	}
// 	std::cout<<"AF psize: "<<pairsize<<", unit_nbr: "<<unit_nbr<<", x ="<<x<<std::endl;
// 	printlist(seq, pairsize, unit_nbr);
// 	mergelist(level+1, seq);

// 	a = seq.begin();
// 	b = a;
// 	std::advance(a, 2*pairsize-1);
// 	std::advance(b, pairsize-1);



// 	//aend and bend are like a.end() they are the * after the value to determine end., so the element a is in the range b_end..a,
// 	typename T::iterator main, pend, rest;
// 	std::vector<typename T::iterator> mainI,pendI,restI;
// 	a_end = a;
// 	b_end = b;
// 	std::advance(a_end, 1);
// 	std::advance(b_end, 1);
// 	main.insert(main.end(), seq.begin(), a_end);
// 	// rest.insert(rest.end(), lasta, seq.end());

// 	for  (int i =0;i<((unit_nbr-3)/2);i++)
// 	{
// 		std::advance(b, pairsize*2);
// 		std::advance(b_end, pairsize*2);
// 		pend.insert(pend.end(), a_end, b_end);
// 		std::advance(a, pairsize*2);
// 		std::advance(a_end, pairsize*2);
// 		main.insert(main.end(), b_end, a_end);
// 	}
// 	if(a_end != seq.end())
// 		rest.insert(rest.end(), a_end, seq.end());
// 	if(rest.size()>=(pairsize))
// 	{
// 		for(int i=0;i<pairsize;i++)
// 		{
// 			pend.insert(pend.end(), *rest.begin());
// 			rest.erase(rest.begin());
// 		}
// 	}

// 	if (pairsize==1)
// 	{
// 		pend.insert(pend.end(),rest.begin(),rest.end());
// 		rest.erase(rest.begin(), rest.end());
// 	}

// 	std::cout<<"LEVEL: "<<level<<"impair: "<<impair<<" POST INSERT: psize: "<<pairsize<<", unit_nbr: "<<unit_nbr<<std::endl << "MAIN: ";
// 	printlist(main, pairsize, unit_nbr);
// 	std::cout<< "PEND: ";
// 	printlist(pend, pairsize, unit_nbr);
// 	std::cout<< "rest: ";
// 	printlist(rest, pairsize, unit_nbr);std::cout<< "\n";

// 	int jackval = 1, prevjack = 1;
// 	for(int k = 1;k < 15; k++, prevjack=jackval, jackval=_jacobsthal_number(k))
// 	{
// 		std::cout<<"k: "<<k<< " jackval=" << jackval << " prevjack: "<<prevjack<<std::endl;
// 		std::vector<int>::iterator insert_point, topush = pend.begin();

// 		for(int x = 0; x<prevjack-jackval;x++)
// 		{
// 			insert_point = std::upper_bound(main.begin(), main.end(), *topush);
// 			main.insert(insert_point, *topush);
// 			std::advance(topush,pairsize*2);
// 		}


// 	}

// }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// V1
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




