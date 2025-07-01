/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:34:14 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/01 10:04:49 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug( void )
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple"
		 		<< "-pickle-special-ketchup burger. I really do!"
		 		<< std::endl;
}

void	Harl::info( void )
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. "
				<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t"
				<< " be asking for more!"
				<< std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. "
				<< "I’ve been coming for years, whereas you started working "
				<< "here just last month."
				<< std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now."
				<< std::endl;
}

int		getLevelId( std::string& level )
{
	if (level == "DEBUG")
		return (1);
	if (level == "INFO")
		return (2);
	if (level == "WARNING")
		return (3);
	if (level == "ERROR")
		return (4);
	return (-1);
}

void	Harl::complain( std::string level )
{
	std::string	action[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*fptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int	levelId = getLevelId(level);

	switch (levelId)
	{
		case (1):
			(this->*fptr[0])();
			(this->*fptr[1])();
			(this->*fptr[2])();
			(this->*fptr[3])();
			break;
		case (2):
			(this->*fptr[1])();
			(this->*fptr[2])();
			(this->*fptr[3])();
			break;
		case (3):
			(this->*fptr[2])();
			(this->*fptr[3])();
			break;
		case (4):
			(this->*fptr[3])();
			break;
		default:
			std::cout << "[DANCE]\n*bursts into a dance*" << std::endl;
			break;
	}
}
