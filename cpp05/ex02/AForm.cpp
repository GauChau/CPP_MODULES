#include "AForm.hpp"

// Constructors

AForm::AForm(const std::string name, bool sign, const int grade_sign, const int grade_exec)
: _name(name), _sign(sign), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	std::cout << "\e[0;33mFields Constructor called of AForm\e[0m" << std::endl;
	if(_grade_exec < 1 || _grade_sign < 1)
	{
		std::cout << "invalid grade. Valid number from 1 to 150;\n";
		throw GradeTooHigh();
	}
	if(_grade_exec > 150 || _grade_sign > 150)
	{
		std::cout << "invalid grade. Valid number from 1 to 150;\n";
		throw GradeTooLow();
	}

}

AForm::AForm(const AForm &copy)
: _name(copy._name), _sign(copy._sign), _grade_sign(copy._grade_sign), _grade_exec(copy._grade_exec)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of AForm\e[0m" << std::endl;
}



// Destructor
AForm::~AForm()
{
	std::cout << "\e[0;31mDestructor called of AForm\e[0m" << std::endl;
}


// Operators
AForm & AForm::operator=(const AForm &assign)
{
	this->_sign = assign._sign;
	return *this;
}


// Getters / Setters
const std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSign() const
{
	return _sign;
}
void AForm::setSign(bool sign)
{
	_sign = sign;
}

int AForm::getGrade_sign() const
{
	return _grade_sign;
}

int AForm::getGrade_exec() const
{
	return _grade_exec;
}

void AForm::beSigned(Bureaucrat const &agent)
{
	if(agent.getGrade() <= _grade_sign)
		_sign = true;
	else if (agent.getGrade() > _grade_sign)
	{
		std::cout << "Bureaucrat's " << agent.getName() << " grade is too low. Get Promoted!\n";
		throw GradeTooLow();
	}
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSign())
	{
		throw FormNotSigned();
	}
	else if(executor.getGrade() > this->getGrade_exec())
	{
		throw GradeTooLow();
	}
	else
	{
		FormAction();
	}
}




// Exceptions
const char * AForm::GradeTooLow::what() const throw()
{
	return "Grade is too LOW";
}
const char * AForm::GradeTooHigh::what() const throw()
{
	return "Grade is too HIGH";
}
const char * AForm::FormNotSigned::what() const throw()
{
	return "Form is not SIGNED";
}



// Stream operators
std::ostream & operator<<(std::ostream &stream, const AForm &object)
{
	stream << object.getName() << " AForm has an Exec grade req. of: "<< object.getGrade_exec()
	<< " and a Signing grade req. of: " << object.getGrade_sign()
	<< "." <<std::endl;
	return stream;
}
