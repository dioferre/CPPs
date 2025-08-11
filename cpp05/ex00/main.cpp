/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:14:38 by dioferre          #+#    #+#             */
/*   Updated: 2025/08/11 12:23:16 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	invalidBureaucratTest(void)
{
	try
	{
		Bureaucrat	Golias("Golias", -4);
	}
	catch(const std::exception& e)
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
	catch(const std::exception& e)
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
	catch(const std::exception& e)
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

	
	std::cout << Ze << std::endl;
	std::cout << Tobias << std::endl;

	Ze = Tobias;
	std::cout << Ze << std::endl;
}