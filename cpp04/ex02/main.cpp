/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:20:22 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/10 11:32:32 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "Brain.hpp"
#include <stdio.h>

#define SAIZE 50

int main()
{
  std::cout << "-------------------[Mandatory tests 0]----------------------" << std::endl;
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  delete j;//should not create a leak
  delete i;
  std::cout << "-------------------[Mandatory tests 1]----------------------" << std::endl;
  std::cout << "~~~~~~~~~~~~~~~[INIT]~~~~~~~~~~~~~~~" << std::endl;
  Animal *animals[10];
  for (int i = 0; i < 10; i++) {
    std::cout << "[" << i << "] ";
    if (i < 5)
      animals[i] = new Cat();
    else
      animals[i] = new Dog();
    if (!animals[i]) {
      for (int j = 0; j < i; j++) {delete animals[j];}
      std::cout << "Memory alloctation error" << std::endl;
      return 1;
    }
  }

  std::cout << "~~~~~~~~~~~~~~~[COPY]~~~~~~~~~~~~~~~" << std::endl;
  dynamic_cast<Cat*>(animals[0])->getBrain()->setIdeas(0,"Big boss is a one man army");
  dynamic_cast<Dog*>(animals[5])->getBrain()->setIdeas(0,"Ocelot is the best gun shooter");

  Cat* catCopy = new Cat(*dynamic_cast<Cat*>(animals[0]));
  if (!catCopy) {
    std::cout << "Memory alloctation error" << std::endl;
    for (int i = 0; i < 10; i++) {delete animals[i];}
    return 1;
  }
  Dog* dogCopy = new Dog(*dynamic_cast<Dog*>(animals[5]));
  if (!dogCopy) {
    for (int i = 0; i < 10; i++) {delete animals[i];}
    delete catCopy;
    std::cout << "Memory alloctation error" << std::endl;
    return 1;
  }

  std::cout << "~~~~~~~~~~~~~~~[ACTIONS]~~~~~~~~~~~~~~~" << std::endl;
  for (int i = 0; i < 10; i++) {
    animals[i]->makeSound();
    if (i == 0)
      std::cout << dynamic_cast<Cat*>(animals[i])->getBrain()->getIdeas(0) << std::endl;
    if (i == 5)
      std::cout << dynamic_cast<Dog*>(animals[i])->getBrain()->getIdeas(0) << std::endl;
  }

  std::cout << "~~~~~~~~~~~~~~~[CLEAR]~~~~~~~~~~~~~~~" << std::endl;
  for (int i = 0; i  < 10; i++) {delete animals[i];}
  delete catCopy;
  delete dogCopy;
  return 0;
}

// int main()
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	// const Animal* p;
// 	const Animal* table[SAIZE];
// 	const Dog *joe= new Dog();
// 	const Dog *Huj= new Dog();
// 	joe = Huj;
// 	// delete Huj;
// 	// p = j;
// 	// std::string l="joe;";
// 	// std::string v="aoe;";
// 	// l = v;
// 	for(int k=0; k < SAIZE; k++)
// 	{
// 		if (k % 2 == 0)
// 		{
// 			table[k] = new Dog();
// 		}
// 		else
// 		{
// 			table[k] = new Cat();
// 		}
// 	}
// 	for(int k=0; k < SAIZE; k++)
// 	{
// 		delete table[k];
// 	}
// 	// printf("p:%, j:%p\n", p->getType(), j->getType());
// 	delete j;//should not create a leak
// 	// std::cerr <<"p:"<<p->getType()<<std::endl;
// 	std::cerr <<"p:"<< joe->getBrain()<<std::endl;
// 	delete joe;
// 	// delete p;
// 	// std::cerr <<"j:"<<j->getType()<<std::endl;
// 	delete i;
// 	// std::cout << i->getType() << j->getType()<<std::endl;
// 	return 0;
// }