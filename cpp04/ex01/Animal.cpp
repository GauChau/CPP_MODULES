#include "Animal.hpp"

// Constructors
Animal::Animal()
{
	this->type = "Undefined";
	std::cout << "\e[0;33mDefault Constructor called of Animal\e[0m" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	this->type = copy.type;
	std::cout << "\e[0;33mCopy Constructor called of Animal\e[0m" << std::endl;
}


// Destructor
Animal::~Animal()
{
	std::cout << "\e[0;31mDestructor called of Animal\e[0m" << std::endl;
}


// Operators
Animal & Animal::operator=(const Animal &assign)
{
	std::cout << "\e[0;33m = called of ANIMAL\e[0m" << std::endl;
	this->type = assign.type;
	return *this;
}

//members
void Animal::makeSound()const
{
	std::cout << "\e[0;34mStrange Noise\e[0m" << std::endl;
}
std::string Animal::getType()const
{
	return(this->type);
}