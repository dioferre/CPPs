#ifndef AMATERIA_HPP
#define AMATERIA_HPP


#include <iostream>

#include "Colors.hpp"
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string	type;
public:
	AMateria();
	AMateria( const std::string& _type );
	AMateria( const AMateria& other );

	~AMateria();

	AMateria& operator=( const AMateria& other );

	const std::string&	getType() const; //Returns the materia type
	virtual AMateria*	clone() const = 0;
	virtual void	use(ICharacter& target);
};

#endif