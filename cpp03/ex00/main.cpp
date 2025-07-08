/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 09:36:05 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/08 09:48:16 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	subject1("subject 1");
	ClapTrap	subject2("subject 2");

	std::cout << std::endl;
	std::cout << BWHITE;
	subject1.attack(subject2.getName());
	
	subject2.takeDamage(3);
	
	subject2.beRepaired(3);
	std::cout << RESET;
	std::cout << std::endl;
}