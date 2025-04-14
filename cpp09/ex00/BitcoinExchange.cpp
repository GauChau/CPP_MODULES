#include "BitcoinExchange.hpp"

// Constructors
BitcoinExchange::BitcoinExchange(std::string dbin)
{
	// std::cout<<this->_data.size()<<std::endl;
	// std::cout<<this->_data.max_size()<<std::endl;
	this->filldb(dbin);
	// std::cout<<this->_data.begin()->second<<std::endl;
	// std::cout<<this->_data.end()->second<<std::endl;
	// std::cout<< (this->_data.find("2022-03-04"))->first<<std::endl;
	// std::cout<<this->_data.size()<<std::endl;
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
	dbstream.open(dbin.c_str());
	if (!dbstream.is_open())
	{
		// throw InvalidDB();
		dbcheck = 0;
		return ;
	}
	dbcheck = 1;
	while (std::getline(dbstream,data))
	{
		std::pair<std::string, float> joe = std::make_pair(data.substr(0,10),
												std::atof((data.substr(11)).c_str()));
		this->_data[joe.first] = joe.second;
		// std::cout << joe.first << " "<< this->_data[joe.first] <<std::endl;
	}


}

static int isstrdigit(std::string str)
{
	std::string::iterator iter = str.begin();
	while(iter != str.end())
	{
		// std::cout<< "loop:" << *iter<< "intcast:"<< (int)*iter<<std::endl;
		if(*iter != 0 && !std::isdigit(*iter))
		{
			// std::cout<< "not dig:" << *iter<< "intcast:"<< (int)*iter<<std::endl;
			return 0;
		}
		iter++;
	}
	return 1;
}

static void trimspc(std::string *str)
{
	std::string::iterator iter = str->begin();
	if(*iter == ' ')
		str->erase(iter);
	iter = str->end() -1;
	if(*iter == ' ')
		str->erase(iter);
}

bool isLeapYear(int year) {
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
	{
        return true;
    }
    return false;
}

int		BitcoinExchange::GregorianChecker(s_date date)
{
	if (date.imonth>12 || date.iyear < 1900)
	{
		return 0;
	}
	switch (date.imonth)
	{
		case 2:
			if (isLeapYear(date.iyear) && date.iday > 29)
				return 0;
			else if (date.iday > 28)
				return 0;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (date.iday > 30)
				return 0;
			break;
		default:
			if (date.iday > 31)
				return 0;
			break;
	}
	return 1;
}

static t_date ddayfill(std::string date)
{
	t_date dday;
	std::istringstream input(date);

	std::getline(input, dday.year, '-');
	std::getline(input, dday.month, '-');
	std::getline(input, dday.day);

	dday.iyear = std::atoi(dday.year.c_str());
	dday.imonth = std::atoi(dday.month.c_str());
	dday.iday = std::atoi(dday.day.c_str());

	return dday;

}

int		BitcoinExchange::DateChecker(std::string date)
{
	t_date dday = ddayfill(date);
	if (!isstrdigit(dday.year) || !isstrdigit(dday.month) || !isstrdigit(dday.day))
		throw InvalidDate();
	//checks if date is gregorian calendar valid
	if (!GregorianChecker(dday))
		throw InvalidDate();

	std::time_t time = std::time(0);
	std::tm now = *std::localtime(&time);

	//checks whether date is anterior of current day
	if (dday.iyear > now.tm_year + 1900 || dday.imonth > 12 || dday.iday > 31)
		throw InvalidDate();
	if (dday.iyear == now.tm_year + 1900)
	{
		if (dday.imonth == now.tm_mon + 1)
		{
			if (dday.iday > now.tm_mday)
				throw InvalidDate();
		}
		else if (dday.imonth > now.tm_mon + 1)
			throw InvalidDate();
	}
	return 1;
}

int		BitcoinExchange::ValueChecker(std::string input)
{
	double value = std::atof(input.c_str());

	if (value < 0)
		throw NegVal();
	if (!isstrdigit(input))
		throw InvalidValue();
	if (value > 2147483647 || input.length() > 10)
		throw InvalidValue();	
	return 0;
}

void	BitcoinExchange::Convert(std::string input)
{
	if (!dbcheck)
	{
		throw InvalidDB();
	}
	
	std::istringstream sinput(input);
	std::string in_key, in_value;
	std::map<std::string, float>::iterator iter;

	std::getline(sinput,in_key, '|');
	std::getline(sinput,in_value);
	trimspc(&in_key);
	trimspc(&in_value);
	if(in_value.length()<1)
		throw InvalidInput();

	this->DateChecker(in_key);
	this->ValueChecker(in_value);

	iter = this->_data.find(in_key);
	if (iter == this->_data.end())
	{
		this->_data[in_key] = -1;
		iter = this->_data.find(in_key);
		if (iter == this->_data.begin())
			throw InvalidDate();
		iter--;
		this->_data[in_key] = iter->second;
	}
	double res = (double)iter->second * atof(in_value.c_str());

	std::cout << in_key << "->" << iter->second << "$ * " << in_value << "BTC = "
			<<  res << "$." << std::endl;
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
const char * BitcoinExchange::NegVal::what() const throw()
{
	return "BTC EXCHANGE: Negative Value";
}
const char * BitcoinExchange::InvalidDB::what() const throw()
{
	return "BTC EXCHANGE: Database loading error.";
}
