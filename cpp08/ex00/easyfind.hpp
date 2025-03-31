/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautierchauvot <gautierchauvot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:58:14 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/27 16:12:38 by gautierchau      ###   ########.fr       */
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
	return  (find(a.begin(), a.end(), b));
}

#endif