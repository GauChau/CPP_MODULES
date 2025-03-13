#include "RobotomyRequestForm.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("Shrub", false, 145, 137), _target(target)
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
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &	RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	AForm::operator=(rhs);
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
	// std::rand

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */