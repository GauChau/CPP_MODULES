/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:45:47 by gchauvot          #+#    #+#             */
/*   Updated: 2025/02/06 16:24:49 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	std::string line;
	Harl	raler;

	while (1)
	{
		std::getline(std::cin, line);
		if(!std::cin)
			return(0);
		if (line.length() > 0)
		{
			raler.complain(line);
		}
	}
	return 0;
}