/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:38:05 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/08 12:44:22 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	printAnimalSound( const Animal& subject )
{
	std::cout << subject.getType() << ": ";
	subject.makeSound();
	std::cout << std::endl;
}

int main()
{
	Animal*	animals[4];
	Animal	_lel;

	for (size_t i = 0; i < 5; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	
	std::cout << std::endl;

	for (size_t i = 0; i < 5; i++)
	{
		std::cout << "This is a " << animals[i]->getType() << std::endl;
		printAnimalSound(*animals[i]);
	}
	
	std::cout << std::endl;

	for (size_t i = 0; i < 5; i++)
	{
		delete animals[i];
	}
	
	return (0);
}