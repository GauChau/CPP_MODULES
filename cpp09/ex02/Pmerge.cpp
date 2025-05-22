/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmerge.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:52:38 by gchauvot          #+#    #+#             */
/*   Updated: 2025/05/21 13:52:38 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>


long _jacobsthal_number(long n)
{
	return round((pow(2, n + 1) + pow(-1, n)) / 3);
}
long next_jack(long n)
{
	int prev =0;

	int res=0;
	for(int i=0;res<n;i++)
	{
		prev = res;
		res = _jacobsthal_number(i);
	}
	return(prev);
}

static int isstrdigit_spc(std::string str)
{
	std::string::iterator iter = str.begin();
	while(iter != str.end())
	{
		if(*iter != 0 && (!std::isdigit(*iter) && !std::isspace(*iter)))
			return 0;
		iter++;
	}
	return 1;
}

void Pmerge::fillseq(std::string input)
{
	std::stringstream s_input(input);
	std::string buffer;
	int x, i = 0;

	if (!isstrdigit_spc(input))
		throw BadInput();

	while (std::getline(s_input, buffer, ' '))
	{
		x = std::atol(buffer.c_str());
		this->_vectored.push_back(x);
		this->_dequed.push_back(x);
		i++;
	}
	this->_n = i;
}

std::vector<int>& Pmerge::Get_vectored(void)
{
	return(this->_vectored);
}
std::deque<int>& Pmerge::Get_dequed(void)
{
	return(this->_dequed);
}

void Pmerge::mergelist_vector(int level, std::vector<int> &seq)
{
	size_t pairsize = pow(2,level-1), unit_nbr = seq.size() / pairsize;
	size_t impair = (unit_nbr %2);
	size_t x;
	std::vector<int>::iterator a, b;

	////////////////////////////////////////
	//APPAIRAGE DES CHIFFRES, EN RECURSION
	////////////////////////////////////////
	if (unit_nbr < 2)
		return ;
	a = seq.begin();
	b = a;
	std::advance(a, 2*pairsize-1);
	std::advance(b, pairsize-1);
	for (x = 0; x < unit_nbr /2;x++)
	{
		if (*a < *b)
			swap_pair(seq, b, a, pairsize);
		std::advance(a, pairsize*2);
		std::advance(b, pairsize*2);
	}

	mergelist_vector(level+1, seq); //RECURSION

	////////////////////////////////////////////////////////////////////////////////////////////////////
	//REMPLISSAGE DES MAIN, PEND ET REST
	//MAIN: TOUS LES MAX DES PAIRS + LE MIN DU PLUS PETIT MAX
	//PEND: LE RESTE DES MIN
	//REST: LES CHIFFRES RESTANT NE POUVANT CONSTITUER UN BLOCK CAR PAS ASSEZ DE CHIFFRES RESTANTS
	////////////////////////////////////////////////////////////////////////////////////////////////////
	a = seq.begin();
	b = a;
	std::advance(a, 2*pairsize-1);
	std::advance(b, pairsize-1);
	std::vector<std::vector<int>::iterator> main, pend, rest;
	main.insert(main.end(), b);
	main.insert(main.end(), a);

	for (size_t i =0;i<((unit_nbr-2)/2);i++)
	{
		std::advance(b, pairsize*2);
		pend.insert(pend.end(), b);
		std::advance(a, pairsize*2);
		main.insert(main.end(), a);
	}
	if(impair)
	{
		std::advance(b, pairsize*2);
		pend.insert(pend.end(), b);
		a = b;
	}
	for (std::advance(a, 1);a!=seq.end();std::advance(a, 1))
	{
		rest.insert(rest.end(), a);
	}

	////////////////////////////////////////////////////////////
	//INSERTION DU PEND DANS MAIN SUIVANT LA SUITE DE JACOBSTHAL
	////////////////////////////////////////////////////////////
	size_t jackval = 1, prevjack = 1;
	for(size_t k = 1, x = 0;x<pend.size(); k++, prevjack=jackval, jackval=_jacobsthal_number(k))
	{
		std::vector<std::vector<int>::iterator>::iterator insert_point, topush = pend.begin();

		for(size_t y = jackval; y > prevjack; y-=1)
		{
			topush = pend.begin();
			if (y-2<pend.size())
				std::advance(topush, y-2);
			else
			{
				topush = pend.end();
				std::advance(topush, -(pend.size()-x));
			}
			if (topush!=pend.end())
			{
				insert_point = std::upper_bound(main.begin(), main.end(), *topush, _compare<std::vector<int>::iterator>);
				main.insert(insert_point, *topush);
				x++;
				if (topush==pend.begin() || x>=pend.size())
					break ;
			}
		}
	}

	////////////////////////////////////////
	//MISE A JOUR DE LA SEQUENCE INITIALE
	////////////////////////////////////////
	std::vector<std::vector<int>::iterator>::iterator insert_point = main.begin();
	std::vector<int> result;
	for(size_t y =0;y<unit_nbr; y++)
	{
		if(insert_point==main.end())
			break;
		insertblock(pairsize,*insert_point,result);
		std::advance(insert_point, 1);
	}
	insert_point=rest.begin();
	for(;rest.size()>0;)
	{
		if(insert_point==rest.end())
			break;
		result.insert(result.end(),**insert_point);
		std::advance(insert_point, 1);
	}
	seq.clear();
	seq = result;
	// std::cout<< "resULTt VECTORED: ";
	// printlist(result, pairsize, unit_nbr);
}

void Pmerge::mergelist_deque(int level, std::deque<int> &seq)
{
	size_t pairsize = pow(2,level-1), unit_nbr = seq.size() / pairsize, x;
	size_t impair = (unit_nbr %2);
	std::deque<int>::iterator a, b;

	//////////////////////////////////////////////////////////////////////////
	//APPAIRAGE DES CHIFFRES, EN RECURSION
	//COMPARE DEUX CHIFFRES. SWAP LE BLOCK DE PAIRE SI GAUCHE < DROITE
	//////////////////////////////////////////////////////////////////////////
	if (unit_nbr < 2)
		return ;
	a = seq.begin();
	b = a;
	std::advance(a, 2*pairsize-1);
	std::advance(b, pairsize-1);

	for (x =0; x < unit_nbr /2;x++)
	{
		if (*a < *b)
			swap_pair(seq, b, a, pairsize);
		std::advance(a, pairsize*2);
		std::advance(b, pairsize*2);
	}
	mergelist_deque(level+1, seq);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	//REMPLISSAGE DES MAIN, PEND ET REST
	//MAIN: TOUS LES MAX DES PAIRS + LE MIN DU PLUS PETIT MAX
	//PEND: LE RESTE DES MIN
	//REST: LES CHIFFRES RESTANT NE POUVANT CONSTITUER UN BLOCK CAR PAS ASSEZ DE CHIFFRES RESTANTS
	////////////////////////////////////////////////////////////////////////////////////////////////////
	a = seq.begin();
	b = a;
	std::advance(a, 2*pairsize-1);
	std::advance(b, pairsize-1);
	std::deque<std::deque<int>::iterator> main, pend, rest;
	main.insert(main.end(), b);
	main.insert(main.end(), a);

	for (size_t i =0;i<((unit_nbr-2)/2);i++)
	{
		std::advance(b, pairsize*2);
		pend.insert(pend.end(), b);
		std::advance(a, pairsize*2);
		main.insert(main.end(), a);
	}
	if(impair)
	{
		std::advance(b, pairsize*2);
		pend.insert(pend.end(), b);
		a = b;
	}
	for (std::advance(a, 1);a!=seq.end();std::advance(a, 1))
		rest.insert(rest.end(), a);

	////////////////////////////////////////////////////////////////////////////////////
	//INSERTION DU PEND DANS MAIN SUIVANT LA SUITE DE JACOBSTHAL
	//insertion utilisant un binary search avec la fonction upperbound
	////////////////////////////////////////////////////////////////////////////////////
	size_t jackval = 1, prevjack = 1;
	for(size_t k = 1, x = 0;x<pend.size(); k++, prevjack=jackval, jackval=_jacobsthal_number(k))
	{
		std::deque<std::deque<int>::iterator>::iterator insert_point, topush = pend.begin();

		for(size_t y = jackval; y > prevjack; y-=1)
		{
			topush = pend.begin();
			if (y-2<pend.size())
				std::advance(topush, y-2);
			else
			{
				topush = pend.end();
				std::advance(topush, -(pend.size()-x));
			}
			if (topush!=pend.end())
			{
				insert_point = std::upper_bound(main.begin(), main.end(), *topush, _compare<std::deque<int>::iterator>);
				main.insert(insert_point, *topush);
				x++;
				if (topush==pend.begin() || x>=pend.size())
					break ;
			}
		}
	}

	////////////////////////////////////////
	//MISE A JOUR DE LA SEQUENCE INITIALE
	////////////////////////////////////////
	std::deque<std::deque<int>::iterator>::iterator insert_point = main.begin();
	std::deque<int> result;
	for(size_t y =0;y<unit_nbr; y++)
	{
		if(insert_point==main.end())
			break;
		insertblock(pairsize,*insert_point,result);
		std::advance(insert_point, 1);

	}
	insert_point=rest.begin();
	for(;rest.size()>0;)
	{
		if(insert_point==rest.end())
			break;
		result.insert(result.end(),**insert_point);
		std::advance(insert_point, 1);

	}
	seq.clear();
	seq = result;
}

// Constructors
Pmerge::Pmerge()
{
}

Pmerge::Pmerge(const Pmerge &copy)
{
	*this = copy;
}

// Destructor
Pmerge::~Pmerge()
{
}

// Operators
Pmerge & Pmerge::operator=(const Pmerge &assign)
{
	this->_dequed = assign._dequed;
	this->_vectored = assign._vectored;
	return *this;
}

// Exceptions
const char * Pmerge::BadInput::what() const throw()
{
	return "Pmerge: Bad Input";
}

const char * Pmerge::SortingFailed::what() const throw()
{
	return "\e[0;31mFAILED\e[0m";
}




