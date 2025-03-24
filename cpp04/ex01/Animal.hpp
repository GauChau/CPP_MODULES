/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:20:14 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/24 14:36:49 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
#include "Brain.hpp"

class Animal
{
	private:
	public:
		// Constructors
		Animal();
		Animal(const Animal &copy);

		// Destructor
		virtual ~Animal();

		// Operators
		Animal & operator=(const Animal &assign);

		//members
		virtual void makeSound() const;
		virtual std::string getType() const;

	protected :
		std::string type;

};

#endif