#include "Serializer.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Serializer::Serializer()
{
}

Serializer::Serializer( const Serializer & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Serializer::~Serializer()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Serializer &				Serializer::operator=( Serializer const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Serializer const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

	uintptr_t Serializer::serialize(Data *ptr)
	{
		return(ptr->value);
	}

	Data* Serializer::deserialize(uintptr_t raw)
	{
		Data *res = new Data;
		res->value = raw;
		return (res);
	}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */