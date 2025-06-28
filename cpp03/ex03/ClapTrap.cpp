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
		_name = src.getName();
		HP = src.getHP();
		EP = src.getEP();
		AD = src.getAD();
	}
	return (*this);
}

void	ClapTrap::attack( const std::string& target )
{
	if ( EP >= 1 && HP > 0)
	{
		std::cout << BWHITE << "<" << this->_name << "> " << RESET
					<< "attacks " << BWHITE<< "<" << target << ">" << RESET << ", "
					<< "doing " << RED << AD << RESET << " points of damage!\n";
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

std::string ClapTrap::getName() const
{
	return (_name);
}

unsigned int ClapTrap::getHP() const
{
	return ( HP );
}

unsigned int ClapTrap::getEP() const
{
	return ( EP );
}

unsigned int ClapTrap::getAD() const
{
	return ( AD );
}