#ifndef PMERGE_HPP
# define PMERGE_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <cstddef>
#include <algorithm>
#include <vector>
#include <map>
#include <ctime>
#include <list>
#include <iterator>
#include <cstdio>
#include <filesystem>
#include <cmath>


class Pmerge
{
	public:
		// Constructors
		Pmerge();
		Pmerge(const Pmerge &copy);
		Pmerge(std::pair<int,int> merge);

		// Destructor
		~Pmerge();

		// Operators
		Pmerge & operator=(const Pmerge &assign);

		// Getters / Setters
		std::pair<int,int> getMerge() const;

		// Members
		void	fillseq(std::string);
		template <typename T> void	mergelist(int npairmax, T&);
		void	sortmlist(int pairsize, std::list<int>::iterator &pstart, std::list<int>::iterator &pend);


		// Exceptions
		class BadInput : public std::exception {
			virtual const char* what() const throw();
		};
		std::list<int> *_listed;

	private:
		std::pair<int,int> _merge;
		std::vector<int> _vectored;
		int _n;

};
long next_jack(long n);
long _jacobsthal_number(long n);



template <typename T>
bool _compare(T lv, T rv)
{
	return *lv < *rv;
}

template <typename T>
void printlist(T joe, int size, int unit_nbr)
{
	int x =1;
	bool color=0;
	unit_nbr++;
	std::cout <<"ctn len: "<< joe.size() << " n:"<<size<<" jacob:"<<next_jack(joe.size())<< std::endl;
	for(typename T::iterator i=joe.begin(); i!=joe.end();i++,x++)
	{


		if (color)
		{
			std::cout << "\e[0;33m";
			std::cout << *i;
			std::cout << " "<<"\e[0m";
		}
		else
		{
			std::cout << "\e[0;32m";
			std::cout << *i;
			std::cout << " "<<"\e[0m";
		}
		if(x == size)
		{
			color = !color;
			x = 0;
		}
	}
	std::cout << std::endl;
}

template <typename T>
void print_iter_list(T joe, int size, int unit_nbr)
{
	int x =1;
	bool color=0;
	unit_nbr++;
	std::cout <<"ctn len: "<< joe.size() << " n:"<<size<<" jacob:"<<next_jack(joe.size())<< " unitnbr: "<<unit_nbr<< std::endl;
	for(typename T::iterator i=joe.begin(); i!=joe.end();i++,x++)
	{


		if (color)
		{
			std::cout << "\e[0;33m";
			std::cout << **i;
			std::cout << " "<<"\e[0m";
		}
		else
		{
			std::cout << "\e[0;32m";
			std::cout << **i;
			std::cout << " "<<"\e[0m";
		}
		if(x == size)
		{
			color = !color;
			x = 0;
		}
	}
	std::cout << std::endl;
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
	std::vector<typename T::iterator> main, pend, rest;
	main.insert(main.end(), b);
	main.insert(main.end(), a);

	for  (int i =0;i<((unit_nbr-2)/2);i++)
	{
		std::advance(b, pairsize*2);
		pend.insert(pend.end(), b);
		std::advance(a, pairsize*2);
		main.insert(main.end(), a);
	}
	if(impair)
	{
		std::advance(b, pairsize*2);
		pend.insert(pend.end(), b);
		a = b;
	}
	for (std::advance(a, 1);a!=seq.end();std::advance(a, 1))
	{
		rest.insert(rest.end(), a);
	}

	int jackval = 1, prevjack = 1;
	for(int k = 1;k < 15; k++, prevjack=jackval, jackval=_jacobsthal_number(k))
	{
		std::cout<<"k: "<<k<< " jackval=" << jackval << " prevjack: "<<prevjack<<std::endl;
		typename std::vector<typename T::iterator>::iterator insert_point, topush = pend.begin();

		// for(int x = 0; x<prevjack-jackval;x++)
		// {
			if(topush!=pend.end())
				insert_point = std::upper_bound(main.begin(), main.end(), topush, _compare);
				// std::cout<< "comp"<<x<<": " <<_compare(*topush, *main.begin())<<"\n";
				// std::cout<<**main.begin()<< "comp"<<k<<": " <<**topush<<"\n";
			// main.insert(insert_point, *topush);
			// std::advance(topush,1);
		// }
	}
	std::cout<< "seq: ";
	printlist(seq, pairsize, unit_nbr);
	std::cout<< "MAINV1: ";
	print_iter_list(main, pairsize, unit_nbr);
	std::cout<< "PENDV1: ";
	print_iter_list(pend, pairsize, unit_nbr);
	std::cout<< "restV1: ";
	print_iter_list(rest, pairsize, unit_nbr);
	std::cout<< "---------------\n";
}

#endif