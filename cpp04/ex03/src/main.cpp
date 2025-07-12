/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 09:47:38 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/12 17:55:46 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"


int	main(void)
{
	Cure*	cure = new Cure();
	Ice*	ice = new Ice();
	
	Character	Roberto("Roberto");
	Character	Ciclista("Ciclista");

	(void) Roberto;
	(void)	Ciclista;
 	Roberto.equip(cure), Roberto.equip(ice);

	Roberto.use(0, Ciclista), Roberto.use(1, Ciclista), Roberto.use(6, Ciclista);
	Ciclista.unequip(0);

	Roberto.unequip(1), Roberto.use(1, Ciclista);
	Roberto.unequip(0);
 	Ciclista.equip(cure), Ciclista.equip(ice);

	Ciclista.use(0, Ciclista), Ciclista.use(1, Ciclista);
}