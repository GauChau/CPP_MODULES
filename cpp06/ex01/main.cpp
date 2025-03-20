/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:41:47 by gautierchau       #+#    #+#             */
/*   Updated: 2025/03/20 10:55:58 by gchauvot         ###   ########.fr       */
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
    std::cout << "Deserialized : " << deserialized->data
              << std::endl;

    // Ensure it's the same pointer
    if (deserialized == &myData) {
        std::cout << "Success!" << std::endl;
    } else {
        std::cout << "Error! " << std::endl;
    }

    return 0;
}