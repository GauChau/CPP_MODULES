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

int main(int argc, char **argv)
{
	if (argc<2)
		return 0;
	std::string sequence = joiner(argc, argv);
	std::cout<<"\e[0;36mINPUT: \e[0;31m\n" << sequence<<"\e[0m\n" << std::endl;

	Pmerge *joe= new(Pmerge);

	try
	{
		/* code */
		joe->fillseq(sequence);

		clock_t start_v = clock(), end_v;
		joe->mergelist_vector(1, joe->Get_vectored());
		end_v = clock();
		double time_elapsed_v = static_cast<double>(end_v - start_v) / CLOCKS_PER_SEC;

		clock_t start_d = clock(), end_d;
		joe->mergelist_deque(1, joe->Get_dequed());
		end_d = clock();
		double time_elapsed_d = static_cast<double>(end_d - start_d) / CLOCKS_PER_SEC;

		std::cout<<"\e[0;36mVECTOR CONTAINER RESULT: ";
		joe->issorted(joe->Get_vectored());
		std::cout<<"\e[0;33m";
		printcontainer(joe->Get_vectored());
		std::cout<<"\e[0;37mVector container sorted in: \e[0;35m"<< time_elapsed_v * 1000<<"ms";
		std::cout<<"\e[0m\n" << std::endl;

		std::cout<<"\e[0;36mDEQUE CONTAINER RESULT: ";
		joe->issorted(joe->Get_dequed());
		std::cout<<"\e[0;32m";
		printcontainer(joe->Get_dequed());
		std::cout<<"\e[0;37mDeque container sorted in: \e[0;35m"<< time_elapsed_d * 1000<<"ms";
		std::cout<<"\e[0m\n" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete joe;

	return 0;
}
//2 11 0 17 6 15 8 16 3 10 1 21 9 18 14 19 5 12 4 20 7 13