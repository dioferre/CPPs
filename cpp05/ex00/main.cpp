/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:14:38 by dioferre          #+#    #+#             */
/*   Updated: 2025/08/14 10:25:53 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	invalidBureaucratTest(void)
{
	try
	{
		Bureaucrat	Golias("Golias", -4);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	gradeTooHighTest(Bureaucrat& b)
{
	try
	{
		b.incrementGrade(), b.incrementGrade();
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	gradeTooLowTest(Bureaucrat& b)
{
	try
	{
		b.decrementGrade();
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
}


int	main(void)
{
	Bureaucrat	Ze("Ze", 150);
	Bureaucrat	Tobias("Tobias", 2);

	invalidBureaucratTest();
	gradeTooHighTest(Tobias);
	gradeTooLowTest(Ze);

	// Testing '<<' overload operator
	std::cout << Ze << std::endl;
	std::cout << Tobias << std::endl;

	// Testing copy assignment operator
	Ze = Tobias;
	std::cout << Ze << std::endl;
}