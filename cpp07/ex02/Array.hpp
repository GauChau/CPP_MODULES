/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:58:14 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/20 14:56:28 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
#include <fstream>
#include <filesystem>
#include <cstdlib>

template <typename T>
class Array
{
	public :
		Array();
		Array(unsigned int n);
		Array(Array &copy);
		Array& operator=(Array &src);
		~Array();
	private :
		T	*array;
		size_t len;
};
#include "Array.tpp"

#endif