/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:03:04 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/13 12:23:06 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main (void)
{
    try
	{
        Bureaucrat john("John", 150);
        std::cout << john << std::endl;

        john.grade_plus();
        std::cout << john << std::endl;

        john.grade_minus();
        std::cout << john << std::endl;

        Bureaucrat boss("Boss", 1);
        std::cout << boss << std::endl;
        boss.grade_plus(); // error
    }
    catch (const std::exception &a) {
        std::cerr << "Exception 1 caught: " << a.what() << std::endl;
    }
	try
	{

		Bureaucrat ny("NY", 10);
		std::cout << ny << std::endl;

        ShrubberyCreationForm law("CHENE");
        PresidentialPardonForm law2("NIXON");
        RobotomyRequestForm law3("BENDER");
        RobotomyRequestForm law4("FLEXO");
        law3 = law4;

        std::cout << law;
        std::cout << law2;
        std::cout << law3;
        std::cout << "______________________________________\n";
        ny.signAForm(law);
        ny.signAForm(law2);
        ny.signAForm(law3);
        std::cout << "______________________________________\n";
        ny.executeForm(law);
        ny.executeForm(law2);
        ny.executeForm(law3);

	}

	catch (const std::exception &e) {
        std::cerr << "Exception 2 caught: " << e.what()<< std::endl;
    }


	// john.grade_plus();
	// std::cout << john << std::endl;
	return 0;
}