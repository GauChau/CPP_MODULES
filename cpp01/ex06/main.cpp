/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:45:47 by gchauvot          #+#    #+#             */
/*   Updated: 2025/02/06 16:18:35 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 0;

	std::string line;
	std::string level = argv[1];
	Harl	raler;

	// while (1)
	// {
	// 	std::getline(std::cin, line);
	// 	if(!std::cin)
	// 		return(0);
	// 	if (line.length() > 0)
	// 	{
	// 		raler.complain(line);
	// 	}
	// }
		raler.complain(level);
	return 0;
}