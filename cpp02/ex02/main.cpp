/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:08:12 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/04 15:57:19 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Fixed.hpp"

void	printReturn(bool _return)
{
	std::cout << (_return ? "TRUE" : "FALSE") << std::endl;
}

void	runOtherTests(Fixed &a, Fixed &b, Fixed &c)
{
	std::cout << "Testing pre-increment on a: ";
	std::cout << ++a << std::endl;

	std::cout << "Testing post-increment on a: ";
	std::cout << a++ << std::endl;

	std::cout << "Value of a after post-increment: ";
	std::cout << a << std::endl;

	std::cout << "Testing pre-decrement on b: ";
	std::cout << --b << std::endl;

	std::cout << "Testing post-decrement on b: ";
	std::cout << b-- << std::endl;

	std::cout << "Value of b after post-decrement: ";
	std::cout << b << std::endl;

	std::cout << std::endl;

	std::cout << "Fixed::min(a, b): ";
	std::cout << Fixed::min(a, b) << std::endl;

	std::cout << "Fixed::min(b, c): ";
	std::cout << Fixed::min(b, c) << std::endl;

	std::cout << "Fixed::min(a, c): ";
	std::cout << Fixed::min(a, c) << std::endl;

	std::cout << std::endl;

	std::cout << "Fixed::max(a, b): ";
	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << "Fixed::max(b, c): ";
	std::cout << Fixed::max(b, c) << std::endl;

	std::cout << "Fixed::max(a, c): ";
	std::cout << Fixed::max(a, c) << std::endl;

	std::cout << std::endl;
}

void	runComparisonTests(Fixed&a, Fixed& b, Fixed& c)
{

    std::cout << a << " > " << b << " result: ";
    printReturn(a.toFloat() > b.toFloat());

    std::cout << a << " < " << b << " result: ";
    printReturn(a.toFloat() < b.toFloat());

    std::cout << a << " >= " << b << " result: ";
    printReturn(a.toFloat() >= b.toFloat());

    std::cout << a << " <= " << b << " result: ";
    printReturn(a.toFloat() <= b.toFloat());

    std::cout << a << " == " << b << " result: ";
    printReturn(a.toFloat() == b.toFloat());

    std::cout << a << " != " << b << " result: ";
    printReturn(a.toFloat() != b.toFloat());

    std::cout << std::endl;

    std::cout << b << " > " << c << " result: ";
    printReturn(b.toFloat() > c.toFloat());

    std::cout << b << " < " << c << " result: ";
    printReturn(b.toFloat() < c.toFloat());

    std::cout << b << " >= " << c << " result: ";
    printReturn(b.toFloat() >= c.toFloat());

    std::cout << b << " <= " << c << " result: ";
    printReturn(b.toFloat() <= c.toFloat());

    std::cout << b << " == " << c << " result: ";
    printReturn(b.toFloat() == c.toFloat());

    std::cout << b << " != " << c << " result: ";
    printReturn(b.toFloat() != c.toFloat());

    std::cout << std::endl;

    std::cout << a << " > " << c << " result: ";
    printReturn(a.toFloat() > c.toFloat());

    std::cout << a << " < " << c << " result: ";
    printReturn(a.toFloat() < c.toFloat());

    std::cout << a << " >= " << c << " result: ";
    printReturn(a.toFloat() >= c.toFloat());

    std::cout << a << " <= " << c << " result: ";
    printReturn(a.toFloat() <= c.toFloat());

    std::cout << a << " == " << c << " result: ";
    printReturn(a.toFloat() == c.toFloat());

    std::cout << a << " != " << c << " result: ";
    printReturn(a.toFloat() != c.toFloat());

    std::cout << std::endl;	
}

void	runOperationTests(Fixed& a, Fixed& b)
{
	std::cout << a << " " << "+" << " " << b 
			<< " result: "
			<< (a.toFloat() + b.toFloat()) << std::endl;


	std::cout << a << " " << "-" << " " << b 
			<< " result: "
			<< (a.toFloat() - b.toFloat()) << std::endl;

	
	std::cout << a << " " << "*" << " " << b 
			<< " result: "
			<< (a.toFloat() * b.toFloat()) << std::endl;

	
	std::cout << a << " " << "/" << " " << b 
			<< " result: "
			<< (a.toFloat() / b.toFloat()) << std::endl;
}

void	runTests(Fixed& a, Fixed& b, Fixed& c)
{
	std::cout << BWHITE <<"\n-------- Operation Tests --------\n" << RESET << std::endl;
	runOperationTests(a, b);
	std::cout << std::endl << std::endl;
	
	std::cout << BWHITE << "--------- Comparison Tests --------\n" << RESET << std::endl;
	runComparisonTests(a, b, c);
	std::cout << std::endl;

	std::cout << BWHITE <<  "------------ Other Tests ----------\n" << RESET << std::endl;
	runOtherTests(a, b, c);
}

int main( void ) {
	Fixed a(1);
	Fixed b(2.4f);
	Fixed c(13.564f);

	runTests(a, b, c);

	return 0;
}