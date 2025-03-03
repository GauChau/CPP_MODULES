#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	public:
		// Constructors
		Brain();
		Brain(const Brain &copy);

		// Destructor
		virtual ~Brain();

		// Operators
		Brain & operator=(const Brain &assign);
		void setIdeas(unsigned int index, std::string content);

	protected :
		const static unsigned int _nbIdeas = 100;
		std::string ideas[_nbIdeas];

};

#endif