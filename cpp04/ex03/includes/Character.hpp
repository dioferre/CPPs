#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Utils.hpp"

#include <iostream>
#include <vector>


class Character : public ICharacter
{
private:
	std::string			name;
	AMateria*			inventory[4];

	static AMateria*	floor[50];
	static int			inventory_size;
	static int			max_floor_items;
	void				rebuildFLoorArray( int pop_item_idx );

	bool				isValidIndex( int idx );
	bool				isMateriaEquippable( AMateria* m );
	void				dropItem( AMateria& item );
	void				pickItem( AMateria& item );
 public:
	Character();
	Character( std::string _name );
	Character( const Character& other );
	~Character();

	Character&	operator=( const Character& other );
	std::string const & getName() const;
	void equip( AMateria* m );
	void unequip( int idx );
	void use( int idx, ICharacter& target );
};


#endif