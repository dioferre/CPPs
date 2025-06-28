/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:10:15 by dioferre          #+#    #+#             */
/*   Updated: 2025/05/18 12:11:56 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie( std::string name )
{
	this->name = name;
	this->announce();
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " destroyed!" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
