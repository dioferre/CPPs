/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:51:58 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/01 10:05:39 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main( void )
{
	Harl _Harl;

	std::cout << std::endl << "------ DEBUG Level ------" << std::endl;
	_Harl.complain("DEBUG");
	std::cout << std::endl << "------ ERROR Level ------" << std::endl;
	_Harl.complain("ERROR");
	std::cout << std::endl << "------ Invalid Level ------" << std::endl;
	_Harl.complain("ALARM");
	std::cout << std::endl;
	return (0);
}
