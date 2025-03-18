#include "ScalarConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter()
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScalarConverter::~ScalarConverter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/



/*
** --------------------------------- METHODS ----------------------------------
*/

static int strisnum(std::string &src)
{
    for (unsigned long i = 0; i < src.length(); i++)
	{
		if(!isdigit(src[i]))
			return 0;
	}
	return 1;
}

static int strisprint(std::string &src)
{
    for (unsigned long i = 0; i < src.length(); i++)
	{
		if(!isprint(src[i]))
			return 0;
	}
	return 1;
}

// static int strisprint(std::string &src)
// {
//     for (unsigned long i = 0; i < src.length(); i++)
// 	{
// 		if(!isprint(src[i]))
// 			return 0;
// 	}
// 	return 1;
// }

static int strisfloatable(std::string &src)
{

	int point = 0;

    for (unsigned long i = 0; i < src.length(); i++)
	{
		if(!isdigit(src[i]))
		{
			if(i ==0 && src[i]=='-')
				continue;
			if(src[i] == '.' && i !=0 && i != src.length()-1 && !point)
			{
				point = 1;
				continue ;
			}
			if(src[i] == 'f' && i == src.length()-1)
				continue ;
			return 0;
		}
	}
	return 1;
}

void ScalarConverter::convert(std::string src)
{

	int i;
	double d;
	int i_c;
	char c;
	float f;

	std::string impossible("impossible");
	std::string nan("nan");
	std::string NonDisplay("Non displayable");

	// char conversion
	c = (char)atol(src.c_str());
	if (!strisfloatable(src) || (c > 127 || c < 0) || src.length() > 3)
		std::cout << "char : " << impossible << std::endl;
	else if(!isprint((int)c))
		std::cout << "char : " << NonDisplay << std::endl;
	else
		std::cout << "char : " << c << std::endl;

	//int conversion
	if(atol(src.c_str())> 2147483647 || atol(src.c_str())< -2147483648)
		std::cout << "int : overflow" << std::endl;
	else
	{
		i = atol(src.c_str());
		if (!strisfloatable(src))
			std::cout << "int : " << impossible << std::endl;
		else
			std::cout << "int : " << i << std::endl;
	}


	//float conversion
	f = atof(src.c_str());
	if (!strisfloatable(src))
		std::cout << "float : " << nan << "f"<<std::endl;
	else if (f == (long long)f)
	{
		std::cout << "float : " << f << ".0f"<<std::endl;
	}
	else
		std::cout << "float : " << f << "f"<<std::endl;


	// double conversion
	d = atof(src.c_str());
	if (!strisfloatable(src))
		std::cout << "double : " << nan << std::endl;
	else if (d == (long long)d)
	{
		std::cout << "double : " << d << ".0"<<std::endl;
	}
	else
		std::cout << "double : " << d << std::endl;
	std::cout << "---------------------------------------" << std::endl;

	std::string lol= "45666"; lol.data();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */