/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:20:04 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/24 14:07:55 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		// Constructors
		Dog();
		Dog(const Dog &copy);

		// Destructor
		virtual ~Dog();

		// Operators
		Dog & operator=(const Dog &assign);

		// //members
		void makeSound()const;
		// std::string getType()const;
		Brain *getBrain();

	private:
		Brain *cerv;

};

#endif