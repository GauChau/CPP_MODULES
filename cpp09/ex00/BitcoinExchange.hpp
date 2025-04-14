#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <cstddef>
#include <algorithm>
#include <vector>
#include <map>
#include <ctime>

typedef struct s_date
{
	std::string year;
	std::string month;
	std::string day;
	int iyear;
	int imonth;
	int iday;

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
		class NegVal : public std::exception {
			virtual const char* what() const throw();
		};
		class InvalidDB : public std::exception {
			virtual const char* what() const throw();
		};

		//members
		void	filldb(std::string dbin);
		int		DateChecker(std::string date);
		int		ValueChecker(std::string date);
		void	Convert(std::string input);
		int		GregorianChecker(s_date date);

	private:
		std::map<std::string, float> _data;
		bool dbcheck;

};

#endif