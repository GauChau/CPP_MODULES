/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:21:42 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/20 14:59:42 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(void): len(1)
{
	std::cout << "\e[0;33mDefault Constructor called of Array\e[0m" << std::endl;
	this->array = new T[1];
}

template <typename T>
Array<T>::Array(unsigned int n) : len(1)
{
	std::cout << "\e[0;33mLen Constructor called of Array\e[0m" << std::endl;
	this->array = new T[n];
}

template <typename T>
Array<T>::~Array(void)
{
	// delete[] this->array;
	delete this->array;
}

