/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbook.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:47:42 by gchauvot          #+#    #+#             */
/*   Updated: 2025/02/24 17:03:59 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PBOOK_HPP
# define PBOOK_HPP
#include <cstdlib>
#include <string>
#include <iostream>

class Contact
{
	private:
	std::string fname;
	std::string lname;
	std::string nickname;
	std::string pnumber;
	std::string secret;

	public:
	std::string get_fname();
	std::string get_lname();
	std::string get_nickname();
	std::string get_pnumber();
	std::string get_secret();

	void w_fname(std::string);
	void w_lname(std::string);
	void w_nickname(std::string);
	void w_pnumber(std::string);
	void w_secret(std::string);
};



class PhoneBook
{
	private:
		Contact array[8];
		int		i;
		int		total;
		void aligner(std::string);

	public :
		void init();
		void ADD();
		void SEARCH();
		void display(int id);
		int RUNNER(std::string);
};

// std::string get_fname(void);
// std::string get_lname(void);
// std::string get_nickname(void);
// std::string get_pnumber(void);
// std::string get_secret(void);

#endif
