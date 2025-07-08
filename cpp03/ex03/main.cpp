/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:32:15 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/08 11:18:20 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void printHeader(const std::string& header)
{
	const int	totalWidth = 50;
	int			dashCount = (totalWidth - header.size() - 2) / 2; // 2 for spaces
	int			oddFactor = (totalWidth - header.size() - 2) % 2; // Fix in case the result is an odd number
	
	std::cout << std::string(dashCount, '-') << " " << header << " "
				<< std::string(dashCount + oddFactor, '-') << std::endl;
}

int	main(void)
{
	// Construction
	printHeader("Construction Logs");
	ScavTrap _scav("Camelo");
	ClapTrap _clap("Abutre");
	FragTrap _frag("Papas de Sarrabulho");
	DiamondTrap _diamond("ola123");
	std::cout << std::endl;

	// First Tests
	printHeader("First Tests");
	_scav.guardGate();
	_scav.attack("Albatroz");
	_clap.attack("Suricata");
	_frag.attack("Albatroz");
	_frag.highFivesGuys();

	// Diamond Tests
	std::cout << std::endl;
	printHeader("Diamond Tests");
	_diamond.whoAmI();
	std::cout << "HP: " << _diamond.getHP();
	std::cout << "\nEP: " << _diamond.getEP();
	std::cout << "\nAD: " << _diamond.getAD() << std::endl;
	_diamond.attack(_clap.getName());
	
	// Copy Tests
	printHeader("Copy Tests");
	DiamondTrap _diamondCopy(_diamond);
	_diamondCopy.whoAmI();
	std::cout << "HP: " << _diamondCopy.getHP();
	std::cout << "\nEP: " << _diamondCopy.getEP();
	std::cout << "\nAD: " << _diamondCopy.getAD() << std::endl;

	// Destruction
	printHeader("Destruction Logs");
	std::cout << std::endl;

	return (0);
}