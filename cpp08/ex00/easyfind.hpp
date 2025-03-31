/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:58:14 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/31 15:10:11 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

# include <iostream>
# include <string>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <cstddef>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &a, int b)
{
	typename T::iterator res;

	res = find(a.begin(), a.end(), b);
	if(res == a.end())
	{
		std::cerr << b << ": ";
		throw std::out_of_range("value not found.");
		// std::cout << "target not found" << std::endl;
		// return (0);
	}
	return res;
}

#endif