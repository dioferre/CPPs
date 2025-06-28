/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:08:12 by dioferre          #+#    #+#             */
/*   Updated: 2025/06/22 13:42:46 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Fixed.hpp"

#include "Point.hpp"

int main( void ) {
    // Triangle vertices
    Point A(-5, -2);
    Point B(3, 4);
    Point C(6, -3);

    // Test points
    Point P1(1, 0);      // Inside
    Point P2(0, -1);     // Inside
    Point P3(2, 1);      // Inside

    Point P4(-5, -2);    // On vertex A
    Point P5(4.5, 0.5);  // On edge BC
    Point P6(-1, 1);     // On edge AB

    Point P7(-6, -4);    // Outside, far left
    Point P8(0, 5);      // Outside, above triangle
    Point P9(7, -4);     // Outside, far right
    Point P10(10, 10);   // Outside, far top-right

    // Example usage
    std::cout << "P1 status : " << (bsp(A, B, C, P1) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "P2 status : " << (bsp(A, B, C, P2) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "P3 status : " << (bsp(A, B, C, P3) ? "INSIDE" : "OUTSIDE") << std::endl;

    std::cout << "P4 status : " << (bsp(A, B, C, P4) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "P5 status : " << (bsp(A, B, C, P5) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "P6 status : " << (bsp(A, B, C, P6) ? "INSIDE" : "OUTSIDE") << std::endl;

    std::cout << "P7 status : " << (bsp(A, B, C, P7) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "P8 status : " << (bsp(A, B, C, P8) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "P9 status : " << (bsp(A, B, C, P9) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "P10 status : " << (bsp(A, B, C, P10) ? "INSIDE" : "OUTSIDE") << std::endl;

    return 0;
}
