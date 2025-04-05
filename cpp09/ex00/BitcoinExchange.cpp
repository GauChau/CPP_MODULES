#include "BitcoinExchange.hpp"

// Constructors
BitcoinExchange::BitcoinExchange(std::string dbin)
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	(void) copy;
}


// Destructor
BitcoinExchange::~BitcoinExchange()
{
}


// Operators
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &assign)
{
	(void) assign;
	return *this;
}

void BitcoinExchange::filldb(std::string dbin)
{
	std::ifstream dbstream;
	dbstream.open("data.csv");
	while (getli)
	{
		/* code */
	}
	

}



// Exceptions
const char * BitcoinExchange::InvalidDate::what() const throw()
{
	return "BTC EXCHANGE: Invalid Date";
}
const char * BitcoinExchange::InvalidValue::what() const throw()
{
	return "BTC EXCHANGE: Invalid Value";
}
const char * BitcoinExchange::InvalidInput::what() const throw()
{
	return "BTC EXCHANGE: Invalid Input";
}
