#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
#include "data.hpp"

class Serializer
{

	public:

		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);

	private:

};


#endif /* ****************************************************** SERIALIZER_H */