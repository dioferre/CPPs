/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:11:12 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/12 17:57:30 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Utils.hpp"

void	printError(std::string Message)
{
	std::cout << RED << "[ERROR]: " << RESET
				<< Message
				<< std::endl;
}

void	printLog(std::string Message)
{
	std::cout << "[LOG]: " << Message << std::endl;
}