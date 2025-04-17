/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:47:12 by marvin            #+#    #+#             */
/*   Updated: 2025/04/17 17:47:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pmerge.hpp"

std::string joiner(int argc, char **argv)
{
	std::string res;

	for (int i = 1; i < argc; i++)
	{
		res+= argv[i];
		res +=" ";
	}
	return res;
}

int main(int argc, char **argv)
{
	if (argc<2)
		return 0;

	std::string sequence = joiner(argc, argv);
	std::cout << sequence << std::endl;


	Pmerge *joe= new(Pmerge);
	
	joe->fillseq(sequence);
	std::cout <<"fillseq size: "<< sequence.size()<< std::endl;
	joe->mergelist((joe->_listed)->size(),*joe->_listed);
	return 0;
}