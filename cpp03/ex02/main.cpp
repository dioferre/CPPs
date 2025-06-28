#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ScavTrap subject1("Camelo");
	ClapTrap subject2("Abutre");
	FragTrap subject3("Papas de Sarrabulho");

	subject1.guardGate();
	subject1.attack("Albatroz");

	subject2.attack("Suricata");
	
	subject3.attack("Albatroz");
	subject3.highFivesGuys();

	return (0);
}