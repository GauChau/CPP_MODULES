/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:03:07 by gautierchau       #+#    #+#             */
/*   Updated: 2025/05/21 14:08:07 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RNP.hpp"
#include <cstdlib>

int main(int argc, char **argv)
{
	(void)argc;
	std::string test = argv[1];
	RNP tost(test);
	try
	{
		/* code */
		tost.Compute();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}