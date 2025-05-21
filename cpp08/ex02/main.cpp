/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:01:07 by gchauvot          #+#    #+#             */
/*   Updated: 2025/05/21 17:30:03 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

void tests()
{
    MutantStack<int> mstack;
	std::stack<int> koko;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.push(4);
    mstack.push(5);
    mstack.push(6);
	for(MutantStack<int>::iterator it = mstack.begin(); it != mstack.end();it++)
	{
		std::cout<<"mstack: " << *it << std::endl;
	}

	for(;mstack.size()>0;mstack.pop())
	{
		std::cout<<"mtop: " << mstack.top() << std::endl;
	}

}

int main(void)
{
    tests();
    return 0;
}