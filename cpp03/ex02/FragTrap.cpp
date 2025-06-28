#include "FragTrap.hpp"

FragTrap::FragTrap( std::string Name ) : ClapTrap(Name)
{
	std::cout << BWHITE << "<FragTrap>"
				<< GREEN " Constructor" << RESET
				<< " called." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << BWHITE << "<FragTrap>"
				<< RED " Destructor" << RESET
				<< " called." << std::endl;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << BWHITE << "<" << this->_name << "> " << RESET
				<< "gives you a high five!" << std::endl;
}