/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:13:35 by dioferre          #+#    #+#             */
/*   Updated: 2026/02/25 09:11:03 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Program takes only 2 arguments." << std::endl;
		return (1);
	}
	try
	{
		RPN	alg(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "[ERROR]: " << e.what() << '\n';
	}
	
	return (0);
}