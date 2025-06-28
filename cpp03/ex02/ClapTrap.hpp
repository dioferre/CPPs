#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

// Colors because the subject won't let me
// put them on a separate file :D

#define RESET	"\033[0m"
#define BLACK	"\033[30m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"

#define BWHITE	"\033[1;37m"


class ClapTrap
{
protected:
	std::string		_name;
	unsigned int	HP;
	unsigned int	EP;
	unsigned int	AD;

public:
	ClapTrap();
	ClapTrap( std::string Name );
	ClapTrap( const ClapTrap& src );
	
	~ClapTrap();

	ClapTrap& operator=( const ClapTrap& src );

	virtual void	attack( const std::string& target );
	void			takeDamage( unsigned int amount );
	void			beRepaired( unsigned int amount );
} ;


#endif