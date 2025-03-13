#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("NoTarget", false, 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm("PresidentialPardonForm", false, 72, 45), _target(target)
{

}


PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ):AForm(src.getName(), src.getSign(), 72, 45)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\e[0;31mDestructor called of PresidentialPardonForm\e[0m" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &	PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	AForm::operator=(rhs);
	this->_target = rhs._target;
	return *this;
}

std::ostream &			operator<<( std::ostream & stream, PresidentialPardonForm const & object )
{
	stream << object.getName() << " has an Exec grade req. of: "<< object.getGrade_exec()
	<< " and a Signing grade req. of: " << object.getGrade_sign()
	<< "." <<std::endl;
	return stream;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	PresidentialPardonForm::FormAction(void)const
{
	std::cout<< this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */