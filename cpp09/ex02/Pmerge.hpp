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
#include <deque>

class Pmerge
{
	public:
		// Constructors
		Pmerge();
		Pmerge(const Pmerge &copy);
		// Destructor
		~Pmerge();

		// Operators
		Pmerge & operator=(const Pmerge &assign);

		// Members
		void	fillseq(std::string);
		void	mergelist_vector(int level, std::vector<int> &seq);
		void	mergelist_deque(int level, std::deque<int> &seq);
		template <typename T> void issorted(T joe);

		// Exceptions
		class BadInput : public std::exception {
			virtual const char* what() const throw();
		};
		class SortingFailed : public std::exception {
			virtual const char* what() const throw();
		};
		std::vector<int>& Get_vectored(void);
		std::deque<int>& Get_dequed(void);

		private:
			std::vector<int> _vectored;
			std::deque<int> _dequed;
			int _n;

};

template <typename T>
bool _compare(T lv, T rv)
{
	return *lv < *rv;
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
void insertblock(int pairsize, typename T::iterator iter, T &seq)
{
	typename T::iterator block_begin = iter;

	for (int x=0; (block_begin != seq.begin()) && (x<pairsize-1); std::advance(block_begin, -1),x++){}
	for(;block_begin != iter; std::advance(block_begin, 1))
		{seq.insert(seq.end(), *block_begin);}
	seq.insert(seq.end(), *block_begin);
}

template <typename T>
void printcontainer(T ctn)
{
	for(typename T::iterator i=ctn.begin(); i!=ctn.end();i++)
	{
			std::cout << *i<<" ";
	}
	std::cout << std::endl;
}

template <typename T>
void Pmerge::issorted(T joe)
{
	for(typename T::iterator i=joe.begin(), y; i!=joe.end();i++)
	{
		y = i+1;
		if (y == joe.end())
		{
			std::cout<< "\e[0;32mSUCCESS\e[0m" << std::endl;;
			return ;
		}
		if (*i > *y)
			throw Pmerge::SortingFailed();
	}
	std::cout << std::endl;
}

#endif