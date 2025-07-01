#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#include "Colors.hpp"

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const Animal& other);
		virtual ~Animal();
		
		Animal&	operator=(const Animal& other);

		std::string		getType() const;
		virtual void	makeSound() const;
};


#endif 