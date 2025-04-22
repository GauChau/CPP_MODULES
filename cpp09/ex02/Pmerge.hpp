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
		void	mergelist(int npairmax, std::list<int>&);
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

#endif