#ifndef RNP_HPP
# define RNP_HPP

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
#include <stack>

class RNP
{
	public:
		// Constructors
		RNP(std::string input);
		RNP(const RNP &copy);

		// Destructor
		~RNP();

		// Operators
		RNP & operator=(const RNP &assign);

		// Exceptions
		class BadSyntax : public std::exception {
			virtual const char* what() const throw();
		};

		//Members
		void Compute(void);
		void Calculate(std::string oper);

	private:
		std::stack<float> _pile;
		std::string _expression;

};

#endif