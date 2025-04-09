#include "BitcoinExchange.hpp"

// Constructors
BitcoinExchange::BitcoinExchange(std::string dbin)
{
	std::cout<<this->_data.size()<<std::endl;
	std::cout<<this->_data.max_size()<<std::endl;
	this->filldb(dbin);
std::cout<<this->_data.begin()->second<<std::endl;
std::cout<<this->_data.end()->second<<std::endl;
	std::cout<< (this->_data.find("2022-03-04"))->first<<std::endl;
	std::cout<<this->_data.size()<<std::endl;
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
	std::string data;
	dbstream.open(dbin);

	while (std::getline(dbstream,data))
	{		
		std::pair<std::string, float> joe = std::make_pair(data.substr(0,10), std::atof((data.substr(11)).c_str()));
		this->_data[joe.first] = joe.second;
		// std::cout << joe.first << " "<< this->_data[joe.first] <<std::endl;
	}
	

}
int		BitcoinExchange::DateChecker(std::string date)
{
	t_date dday;
	size_t dash =0;

	dash = date.find("-");
	if(dash)
	{
		dday.year = date.substr(0,dash);
		dash = date.substr(dash+1).find("-");
		if(dash)
		{
			dday.month = date.substr(date.find("-") + 1, dash);
		}
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
