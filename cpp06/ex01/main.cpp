/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautierchauvot <gautierchauvot@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:41:47 by gautierchau       #+#    #+#             */
/*   Updated: 2025/03/18 18:42:59 by gautierchau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"
#include "Serializer.hpp"

int main() 
{
    Data myData = {42};
    
    // Serialize
    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "Serialized: " << raw << std::endl;
    
    // Deserialize
    Data* deserialized = Serializer::deserialize(raw);
    std::cout << "Deserialized value: " << deserialized->data 
              << std::endl;

    // Ensure it's the same pointer
    if (deserialized == &myData) {
        std::cout << "Success! Pointers match." << std::endl;
    } else {
        std::cout << "Error! Pointers do not match." << std::endl;
    }

    return 0;
}