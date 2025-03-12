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

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	RobotomyRequestForm::FormAction(std::ostream &os)
{
	os
	<< "        *                *\n"
    << "       ***              ***\n"
    << "      *****            *****\n"
    << "     *******          *******\n"
    << "    *********        *********\n"
    << "   ***********      ***********\n"
    << "  *************    *************\n"
    << "       | |              | |\n"
    << "       | |              | |"
    << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */