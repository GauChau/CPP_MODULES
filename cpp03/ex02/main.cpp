
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

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>


int main( void )
{
	ClapTrap uno("CL4PTR4P");
	ScavTrap una("SC4V");
	FragTrap due("FR4G");
	una.guardGate();
	una.attack("VICTIME");
	due.attack("HANDSOME JACK");
	due.highFivesGuys();

	std::cout << una.get_Hp()<<"\n";

	return 0;
}
