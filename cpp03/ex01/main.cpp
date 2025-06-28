#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap subject1("Camelo");
	ClapTrap subject2("Abutre");

	subject1.guardGate();
	subject1.attack("Albatroz");
	subject2.attack("Suricata");

	return (0);
}