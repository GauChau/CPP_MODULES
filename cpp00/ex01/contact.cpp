/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:18:53 by gchauvot          #+#    #+#             */
/*   Updated: 2025/02/04 12:35:56 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pbook.hpp"

std::string Contact::get_fname(void)
{
	return(this->fname);
}

std::string Contact::get_lname(void)
{
	return(this->lname);
}
std::string Contact::get_nickname(void)
{
	return(this->nickname);
}
std::string Contact::get_pnumber(void)
{
	return(this->pnumber);
}
std::string Contact::get_secret(void)
{
	return(this->secret);
}
void Contact::w_fname(std::string name)
{
	this->fname = name;
}
void Contact::w_lname(std::string val)
{
	this->lname = val;
}
void Contact::w_nickname(std::string val)
{
	this->nickname = val;
}
void Contact::w_pnumber(std::string val)
{
	this->pnumber = val;
}
void Contact::w_secret(std::string val)
{
	this->secret = val;
}