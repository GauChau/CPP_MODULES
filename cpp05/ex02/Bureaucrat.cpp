#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Constructors
Bureaucrat::Bureaucrat()
{
	std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string Name, int grade) : _Name(Name)
{
	if(grade < 151 && grade > 0)
		this->_grade = grade;
	else if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();

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

std::ostream & operator<<(std::ostream &stream, const Bureaucrat &object)
{
	stream << object.getName() << " bureaucrat grade " << object.getGrade() << ".\n";
	return stream;
}


// Members
const std::string	Bureaucrat::getName() const
{
	return this->_Name;
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::grade_plus()
{
	if(this->getGrade() > 1 && this->getGrade() <= 150)
		this->_grade--;
	else if (this->getGrade() < 2)
		throw GradeTooHighException();
	else if (this->getGrade() > 150)
		throw GradeTooLowException();
}
void	Bureaucrat::grade_minus()
{
	if(this->getGrade() >= 1 && this->getGrade() < 150)
		this->_grade++;
	else if (this->getGrade() < 1)
		throw GradeTooHighException();
	else if (this->getGrade() > 149)
		throw GradeTooLowException();
}

void	Bureaucrat::signAForm(AForm &AForm) const
{
	AForm.beSigned(*this);
	if(AForm.getSign())
		std::cout << this->getName() << " signed " << AForm.getName() << std::endl;
	else
	{
		std::cout << this->getName() << " couldn't signed " << AForm.getName() <<
		" for grade requirement is not met." << std::endl;
	}
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
