#ifndef AMATERIA_HPP
#define AMATERIA_HPP


#include <iostream>

#include "Colors.hpp"
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string	type;
	ICharacter	*wielder;
	bool		is_on_floor;
public:
	AMateria();
	AMateria( const std::string& _type );
	AMateria( const AMateria& other );

	virtual ~AMateria();

	AMateria& operator=( const AMateria& other );

	const std::string&	getType() const; //Returns the materia type
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);

	// Accessors / Mutators

	void		setWielder( ICharacter* target );
	ICharacter*	getWielder( void );

	void		setFloorState( bool state );
	bool		getFloorState( void );
};

#endif