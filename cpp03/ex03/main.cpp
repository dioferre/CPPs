/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:32:15 by dioferre          #+#    #+#             */
/*   Updated: 2025/06/28 15:16:18 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


int	main(void)
{
	ScavTrap subject1("Camelo");
	ClapTrap subject2("Abutre");
	FragTrap subject3("Papas de Sarrabulho");
	DiamondTrap subject4("ola123");

	subject1.guardGate();
	subject1.attack("Albatroz");

	subject2.attack("Suricata");
	
	subject3.attack("Albatroz");
	subject3.highFivesGuys();

	subject4.whoAmI();

	std::cout << "Subject 4 Attributes:\n";
	std::cout << "HP: " << subject4.getHP();
	std::cout << "\nEP: " << subject4.getEP();
	std::cout << "\nAD: " << subject4.getAD();
	std::cout << std::endl;
	
	return (0);
}