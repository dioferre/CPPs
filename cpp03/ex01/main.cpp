#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap subject1("Abutre");
	ScavTrap subject2("Camelo");
	ScavTrap subject3(subject2);

	std::cout << std::endl;

	subject2.guardGate();
	subject2.attack("Albatroz");
	subject1.attack("Suricata");

	subject3.beRepaired(2);

	std::cout << std::endl;
	return (0);
}