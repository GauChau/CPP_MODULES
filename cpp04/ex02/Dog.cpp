#include "Dog.hpp"

// Constructors
Dog::Dog()
{
	this->cerv = new Brain();
	this->type = "Dog";
	std::cout << "\e[0;33mDefault Constructor called of Dog\e[0m" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	this->type = copy.type;
	std::cout << "\e[0;33mCopy Constructor called of Dog\e[0m" << std::endl;
}


// Destructor
Dog::~Dog()
{
	delete this->cerv;
	std::cout << "\e[0;31mDestructor called of Dog\e[0m" << std::endl;
}


// Operators
Dog & Dog::operator=(const Dog &assign)
{
	if(this != &assign)
	{
		this->cerv = new Brain(*assign.cerv);
	}
	return *this;
}

// //members
// void Dog::makeSound()const
// {
// 	std::cout << "\e[0;34mOuaf.\e[0m" << std::endl;
// }
// std::string Dog::getType()const
// {
// 	return(this->type);
// }

