/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:43:33 by dioferre          #+#    #+#             */
/*   Updated: 2025/09/08 11:21:23 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib> // srand, rand
#include <ctime> // time
#include <iostream> // cout, endl
#include <exception> // exceptions

Base * generate(void)
{
	srand(time(NULL));
	switch (rand() % 3)
	{
		case 0:
			std::cout << "A class generated." << std::endl;
			return (new(A));
		case 1:
			std::cout << "B class generated." << std::endl;
			return (new(B));
		case 2:
			std::cout << "C class generated." << std::endl;
			return (new(C));
	}
	
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << "It's an A class" << std::endl;
	}
	else if (dynamic_cast<B*>(p) != NULL)
	{
		std::cout << "It's a B class" << std::endl;
	}
	else if (dynamic_cast<C*>(p) != NULL)
	{
		std::cout << "It's a C class" << std::endl;
	}
	else
		std::cerr << "Can't identify this class" << std::endl;
	
	return ;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "It's an A class" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "It's a B class" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "It's a C class" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << "Can't identify this class" << std::endl;
			}
		}
	}
}

int	main(void)
{
	Base *p = generate();
	Base &r = *p;

	identify(p);
	identify(r);

	delete p;

	return (0);
}