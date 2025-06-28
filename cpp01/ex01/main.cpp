/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:02:49 by dioferre          #+#    #+#             */
/*   Updated: 2025/05/18 12:49:40 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie*	horde;
	int		N = 7;

	horde = zombieHorde(N, "Bartolomeu");

	for (int i = 0; i < N; i++) {
		std::cout << "Zombie index " << i << ": ";
		horde[i].announce();
	}

	delete[] horde;
	return (0);
}
