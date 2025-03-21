/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautierchauvot <gautierchauvot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:58:14 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/20 17:21:11 by gautierchau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <stdexcept>

template <typename T>
class Array
{
	public :
		Array();
		Array(unsigned int n);
		Array(Array &copy);
		Array& operator=(Array &src);
		Array& operator[](size_t i);
		~Array();
	private :
		T	*array;
		size_t len;
};
#include "Array.tpp"

#endif