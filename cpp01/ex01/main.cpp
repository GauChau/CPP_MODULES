/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:58:27 by gchauvot          #+#    #+#             */
/*   Updated: 2025/02/24 12:39:35 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main()
{
	int N = 42;
	std::string name = "Xavier";

	Zombie *moar = zombieHorde(N, name);
	for(int i = 0; i < N; i++)
	{
		moar[i].announce();
	}
	delete[] moar;
	return (0);
}