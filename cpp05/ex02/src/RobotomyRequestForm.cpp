/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:28:43 by dioferre          #+#    #+#             */
/*   Updated: 2025/08/13 19:09:42 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm( "unknown", 72, 45 ), _target("unknown") 
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) :
	AForm("RobotomyRequestForm", 72, 45), _target(target) 
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ) :
	AForm(other.getName(), 72, 45), _target(other.getTarget())
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm() {}


RobotomyRequestForm& RobotomyRequestForm::operator=
	( const RobotomyRequestForm& other )
{
	if (this != &other)
	{
		_target = other.getTarget();
		AForm::operator=(other);
	}
	return (*this);
}

void	RobotomyRequestForm::execForm() const
{
	int random = rand() % 100;

	std::cout << BWHITE << "* BRRRRRRRRRRRRRRRRR *" << RESET << std::endl;
	if (random % 2)
	{
		std::cout << GREEN << _target << " robotomized successfully!" << RESET << std::endl;
	}
	else
	{
		std::cout << RED << "Robotomy failed :c" << RESET << std::endl;
	}
}

std::string	RobotomyRequestForm::getTarget() const
{
	return(_target);
}