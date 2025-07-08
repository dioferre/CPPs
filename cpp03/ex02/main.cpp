/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 09:56:35 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/08 09:57:17 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ScavTrap subject1("Camelo");
	ClapTrap subject2("Abutre");
	FragTrap subject3("Papas de Sarrabulho");

	std::cout << std::endl;
	subject1.guardGate();
	subject1.attack("Albatroz");

	subject2.attack("Suricata");
	
	subject3.attack("Albatroz");
	subject3.highFivesGuys();
	std::cout << std::endl;

	return (0);
}