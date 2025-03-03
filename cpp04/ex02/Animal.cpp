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
	this->type = assign.type;
	return *this;
}

//members
void Animal::makeSound()const
{
	if (this->type == "Cat")
		std::cout << "\e[0;34mMiaou\e[0m" << std::endl;
	else if (this->type == "Dog")
		std::cout << "\e[0;34mOuaf\e[0m" << std::endl;
	else
		std::cout << "\e[0;34mStrange Noise\e[0m" << std::endl;
}
std::string Animal::getType()const
{
	return(this->type);
}