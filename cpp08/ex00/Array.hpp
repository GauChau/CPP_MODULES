/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:58:14 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/27 12:26:18 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <cstddef>

template <typename T>
class Array
{
	public :
		Array();
		Array(unsigned int n);
		Array(Array &copy);
		Array& operator=(const Array &src);
		T& operator[](unsigned int i);
		~Array();

		unsigned int size(void);
	private :
		T	*array;
		unsigned int len;
};
#include "Array.tpp"

#endif