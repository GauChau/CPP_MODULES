/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:21:32 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/14 18:04:54 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main()
{
	ScalarConverter uno;
	uno.convert("100");
	uno.convert("-0");
	uno.convert("aaasd");
	uno.convert("*");
	uno.convert("-1");
	uno.convert("43999999999999999999999999999999.9996f");

	// float inf_value = std::numeric_limits<float>::infinity();  // Positive infinity
	float inf_value = 999.0;
    std::cout << "Positive infinity: " << inf_value << std::endl;

    // Negative Infinity
    float neg_inf_value = -std::numeric_limits<float>::infinity();  // Negative infinity
    std::cout << "Negative infinity: " << neg_inf_value << std::endl;

    // NaN
    float nan_value = std::numeric_limits<float>::quiet_NaN();  // NaN
    std::cout << "NaN value: " << nan_value << std::endl;
}