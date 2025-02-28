/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:32:08 by gchauvot          #+#    #+#             */
/*   Updated: 2025/02/26 15:50:19 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void HumanA::attack(void)
{
	std::cout << this->name << " attacks with "
		<< this->weapon.getType() << std::endl;
}

HumanA::HumanA(std::string _name, Weapon& _weapon)
	: name(_name), weapon(_weapon)
{
}

HumanA::~HumanA()
{
}