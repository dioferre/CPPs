/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:14:38 by dioferre          #+#    #+#             */
/*   Updated: 2025/08/14 10:17:56 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#include <unistd.h>


int	main(void)
{
	Bureaucrat	Tobias("Tobias", 1);
	Bureaucrat	Zacarias("Zacarias", 150);

	Intern someRandomIntern;
	AForm* rrf;
	AForm* wrong;

	// checking makeForm
	rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
	
	// checking makeForm error
	wrong = someRandomIntern.makeForm("a", "b");

	// checking if form made is working as intended
	Zacarias.signForm(*rrf);
	Zacarias.executeForm(*rrf);

	Tobias.signForm(*rrf);
	Tobias.executeForm(*rrf);

	delete(rrf);
}