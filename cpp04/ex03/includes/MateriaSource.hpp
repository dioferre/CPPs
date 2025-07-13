#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria*	known_materias[4];

	static int	inventory_size;

	void		cleanInventory();
	void		copyKnownMaterias( const MateriaSource& other );
public:
	MateriaSource();
	MateriaSource( const MateriaSource& other );
	~MateriaSource();

	MateriaSource& operator=( const MateriaSource& other );
	
	void learnMateria( AMateria* src );
	AMateria* createMateria(std::string const & type);
};

#endif