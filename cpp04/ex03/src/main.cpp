/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioferre <dioferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 09:47:38 by dioferre          #+#    #+#             */
/*   Updated: 2025/07/13 18:42:50 by dioferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"


/* int	main(void)
{
	Cure*	cure = new Cure();
	Ice*	ice = new Ice();
	
	Character	Roberto("Roberto");
	Character	Ciclista("Ciclista");

	(void) Roberto;
	(void)	Ciclista;
 	Roberto.equip(cure), Roberto.equip(ice);

	Roberto.use(0, Ciclista), Roberto.use(1, Ciclista), Roberto.use(6, Ciclista);
	Ciclista.unequip(0);

	Roberto.unequip(1), Roberto.use(1, Ciclista);
	Roberto.unequip(0);
 	Ciclista.equip(cure), Ciclista.equip(ice);

	Ciclista.use(0, Ciclista), Ciclista.use(1, Ciclista);

	Character Ciclista_clone(Ciclista);

	Ciclista_clone.use(0, Roberto);
	Ciclista_clone.unequip(0);
	Ciclista_clone.use(0, Roberto);
	Ciclista.use(0, Ciclista_clone);
} */


// Test 1: Basic Materia Creation and Type Check
void test1() {
    std::cout << "=== Test 1: Basic Materia Creation and Type Check ===\n";
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();

    std::cout << "Ice type: " << ice->getType() << std::endl;   // Expected: "ice"
    std::cout << "Cure type: " << cure->getType() << std::endl; // Expected: "cure"

    delete ice;
    delete cure;
}

// Test 2: Materia Cloning
void test2() {
    std::cout << "\n=== Test 2: Materia Cloning ===\n";
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();

    AMateria* iceClone = ice->clone();
    AMateria* cureClone = cure->clone();

    std::cout << "Ice clone type: " << iceClone->getType() << std::endl;   // Expected: "ice"
    std::cout << "Cure clone type: " << cureClone->getType() << std::endl; // Expected: "cure"

    delete ice;
    delete cure;
    delete iceClone;
    delete cureClone;
}

// Test 3: Using Materias on a Character
void test3() {
    std::cout << "\n=== Test 3: Using Materias on a Character ===\n";
    ICharacter* target = new Character("target");
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();

    ice->use(*target);  // Expected: "* shoots an ice bolt at target *"
    cure->use(*target); // Expected: "* heals target's wounds *"

    delete target;
    delete ice;
    delete cure;
}

// Test 4: Character Inventory Management
void test4() {
    std::cout << "\n=== Test 4: Character Inventory Management ===\n";
    Character* me = new Character("me");
    ICharacter* bob = new Character("bob");

    // Equip 4 Materias
    me->equip(new Ice());
    me->equip(new Cure());
    me->equip(new Ice());
    me->equip(new Cure());

    // Try to equip a 5th Materia (should fail silently)
    AMateria* extra = new Ice();
    me->equip(extra); // Inventory is full, extra should not be equipped

    // Use equipped Materias
    me->use(0, *bob); // Expected: "* shoots an ice bolt at bob *"
    me->use(1, *bob); // Expected: "* heals bob's wounds *"

    delete me;   // Should delete all equipped Materias
    delete bob;
    delete extra; // Must delete manually since it wasn't equipped
}

// Test 5: Unequipping Materias
void test5() {
    std::cout << "\n=== Test 5: Unequipping Materias ===\n";
    Character* me = new Character("me");

    AMateria* ice = new Ice();
    me->equip(ice);
    me->unequip(0); // Unequip the ice Materia

    // Use slot 0 (should do nothing since it's empty)
    ICharacter* bob = new Character("bob");
    me->use(0, *bob); // No output expected

    // Unequip from empty slot (should do nothing)
    me->unequip(0);

    delete me;
    delete bob;
}

// Test 6: Using Materias from Inventory
void test6() {
    std::cout << "\n=== Test 6: Using Materias from Inventory ===\n";
    Character* me = new Character("me");
    ICharacter* bob = new Character("bob");

    me->equip(new Ice());
    me->equip(new Cure());

    me->use(0, *bob); // Expected: "* shoots an ice bolt at bob *"
    me->use(1, *bob); // Expected: "* heals bob's wounds *"
    me->use(2, *bob); // No Materia in slot 2, no output expected
    me->use(-1, *bob); // Invalid index, no output expected

    delete me;
    delete bob;
}

// Test 7: MateriaSource Learning and Creating Materias
void test7() {
    std::cout << "\n=== Test 7: MateriaSource Learning and Creating Materias ===\n";
    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    AMateria* ice = src->createMateria("ice");
    AMateria* cure = src->createMateria("cure");
    AMateria* unknown = src->createMateria("fire");

    std::cout << "Ice type: " << (ice ? ice->getType() : "nullptr") << std::endl;     // Expected: "ice"
    std::cout << "Cure type: " << (cure ? cure->getType() : "nullptr") << std::endl;  // Expected: "cure"
    std::cout << "Unknown: " << (unknown ? unknown->getType() : "nullptr") << std::endl; // Expected: "nullptr"

    delete ice;
    delete cure;
    delete src; // Should delete learned Materias
}

// Test 8: Character Copying (Deep Copy)
void test8() {
    std::cout << "\n=== Test 8: Character Copying (Deep Copy) ===\n";
    Character* original = new Character("original");
    original->equip(new Ice());

    // Copy constructor
    Character* copy1 = new Character(*original);
    copy1->unequip(0); // Modify copy1's inventory

    ICharacter* bob = new Character("bob");
    original->use(0, *bob); // Expected: "* shoots an ice bolt at bob *"
    copy1->use(0, *bob);    // No Materia in slot 0, no output expected

    // Assignment operator
    Character copy2("copy2");
    copy2 = *original;
    copy2.unequip(0);
    original->use(0, *bob); // Expected: "* shoots an ice bolt at bob *"
    copy2.use(0, *bob);     // No Materia in slot 0, no output expected

    delete original;
    delete copy1;
    delete bob;
}

// Test 9: Memory Management
void test9() {
    std::cout << "\n=== Test 9: Memory Management ===\n";
    Character* me = new Character("me");
    AMateria* ice = new Ice();
    me->equip(ice);
    me->equip(new Cure());

    me->unequip(0); // Unequip ice, must delete manually
    delete me;      // Should delete remaining equipped Cure
}

// Test 10: Interface Method Tests
void test10() {
    std::cout << "\n=== Test 10: Interface Method Tests ===\n";
    ICharacter* me = new Character("me");
    std::cout << "Name: " << me->getName() << std::endl; // Expected: "me"
    me->equip(new Ice());
    ICharacter* bob = new Character("bob");
    me->use(0, *bob); // Expected: "* shoots an ice bolt at bob *"
    me->unequip(0);

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Cure());
    AMateria* cure = src->createMateria("cure");
    cure->use(*bob); // Expected: "* heals bob's wounds *"

    delete me;
    delete bob;
    delete cure;
    delete src;
}


// NOTE: There are possible leaks if a user tries to
// equip a materia to a full inventory, beacuse it
// won't be freed inside the Character class later.
// I haven't found any way to fix this without making
// the program crash instead. It's up to the user to
// handle the inventory slots properly based on the
// error logs.
int main() {

  	test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    return 0;
}