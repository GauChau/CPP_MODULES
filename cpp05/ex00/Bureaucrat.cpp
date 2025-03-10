#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat()
{
	std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string Name, int grade) : _Name(Name)
{
	this->_grade = grade;

}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _Name(copy._Name)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
}


// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}


// Operators
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &assign)
{
	this->_grade = assign._grade;
	return *this;
}


// Members
const std::string	Bureaucrat::getName()
{
	return this->_Name;
}

int	Bureaucrat::getGrade()
{
	return this->_grade;
}

void	Bureaucrat::grade_plus()
{
	if(this->getGrade() < 150)
		this->_grade++;
	else
		throw GradeTooHighException();
}
void	Bureaucrat::grade_minus()
{
	if(this->getGrade() > 0)
		this->_grade++;
	else
		throw GradeTooLowException();
}


// Exceptions
const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "GradeTooHigh";
}
const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "GradeTooLow";
}
