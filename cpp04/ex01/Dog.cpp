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
	*this = copy;
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
	std::cout << "\e[0;33m = called of DOG\e[0m" << std::endl;
	this->type = assign.type;
	if(this != &assign)
	{
		if(this->cerv)
			delete this->cerv;
		this->cerv = new Brain(*assign.cerv);
	}
	return *this;
}

// //members
void Dog::makeSound()const
{
	std::cout << "\e[0;34mOuaf.\e[0m" << std::endl;
}
// std::string Dog::getType()const
// {
// 	return(this->type);
// }

Brain *Dog::getBrain()
{
	return this->cerv;
}

