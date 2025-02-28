/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:58:27 by gchauvot          #+#    #+#             */
/*   Updated: 2025/02/05 15:07:44 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <functional>
#include <stdio.h>


int main()
{
	std::string 	uno = "HI THIS IS BRAIN";
	std::string* 	stringPTR = &uno;
	std::string& 	stringREF = uno;

	std::cout << "uno address :" << &uno << std::endl;
	std::cout << "stringPTR address :" << stringPTR << std::endl;
	std::cout << "stringREF address :" << &stringREF << std::endl;
	std::cout << "uno value :" << uno << std::endl;
	std::cout << "stringPTR value :" << *stringPTR << std::endl;
	std::cout << "stringREF value :" << stringREF << std::endl;

	return (0);
}