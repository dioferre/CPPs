/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:14:38 by dioferre          #+#    #+#             */
/*   Updated: 2025/08/12 11:47:35 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat	Ze("Ze", 150);
	Bureaucrat	Tobias("Tobias", 2);

	ShrubberyCreationForm	NDA("NDA");
	
	NDA.execForm(Tobias, "tree");
}