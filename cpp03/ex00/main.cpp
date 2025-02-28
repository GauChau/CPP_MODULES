
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

#include "ClapTrap.hpp"

#include <iostream>


int main( void )
{
	ClapTrap uno("DOOMED");
	uno.attack("demons");
	uno.takeDamage(1);
	uno.beRepaired(100);

	return 0;
}
