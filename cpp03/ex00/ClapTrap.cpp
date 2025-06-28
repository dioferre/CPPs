#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("unknown"), HP(10), EP(10), AD(0)
{
	std::cout << BWHITE << "<ClapTrap>"
				<< GREEN " Default Constructor" << RESET
				<< " called." << std::endl;
}

ClapTrap::ClapTrap( std::string Name ): _name(Name), HP(10), EP(10), AD(0)
{
	std::cout << BWHITE << "<ClapTrap>"
				<< GREEN " Constructor" << RESET
				<< " called." << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& src )
{
	*this = src;
	std::cout << BWHITE << "<ClapTrap>"
				<< GREEN " Copy Constructor" << RESET
				<< " called." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << BWHITE << "<ClapTrap>"
			<< RED " Destructor" << RESET
			<< " called." << std::endl;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& src)
{
	if (this != &src)
	{
		_name = src._name;
		HP = src.HP;
		EP = src.EP;
		AD = src.AD;
	}
	return (*this);
}

void	ClapTrap::attack( const std::string& target )
{
	if ( EP >= 1 && HP > 0)
	{
		std::cout << "ClapTrap";
		std::cout << " <" << _name << "> ";
		std::cout << "attacks";
		std::cout << " <" << target << ">, ";
		std::cout << "causing";
		std::cout << "<" << this->AD << "> ";
		std::cout << "points of damage!" << std::endl;

		EP -= 1;
	}
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if ( amount <= HP  && HP > 0)
		HP -= amount;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if ( EP > 0 && HP > 0 )
		HP += amount;
}
