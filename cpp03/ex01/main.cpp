
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

#include <iostream>


int main( void )
{
	// ClapTrap uno("DOOMED");
	ScavTrap una("DOOMED");
	una.guardGate();
	una.attack("VICTIME");
	std::cout << una.get_Hp()<<"\n";

	return 0;
}
