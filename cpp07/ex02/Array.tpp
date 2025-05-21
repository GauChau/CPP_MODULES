/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:21:42 by gchauvot          #+#    #+#             */
/*   Updated: 2025/05/21 17:58:06 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include "Array.hpp"


template <typename T>
Array<T>::Array(void): len(0)
{
	this->array =NULL;
}

template <typename T>
Array<T>::Array(unsigned int n) : len(n)
{
	this->array = new T[n];
}

template <typename T>
Array<T>::Array(Array &copy)
{
	this->array = NULL;
	*this = copy;
}

template <typename T>
 Array<T>& Array<T>::operator=(const Array &src)
{
	if (this->array != NULL)
		delete[] this->array;
	this->len = src.len;
	this->array = new T[this->len];
	for (unsigned int i = 0; i < len; i++)
	{
		this->array[i] = src.array[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= this->len)
	{
		throw std::out_of_range("array<T> operator[]: Out of bounds");
	}
	return this->array[i];
}

template <typename T>
unsigned int Array<T>::size()
{
	return this->len;
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] this->array;
	// delete this->array;
}

