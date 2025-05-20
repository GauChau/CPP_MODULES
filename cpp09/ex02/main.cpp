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

int highestPowerof2(int n)
{
    int res = 0;
    for (int i = n; i >= 1; i--) {
        // If i is a power of 2
        if ((i & (i - 1)) == 0) {
            res = i;
            break;
        }
    }
    return res;
}
template <typename T, typename U>
void printlist(T joe, int size, int unit_nbr);

int main(int argc, char **argv)
{
	if (argc<2)
		return 0;

	std::string sequence = joiner(argc, argv);
	std::cout << sequence << std::endl;


	Pmerge *joe= new(Pmerge);
	Pmerge *test= new(Pmerge);

	joe->fillseq(sequence);
	test->fillseq(sequence);
	// test->_listed->sort();
	std::cout <<"fillseq size: "<< sequence.size()<< std::endl;

	joe->mergelist(1, *joe->_listed);
	printlist(*joe->_listed,joe->_listed->size(), 1);
	std::cout<<"test: "<<std::endl;
	printlist(*test->_listed,test->_listed->size(), 1);

	return 0;
}
//2 11 0 17 6 15 8 16 3 10 1 21 9 18 14 19 5 12 4 20 7 13