/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:38:05 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/21 11:42:17 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define ARRAY_SIZE 6

void	printAnimalSound( const Animal& subject )
{
	std::cout << subject.getType() << ": ";
	subject.makeSound();
	std::cout << std::endl;
}

int main()
{
	Animal*	animals[ARRAY_SIZE];
	//Animal	_lel;

	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	
	std::cout << BWHITE << std::endl;

	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << "This is a " << animals[i]->getType() << std::endl;
		printAnimalSound(*animals[i]);
	}
	
	std::cout << RESET;

	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		delete animals[i];
	}
	
	return (0);
}