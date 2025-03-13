/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:21:34 by gchauvot          #+#    #+#             */
/*   Updated: 2025/03/13 15:57:18 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
#include "AForm.hpp"

class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		AForm* makeForm(std::string name, std::string target);

	private:

};

#endif /* ********************************************************** INTERN_H */