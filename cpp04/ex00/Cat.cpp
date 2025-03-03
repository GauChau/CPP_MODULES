#include "Cat.hpp"

// Constructors
Cat::Cat()
{
	this->type = "Cat";
	std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of Cat\e[0m" << std::endl;
}


// Destructor
Cat::~Cat()
{
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
}


// Operators
Cat & Cat::operator=(const Cat &assign)
{
	this->type = assign.type;
	return *this;
}

// //members
// void Cat::makeSound()
// {
// 	std::cout << "\e[0;34mMiaou\e[0m" << std::endl;
// }
// const std::string Cat::getType() const
// {
// 	return(this->type);
// }

