#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string Name ) : ClapTrap(Name)
{
	std::cout << BWHITE << "<ScavTrap>"
				<< GREEN " Constructor" << RESET
				<< " called." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << BWHITE << "<ScavTrap>"
				<< RED " Destructor" << RESET
				<< " called." << std::endl;
}

void	ScavTrap::attack( const std::string& target )
{
	std::cout << BWHITE << "<" << this->_name << "> " << RESET
				<< "with an astonishing attack power of " << RED << AD << RESET << ","
				<< " attacks " << BWHITE<< "<" << target << ">" << RESET << "!\n"
				<< "However it slips and misses the attack, how embarassing!" << std::endl;
}

void	ScavTrap::guardGate( void )
{
	std::cout << BWHITE << "<" << this->_name << "> " << RESET
				<< "is now guarding the gate! "
				<< "Whatever that means..." << std::endl;
}