/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:21:38 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/13 16:09:25 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
	std::cout<<"New intern recruited.\n";
}

Intern::Intern( const Intern & src )
{
	*this = src;
	std::cout<<"Intern copied.\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
	std::cout<<"Incompetent Intern is Fired.\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/


AForm	*createPresident(const std::string target)
{
	return(new PresidentialPardonForm(target));

}
AForm	*createRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}
AForm	*createShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}
/*
** --------------------------------- METHODS ----------------------------------
*/
AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string formlist_name[] = {"PRESIDENTIAL PARDON", "ROBOTOMY REQUEST", "SHRUBBERY CREATION"};
	AForm*(*formlist_classes[])(const std::string target) = {&createPresident, &createRobotomy, &createShrubbery};

	for (int i =0; i<3;i++)
	{
		if(name == formlist_name[i])
		{
			std::cout<< "intern creates "<< formlist_name[i] << std::endl;
			return (formlist_classes[i](target));
		}
	}
	std::cout<< name << " is not a bureautically approved form. Refer to XAVIER NIEL for approval." << std::endl;
	return NULL;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */