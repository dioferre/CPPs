/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:14:38 by dioferre          #+#    #+#             */
/*   Updated: 2025/08/11 17:51:24 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	Ze("Ze", 150);
	Bureaucrat	Tobias("Tobias", 2);

	Form		NDA("NDA Agreement", 3, 3);
	Form		Questionario("Questionairo bonito", 150, 150);

	std::cout << NDA << std::endl;
	std::cout << Questionario << std::endl;

	Ze.signForm(Questionario);
	Ze.signForm(NDA);

	Tobias.signForm(NDA);
}