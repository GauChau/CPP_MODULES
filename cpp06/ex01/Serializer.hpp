#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
#include "data.hpp"

class Serializer
{

	public:

		Serializer();
		Serializer( Serializer const & src );
		~Serializer();

		Serializer &		operator=( Serializer const & rhs );
		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);

	private:

};

std::ostream &			operator<<( std::ostream & o, Serializer const & i );

#endif /* ****************************************************** SERIALIZER_H */