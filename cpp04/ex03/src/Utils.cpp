/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:11:12 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/11 12:22:05 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Utils.hpp"

void	printError(std::string Message)
{
	std::cout << RED << "[ERROR] : " << RESET
				<< Message
				<< std::endl;
}