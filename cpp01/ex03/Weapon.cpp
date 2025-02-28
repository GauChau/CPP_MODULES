/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:14:47 by gchauvot          #+#    #+#             */
/*   Updated: 2025/02/06 11:50:21 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string _type): type(_type)
{
}

Weapon::~Weapon()
{
}

 std::string const &Weapon::getType(void)
{
	return(this->type);
}
void Weapon::setType(std::string type)
{
	this->type = type;
}