/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 08:41:22 by dioferre          #+#    #+#             */
/*   Updated: 2025/09/22 09:09:06 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int	main(void)
{
	Span sp = Span(5);
	Span sp2 = Span(100000);
	Span sp3 = Span(3);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	sp2.addNumberRange(1, 100000);
	sp3.addNumberRange(1, 200000);
	
	// Testing sp
	{
		std::cout << "Sp:" << std::endl;
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
		std::cout << std::endl;
	}

	// Testing sp2
	{
		std::cout << "Sp2:" << std::endl;
		std::cout << "shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp2.longestSpan() << std::endl;
		std::cout << std::endl;
	}

	// Testing sp3
	{
		std::cout << "Sp3:" << std::endl;
		std::cout << "shortest span: " << sp3.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp3.longestSpan() << std::endl;
	}
	
	return (0);
}