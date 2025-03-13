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

std::ostream &			operator<<( std::ostream & stream, ShrubberyCreationForm const & object )
{
	stream << object.getName() << " has an Exec grade req. of: "<< object.getGrade_exec()
	<< " and a Signing grade req. of: " << object.getGrade_sign()
	<< "." <<std::endl;
	return stream;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	ShrubberyCreationForm::FormAction(void)const
{
	std::string outfile= this->_target + "_shrubbery";
	std::ofstream os(outfile);
	if (os.fail() != 0)
	{
		std::cerr << "Error regarding outfile opening. \n";
		return ;
	}
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