/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:35:25 by gchauvot          #+#    #+#             */
/*   Updated: 2025/02/05 12:56:47 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <functional>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(std::string);
		~Zombie();
		void announce();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );



#endif