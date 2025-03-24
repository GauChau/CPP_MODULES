/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:20:19 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/24 12:27:39 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		// Constructors
		Cat();
		Cat(const Cat &copy);

		// Destructor
		virtual ~Cat();

		// Operators
		Cat & operator=(const Cat &assign);

		// //members
		void makeSound() const;
		// const std::string getType()const;
		Brain *getBrain()const;
	private:
		Brain *cerv;

};

#endif