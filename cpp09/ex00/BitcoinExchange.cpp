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
	dbstream.open(dbin.c_str());

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
		if(!std::isdigit(*iter))
			return 0;
		iter++;
	}
	return 1;
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
	switch (date.imonth)
	{
		case 2:
			if (isLeapYear(date.iyear) && date.iday > 29)
				throw InvalidDate();
			else if (date.iday > 28)
				throw InvalidDate();
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (date.iday > 30)
				throw InvalidDate();
			break;
		default:
			break;
	}
}

int		BitcoinExchange::DateChecker(std::string date)
{
	t_date dday;
	std::istringstream input(date);

	std::getline(input, dday.year, '-');
	std::getline(input, dday.month, '-');
	std::getline(input, dday.day,' ');
	if (!isstrdigit(dday.year) || !isstrdigit(dday.month) || !isstrdigit(dday.day))
		return 0;

	std::time_t time = std::time(0);
	std::tm now = *std::localtime(&time);

	dday.iyear = std::atoi(dday.year.c_str());
	dday.imonth = std::atoi(dday.month.c_str());
	dday.iday = std::atoi(dday.day.c_str());

	//checks if date is gregorian calendar valid
	switch (dday.imonth)
	{
		case 2:
			if (isLeapYear(dday.iyear) && dday.iday > 29)
				throw InvalidDate();
			else if (dday.iday > 28)
				throw InvalidDate();
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (dday.iday > 30)
				throw InvalidDate();
			break;
		default:
			break;
	}

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

static std::string yesterday(std::string date)
{
	t_date dday;
	std::istringstream input(date);

	std::getline(input, dday.year, '-');
	std::getline(input, dday.month, '-');
	std::getline(input, dday.day,' ');

	dday.iyear = std::atoi(dday.year.c_str());
	dday.imonth = std::atoi(dday.month.c_str());
	dday.iday = std::atoi(dday.day.c_str());

	if (dday.iday == 1)
	{
		if(dday.imonth -1 == 0)
		{
			if(dday.iyear == 1900)
			{
				;
			}
			else
			{
				dday.iyear--;
			}
		}
	}
	else
	{
		dday.iday--;
	}

}

void	BitcoinExchange::Convert(std::string input)
{
	if(input.substr(input.find(".txt")) != ".txt")
		throw InvalidInput();

	std::ifstream sinput;
	std::string data, ldata;
	sinput.open(input.c_str());

	while (std::getline(sinput,data))
	{
		std::istringstream sline(data);
		std::getline(sline, ldata, '|');
		this->DateChecker(ldata);

	}


}



// Exceptions
const char * BitcoinExchange::InvalidDate::what() const throw()
{
	return "BTC EXCHANGE: Invalid Date";
}
const char * BitcoinExchange::InvalidDate_ys::what() const throw()
{
	return 0;
}
const char * BitcoinExchange::InvalidValue::what() const throw()
{
	return "BTC EXCHANGE: Invalid Value";
}
const char * BitcoinExchange::InvalidInput::what() const throw()
{
	return "BTC EXCHANGE: Invalid Input";
}
