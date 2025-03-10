#include "Form.hpp"

// Constructors

Form::Form(const std::string name, bool sign, const int grade_sign, const int grade_exec)
: _name(name), _sign(sign), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	std::cout << "\e[0;33mFields Constructor called of Form\e[0m" << std::endl;
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

Form::Form(const Form &copy)
: _name(copy._name), _sign(copy._sign), _grade_sign(copy._grade_sign), _grade_exec(copy._grade_exec)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
}



// Destructor
Form::~Form()
{
	std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}


// Operators
Form & Form::operator=(const Form &assign)
{
	this->_sign = assign._sign;
	return *this;
}


// Getters / Setters
const std::string Form::getName() const
{
	return _name;
}

bool Form::getSign() const
{
	return _sign;
}
void Form::setSign(bool sign)
{
	_sign = sign;
}

int Form::getGrade_sign() const
{
	return _grade_sign;
}

int Form::getGrade_exec() const
{
	return _grade_exec;
}

void Form::beSigned(Bureaucrat const &agent)
{
	if(agent.getGrade() <= _grade_sign)
		_sign = true;
	else if (agent.getGrade() > _grade_sign)
	{
		std::cout << "Bureaucrat's " << agent.getName() << " grade is too low. Get Promoted!\n";
		throw GradeTooLow();
	}
}



// Exceptions
const char * Form::GradeTooLow::what() const throw()
{
	return "Grade is too LOW";
}
const char * Form::GradeTooHigh::what() const throw()
{
	return "Grade is too HIGH";
}


// Stream operators
std::ostream & operator<<(std::ostream &stream, const Form &object)
{
	stream << object.getName() << " Form has an Exec grade req. of: "<< object.getGrade_exec()
	<< " and a Signing grade req. of: " << object.getGrade_sign()
	<< "." <<std::endl;
	return stream;
}
