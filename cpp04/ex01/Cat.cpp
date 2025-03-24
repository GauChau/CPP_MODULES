#include "Cat.hpp"

// Constructors
Cat::Cat(): Animal()
{
	this->cerv = new Brain();
	this->type = "Cat";
	std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	*this=copy;
	std::cout << "\e[0;33mCopy Constructor called of Cat\e[0m" << std::endl;
}


// Destructor
Cat::~Cat()
{
	delete this->cerv;
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
}


// Operators
Cat & Cat::operator=(const Cat &assign)
{
	std::cout << "\e[0;33m = called of CAT\e[0m" << std::endl;
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
void Cat::makeSound() const
{
	std::cout << "\e[0;34mMiaou\e[0m" << std::endl;
}
// const std::string Cat::getType() const
// {
// 	return(this->type);
// }

Brain* Cat::getBrain()const
{
	return (this->cerv);
}

