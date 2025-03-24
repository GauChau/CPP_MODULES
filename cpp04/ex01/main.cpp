/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:20:22 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/24 14:40:43 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "Brain.hpp"

#define SAIZE 5

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal* p = new Dog();
	const Animal* table[SAIZE];

	for(int k=0; k < SAIZE; k++)
	{
		if (k % 2 == 0)
		{
			table[k] = new Dog();
		}
		else
		{
			table[k] = new Cat();
		}
	}
	for(int k=0; k < SAIZE; k++)
	{
		delete table[k];
	}
	dynamic_cast<Dog*>(const_cast<Animal*>(p))->getBrain()->setIdeas(0,"ABC");
	dynamic_cast<Dog*>(const_cast<Animal*>(j))->getBrain()->setIdeas(0,"123");

	delete p;
	delete j;//should not create a leak
	delete i;
	// std::cout << i->getType() << j->getType()<<std::endl;


	Dog* A = new Dog();
	Dog* B = new Dog();

	A->getBrain()->setIdeas(0,"ABC");
	B->getBrain()->setIdeas(0,"123");

	std::cout << "dogs before: "
		<< "A: " << A->getBrain()->getIdeas(0) << std::endl
		<< "B: " << B->getBrain()->getIdeas(0) << std::endl;
	*A = *B;

	std::cout << "dogs after: "
		<< "A: " << A->getBrain()->getIdeas(0) << std::endl
		<< "B: " << B->getBrain()->getIdeas(0) << std::endl;

	delete B;
	std::cout << "dog after delete origin: "
		<< "A: " << A->getBrain()->getIdeas(0) << std::endl;
	delete A;
	return 0;
}