/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:02:09 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/20 11:44:57 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base *generate(void)
{
	std::srand(std::time(0));
	int dice = std::rand() %3;
	std::cout << "dice: " <<dice << "\n";

	switch (dice)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default :
			return NULL;
	}


}

void identify(Base *p)
{
	try
	{
		if(dynamic_cast<A*>(p))
		{
			std::cout << "type is A"<<std::endl;
		}
		else if(dynamic_cast<B*>(p))
		{
			std::cout << "type is B"<<std::endl;
		}
		else if(dynamic_cast<C*>(p))
		{
			std::cout << "type is C"<<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

void identify(Base& p)
{
	try
	{
		if(dynamic_cast<A*>(&p))
		{
			std::cout << "type is A"<<std::endl;
		}
		else if(dynamic_cast<B*>(&p))
		{
			std::cout << "type is B"<<std::endl;
		}
		else if(dynamic_cast<C*>(&p))
		{
			std::cout << "type is C"<<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}