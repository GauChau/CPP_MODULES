/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautierchauvot <gautierchauvot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:03:04 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/12 20:07:43 by gautierchau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

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

		Bureaucrat ny("NY", 1);
		std::cout << ny << std::endl;

        ShrubberyCreationForm law("tree");
        ny.signAForm(law);
        std::cout << law;

        ShrubberyCreationForm law2("tree");
        std::cout << law2;
        ny.signAForm(law2);
        law.execute(ny);
        
	}

	catch (const std::exception &e) {
        std::cerr << "Exception 2 caught: " << e.what()<< std::endl;
    }
	// john.grade_plus();
	// std::cout << john << std::endl;
	return 0;
}