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

static int strisfloatable(std::string &src)
{

	int point = 0;

	if(src.length() == 1)
		return (0);
    for (unsigned long i = 0; i < src.length(); i++)
	{
		if(!isdigit(src[i]))
		{
			if(i == 0 && src[i]=='-')
				continue;
			if(src[i] == '.' && i !=0 && i != src.length()-1 && !point)
			{
				point = 1;
				continue ;
			}
			if(src[i] == 'f' && i == src.length()-1)
				continue ;
			return -1;
		}
	}
	if (!point && src.c_str()[src.length()-1] == 'f')
		return (-1);
	if (point && src.c_str()[src.length()-1] == 'f')
		return (2);
	else if(point)
		return 3;
	return 1;
}
void	pchar(char c, std::string src)
{
		// char conversion
	if (c > 127 || c < 0)
		std::cout << "char : " << "impossible" << std::endl;
	else if(!isprint((int)c))
		std::cout << "char : " << "NonDisplay" << std::endl;
	else
		std::cout << "char : " << c << std::endl;
}

void pint(int i, std::string src)
{
	if(atol(src.c_str())> 2147483647 || atol(src.c_str())< -2147483648)
		std::cout << "int : overflow" << std::endl;
	else
	{
		i = atol(src.c_str());
		if (strisfloatable(src)==-1)
			std::cout << "int : " << "impossible" << std::endl;
		else
			std::cout << "int : " << i << std::endl;
	}
}

void pfloat(float f)
{
	//float conversion
	if (f == (long long)f)
	{
		std::cout << "float : " << f << ".0f"<<std::endl;
	}
	else
		std::cout << "float : " << f << "f"<<std::endl;
}

void pdouble(double d)
{
	// // double conversion

	if (d == (long long)d)
	{
		std::cout << "double : " << d << ".0"<<std::endl;
	}
	else
		std::cout << "double : " << d << std::endl;
}

static void charto(std::string src)
{
	char c = src.c_str()[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);
	std::string filler("f");
	if (f == (int)f)
		filler = ".0f";
	std::string fillerd("");
	if (d == (int)d)
		fillerd = ".0";


	// std::cout << "char : " << c << std::endl;
	// pchar(c, src);
	// std::cout << "int : " << i << std::endl;
	// std::cout << "float : " << f << filler << std::endl;
	// std::cout << "double : " << d << fillerd << std::endl;
	pchar(c,src);
	pint(i, src);
	pfloat(f);
	pdouble(d);

}

static void intto(std::string src)
{
	if(atol(src.c_str())> 2147483647 || atol(src.c_str())< -2147483648)
	{
		std::cout << "int : overflow" << std::endl;
		return ;
	}

	int i = atol(src.c_str());

	char c = static_cast<char>(i);
	float f = static_cast<float>(i);;
	double d = static_cast<double>(i);
	std::string filler("f");
	if (f == (int)f)
		filler = ".0f";
	std::string fillerd("");
	if (d == (int)d)
		fillerd = ".0";

	// std::cout << "char : " << c << std::endl;
	// pchar(c, src);
	// std::cout << "int : " << i << std::endl;
	// std::cout << "float : " << f << filler << std::endl;
	// std::cout << "double : " << d << fillerd<< std::endl;
	pchar(c,src);
	pint(i, src);
	pfloat(f);
	pdouble(d);
}

static void floatto(std::string src)
{
	float f = atof(src.c_str());

	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);
	std::string filler("f");
	if (f == (int)f)
		filler = ".0f";
	std::string fillerd("");
	if (d == (int)d)
		fillerd = ".0";

	// std::cout << "char : " << c << std::endl;
	// pchar(c, src);
	// std::cout << "int : " << i << std::endl;
	// std::cout << "float : " << f << filler << std::endl;
	// std::cout << "double : " << d << fillerd << std::endl;
	pchar(c,src);
	pint(i, src);
	pfloat(f);
	pdouble(d);

}

static void doubleto(std::string src)
{
	double d = atof(src.c_str());

	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<double>(d);
	std::string filler("f");
	if (f == (int)f)
		filler = ".0f";
	std::string fillerd("");
	if (d == (int)d)
		fillerd = ".0";

	// std::cout << "char : " << c << std::endl;
	// pchar(c, src);
	// std::cout << "int : " << i << std::endl;
	// std::cout << "float : " << f << filler  << std::endl;
	// std::cout << "double : " << d<< fillerd << std::endl;
	pchar(c,src);
	pint(i, src);
	pfloat(f);
	pdouble(d);

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

	std::cout << "type detector : "<< strisfloatable(src) << std::endl;

	int chose = strisfloatable(src);

	if(chose == 0)
		charto(src);
	else if (chose == 1)
		intto(src);
	else if (chose == 2)
		floatto(src);
	else if (chose == 3)
		doubleto(src);
	else if (chose == -1)
	{
		std::cout << "char : " << impossible << std::endl;
		std::cout << "int : " << impossible << std::endl;
		std::cout << "float : " << nan + 'f' << std::endl;
		std::cout << "double : " << nan << std::endl;
	}
	// // char conversion
	// c = (char)atol(src.c_str());
	// if (strisfloatable(src)==-1 || (c > 127 || c < 0) || src.length() > 3)
	// 	std::cout << "char : " << impossible << std::endl;
	// else if(!isprint((int)c))
	// 	std::cout << "char : " << NonDisplay << std::endl;
	// else
	// 	std::cout << "char : " << c << std::endl;

	// //int conversion
	// if(atol(src.c_str())> 2147483647 || atol(src.c_str())< -2147483648)
	// 	std::cout << "int : overflow" << std::endl;
	// else
	// {
	// 	i = atol(src.c_str());
	// 	if (strisfloatable(src)==-1)
	// 		std::cout << "int : " << impossible << std::endl;
	// 	else
	// 		std::cout << "int : " << i << std::endl;
	// }


	// //float conversion
	// f = atof(src.c_str());
	// if (strisfloatable(src)==-1)
	// 	std::cout << "float : " << nan << "f"<<std::endl;
	// else if (f == (long long)f)
	// {
	// 	std::cout << "float : " << f << ".0f"<<std::endl;
	// }
	// else
	// 	std::cout << "float : " << f << "f"<<std::endl;


	// // double conversion
	// d = atof(src.c_str());
	// if (strisfloatable(src)==-1)
	// 	std::cout << "double : " << nan << std::endl;
	// else if (d == (long long)d)
	// {
	// 	std::cout << "double : " << d << ".0"<<std::endl;
	// }
	// else
	// 	std::cout << "double : " << d << std::endl;
	std::cout << "---------------------------------------" << std::endl;

	std::string lol= "45666"; lol.data();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */