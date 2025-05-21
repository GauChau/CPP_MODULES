/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:03:07 by gautierchau       #+#    #+#             */
/*   Updated: 2025/05/21 16:28:18 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RNP.hpp"
#include <cstdlib>

int main(int argc, char **argv)
{
	if(argc !=2)
	{
		std::cout<<"wrong number of arguments. Only one arg: \"1 2 +\" for example.\n";
		return 0;
	}
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