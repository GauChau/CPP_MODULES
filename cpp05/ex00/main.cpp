/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:03:04 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/10 14:20:00 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
	}

	catch (const std::exception &e) {
        std::cerr << "Exception 2 caught: " << e.what() << std::endl;
    }
	// john.grade_plus();
	// std::cout << john << std::endl;
	return 0;
}