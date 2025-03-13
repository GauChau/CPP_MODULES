#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

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
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &	PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	AForm::operator=(rhs);
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
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