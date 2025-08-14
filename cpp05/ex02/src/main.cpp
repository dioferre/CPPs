/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:14:38 by dioferre          #+#    #+#             */
/*   Updated: 2025/08/14 10:20:04 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <unistd.h>

int	main(void)
{
	Bureaucrat	Ze("Ze", 150);
	Bureaucrat	Tobias("Tobias", 2);

	ShrubberyCreationForm	SCF("Rodrigo");
	RobotomyRequestForm		RRF("Zacarias");
	PresidentialPardonForm	PPM("Ze Diabo");
	
	// Testing executing form without signing
	Tobias.executeForm(SCF);

	// Testing if form works properly
	Tobias.signForm(SCF);
	Tobias.executeForm(SCF);

	Tobias.signForm(RRF);

	// Testing if form really has around 50% chance of failing
	size_t	number_of_tries = 3;
	for (size_t i = 0; i < number_of_tries; i++)
	{
		Tobias.executeForm(RRF);
	}

	// Testing last form as well as permission.
	Ze.signForm(PPM);
	Tobias.signForm(PPM);
	Tobias.executeForm(PPM);	
}