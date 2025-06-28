/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:58:56 by dioferre          #+#    #+#             */
/*   Updated: 2025/05/09 18:14:00 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

// ====================== Getters ======================

std::string Contact::get_first_name() const
{
	return (this->_first_name);
}

std::string Contact::get_last_name() const
{
	return (this->_last_name);
}

std::string Contact::get_nickname() const
{
	return (this->_nickname);
}

std::string Contact::get_secret() const
{
	return (this->_secret);
}

std::string Contact::get_phone_number() const
{
	return (this->_phone_number);
}


// ====================== Setters ======================

void	Contact::set_first_name(std::string arg)
{
	this->_first_name = arg;
}

void	Contact::set_last_name(std::string arg)
{
	this->_last_name = arg;
}

void	Contact::set_nickname(std::string arg)
{
	this->_nickname = arg;
}

void	Contact::set_secret(std::string arg)
{
	this->_secret = arg;
}

void	Contact::set_phone_number(std::string arg)
{
	this->_phone_number = arg;
}
