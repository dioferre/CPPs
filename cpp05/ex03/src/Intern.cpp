/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:46:31 by dioferre          #+#    #+#             */
/*   Updated: 2025/08/14 10:11:31 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern( const Intern& other ) { (void)other; }

Intern::~Intern() {}

Intern&	Intern::operator=( const Intern& other )
{
	if (this != &other) {}
	return (*this);
}


AForm*	Intern::makeForm( std::string form_name, std::string form_target )
{
	static const std::string formNames[3] = 
	{ "presidential pardon" , "robotomy request", "shrubbery creation" };
	
	static const CreateFunc formFuncs[3] = 
	{ &Intern::makePresidential, &Intern::makeRobotomy, &Intern::makeShrubbery };

	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == form_name)
		{
			std::cout << "Intern creates " << formNames[i] << std::endl;
			return ((this->*formFuncs[i])(form_target));
		}
	}
	
	std::cerr << RED << "Error: " << RESET << "Form not found!" << std::endl;
	return (NULL);
}


AForm* Intern::makePresidential( std::string& target ) const
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeRobotomy( std::string& target ) const
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makeShrubbery( std::string& target ) const
{
	return (new ShrubberyCreationForm(target));
}