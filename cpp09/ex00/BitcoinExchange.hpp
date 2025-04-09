#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <cstddef>
#include <algorithm>
#include <vector>
#include <map>

typedef struct s_date
{
	std::string year;
	std::string month;
	std::string day;

}t_date;


class BitcoinExchange
{
	public:
		// Constructors
		BitcoinExchange(std::string dbin);
		BitcoinExchange(const BitcoinExchange &copy);
		
		// Destructor
		~BitcoinExchange();
		
		// Operators
		BitcoinExchange & operator=(const BitcoinExchange &assign);
		
		// Exceptions
		class InvalidDate : public std::exception {
			virtual const char* what() const throw();
		};
		class InvalidValue : public std::exception {
			virtual const char* what() const throw();
		};
		class InvalidInput : public std::exception {
			virtual const char* what() const throw();
		};

		//members
		void	filldb(std::string dbin);
		int		DateChecker(std::string date);
		
	private:
		std::map<std::string, float> _data;
		
};

#endif