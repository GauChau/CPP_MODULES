#include "WrongCat.hpp"

// Constructors
WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "\e[0;33mDefault Constructor called of WrongCat\e[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of WrongCat\e[0m" << std::endl;
}


// Destructor
WrongCat::~WrongCat()
{
	std::cout << "\e[0;31mDestructor called of WrongCat\e[0m" << std::endl;
}


// Operators
WrongCat & WrongCat::operator=(const WrongCat &assign)
{
	this->type = assign.type;
	return *this;
}

// //members
void WrongCat::makeSound()
{
	std::cout << "\e[0;34mWrong Miaou\e[0m" << std::endl;
}
// const std::string WrongCat::getType() const
// {
// 	return(this->type);
// }

