/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:39:59 by gchauvot          #+#    #+#             */
/*   Updated: 2025/02/17 16:10:58 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	protected:

		std::string _Name;
		unsigned int _Hp;
		unsigned int _Ep;
		unsigned int _Ad;


	public:
		// Constructors
		ClapTrap();
		ClapTrap(std::string const Name);
		ClapTrap(std::string const Name, unsigned int _Hp, unsigned int _Ep, unsigned int _Ad);
		ClapTrap(const ClapTrap &copy);

		// Destructor
		~ClapTrap();

		// Operators
		ClapTrap & operator=(const ClapTrap &assign);

		//functions
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		unsigned int get_Ad(void)const;
		unsigned int get_Hp(void)const;
		unsigned int get_Ep(void)const;
		std::string get_Name(void)const;



};

#endif