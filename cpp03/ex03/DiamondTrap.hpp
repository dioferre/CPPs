#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"


class DiamondTrap : public ScavTrap, FragTrap
{
	private:
		std::string	_name;

	public:
		DiamondTrap();
		DiamondTrap( std::string Name );
		DiamondTrap( const DiamondTrap& src );

		~DiamondTrap();

		DiamondTrap& operator=( const DiamondTrap& src );		

		void		whoAmI();
		std::string	getName() const;
		using		ScavTrap::attack;
} ;


#endif