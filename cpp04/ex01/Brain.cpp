#include "Brain.hpp"

// Constructors
Brain::Brain()
{
	std::cout << "\e[0;33mDefault Constructor called of Brain\e[0m" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	// *this->ideas = *copy.ideas;
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of Brain\e[0m" << std::endl;
}


// Destructor
Brain::~Brain()
{
	std::cout << "\e[0;31mDestructor called of Brain\e[0m" << std::endl;
}


// Operators
Brain & Brain::operator=(const Brain &assign)
{
	for(unsigned int i = 0; i < this->_nbIdeas; i++)
	{
		if (assign.ideas[i].length()>0)
			this->ideas[i].assign(assign.ideas[i]);
	}
	return *this;
}

void Brain::setIdeas(unsigned int index, std::string content)
{
	if (index < this->_nbIdeas)
	{
		this->ideas[index].assign(content);
	}
}

