/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:28:37 by dioferre          #+#    #+#             */
/*   Updated: 2025/08/13 19:08:47 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm( "unknown", 25, 5 ),
	_target("unknown") {}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) :
	AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ) :
	AForm(other.getName(), 25, 5), _target(other.getTarget()) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=
	( const PresidentialPardonForm& other )
{
	if (this != &other)
	{
		_target = other.getTarget();
		AForm::operator=(other);
	}
	return (*this);
}

void	PresidentialPardonForm::execForm() const
{
	std::cout << "I am happy to announce that " << BWHITE << _target << RESET <<
	" has been pardoned by glorious Zaphod Beeblebrox!" << std::endl;
}

std::string	PresidentialPardonForm::getTarget() const
{
	return(_target);
}