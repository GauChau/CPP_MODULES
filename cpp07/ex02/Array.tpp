/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautierchauvot <gautierchauvot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:21:42 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/21 11:01:59 by gautierchau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(void): len(0)
{
	std::cout << "\e[0;33mDefault Constructor called of Array\e[0m" << std::endl;
	this->array = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n) : len(n)
{
	std::cout << "\e[0;33mLen Constructor called of Array\e[0m" << std::endl;
	this->array = new T[n];
}

template <typename T>
Array<T>::Array(Array<T> &copy)
{
	std::cout << "\e[0;33mCopy Constructor called of Array\e[0m" << std::endl;
	*this = copy;
	return *this;
}

template <typename T>
Array<T> & Array<T>::operator=(Array<T> &src)
{
	if (this->array)
		delete[] this->array;
	this->len = src.len;
	this->array = new T[this->len];
	for (size_t i = 0; i < len; i++)
	{
		this->array[i] = src.array[i];
	}	
}

template <typename T>
Array<T>& Array<T>::operator[](size_t i)
{
	if (i < 0 || i >= this->len)
	{
		throw std::out_of_range("Out of bounds");
	}
}

template <typename T>
Array<T>::~Array(void)
{
	// delete[] this->array;
	// delete this->array;
}

