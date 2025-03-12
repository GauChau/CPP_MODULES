#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm("Shrub", false, 145, 137), _target(target)
{

}


ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ):AForm(src.getName(), src.getSign(), 145, 137)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &	ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	AForm::operator=(rhs);
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	ShrubberyCreationForm::FormAction(std::ostream &os)
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