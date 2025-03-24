/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:20:22 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/24 12:20:56 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* k = new Cat();
	const WrongAnimal* i = new WrongCat();
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	meta->makeSound();
	j->makeSound();
	k->makeSound();
	i->makeSound(); //will output the wrongcat sound!

	delete meta;
	delete j;
	delete k;
	delete i;


	return 0;
}