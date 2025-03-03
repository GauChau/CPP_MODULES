#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>
#include "Brain.hpp"

class WrongAnimal
{
	public:
		// Constructors
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);

		// Destructor
		~WrongAnimal();

		// Operators
		WrongAnimal & operator=(const WrongAnimal &assign);
		void makeSound() const;
		std::string getType() const;

	protected :
		std::string type;

};

class WrongCat : public WrongAnimal
{
	public:
	// Constructors
		WrongCat();
		WrongCat(const WrongCat &copy);

		WrongCat & operator=(const WrongCat &assign);
	// Destructor
	~WrongCat();
};

#endif