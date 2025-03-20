/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:55:14 by gautierchau       #+#    #+#             */
/*   Updated: 2025/03/20 11:40:55 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

int main(void)
{

	Base *b = generate();

	std::cout << "----- GENERATING ------" << std::endl;
	identify(b);
	identify(*b);

	delete b;
	return 0;
	return 0;
}