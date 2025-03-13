#include "RobotomyRequestForm.hpp"
#include <ctime>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
RobotomyRequestForm::RobotomyRequestForm():AForm("NoTarget", false, 145, 137)
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("RobotomyRequestForm", false, 145, 137), _target(target)
{

}


RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ):AForm(src.getName(), src.getSign(), 145, 137)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\e[0;31mDestructor called of RobotomyRequestForm\e[0m" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &	RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	AForm::operator=(rhs);
	this->_target = rhs._target;
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & stream, RobotomyRequestForm const & object )
{
	stream << object.getName() << " has an Exec grade req. of: "<< object.getGrade_exec()
	<< " and a Signing grade req. of: " << object.getGrade_sign()
	<< "." <<std::endl;
	return stream;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	RobotomyRequestForm::FormAction(void)const
{
	std::srand(std::time(0));
	int flip = rand();
	std::cout << "Brrrrrrrrr ... Brrrrrr ... Bratatatatataaatatatatata\n";
	if((flip %2) == 0)
	{
		std::cout << _target << " has been successfully robotomized." << std::endl;
	}
	else
	{
		std::cout << "Robotomy on " << _target << " has failed miserably." << std::endl;
	}

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */