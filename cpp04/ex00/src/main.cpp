/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:38:05 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/21 11:15:37 by dioferre         ###   ########.fr       */
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
}

void	printWrongAnimalSound( const WrongAnimal& subject )
{
	std::cout << subject.getType() << ": ";
	subject.makeSound();
}

int main()
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongCat*    wrongCat = new WrongCat();
	
	//			Prints

	std::cout << BWHITE;
	std::cout << "\n--------- Animals --------\n" << std::endl;
	
	printAnimalSound(*animal);
	printAnimalSound(*dog);
	printAnimalSound(*cat);
	
	std::cout << "\n------ Wrong Animals -----\n" << std::endl;
	printWrongAnimalSound(*wrongAnimal);
	printWrongAnimalSound(*wrongCat);
	std::cout << "Wrong Cat: "; wrongCat->makeSound();

	std::cout << "\n--------------------------\n" << std::endl;
	std::cout << RESET;

	//			Cleaning
	
	delete (animal);
	delete (dog);
	delete (cat);

	delete(wrongAnimal);
	delete(wrongCat);

	return (0);
}