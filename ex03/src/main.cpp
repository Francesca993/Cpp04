/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:17:27 by francesca         #+#    #+#             */
/*   Updated: 2026/02/04 14:18:13 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include"ICharacter.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Debug.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

/*
int main()
{
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter *me = new Character("me");
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}
*/

static void sep(const std::string& t)
{
    std::cout << "\n==================== " << t << " ====================\n";
}

static void ptrinfo(const std::string& label, void* p)
{
    std::cout << label << ": " << p << std::endl;
}

int main()
{
    sep("SETUP: MateriaSource learnMateria");
    IMateriaSource* src = new MateriaSource();

    // Learn 2 materias (subject-like)
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // Learn more to fill slots (optional)
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // This one tests "full source" behavior (should not leak / should be handled safely)
    src->learnMateria(new Ice());

    sep("CREATE MATERIA: found / not found");
    AMateria* m0 = src->createMateria("ice");
    AMateria* m1 = src->createMateria("cure");
    AMateria* m2 = src->createMateria("fire"); // should be NULL

    ptrinfo("m0 (ice)", m0);
    ptrinfo("m1 (cure)", m1);
    ptrinfo("m2 (fire)", m2);

    // If createMateria returns NULL, don't delete it
    if (!m2)
        std::cout << "OK: createMateria(\"fire\") returned NULL\n";

    sep("CHARACTERS: equip/use basic");
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");

    // Equip created materias
    if (m0) me->equip(m0);
    if (m1) me->equip(m1);

    // Use equipped materias
    me->use(0, *bob);
    me->use(1, *bob);

    sep("EQUIP UP TO FULL + OVERFLOW");
    // Equip more to fill up to 4
    AMateria* e2 = src->createMateria("ice");
    AMateria* e3 = src->createMateria("cure");
    AMateria* e4 = src->createMateria("ice"); // 5th attempt (overflow)

    ptrinfo("e2", e2);
    ptrinfo("e3", e3);
    ptrinfo("e4 (overflow)", e4);

    if (e2) me->equip(e2);
    if (e3) me->equip(e3);

    // This one is the interesting one:
    // - If your equip stores overflow into floor (_invToDelet), don't delete here.
    // - If your equip does "nothing happens" and doesn't take ownership, you'd leak unless you delete here.
    // In your latest approach, equip takes ownership (floor) or deletes if floor full,
    // so we should just call equip and NOT delete afterwards.
    if (e4) me->equip(e4);

    sep("USE: valid/invalid indexes (should not crash)");
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    me->use(4, *bob);   // invalid
    me->use(-1, *bob);  // invalid

    sep("UNEQUIP: valid/invalid indexes (should not delete immediately)");
    me->unequip(1);   // drop slot 1
    me->use(1, *bob); // should do nothing

    me->unequip(10);  // invalid, should do nothing
    me->unequip(-3);  // invalid, should do nothing

    sep("DEEP COPY: copy constructor");
    Character* original = new Character("original");
    AMateria* o0 = src->createMateria("ice");
    AMateria* o1 = src->createMateria("cure");
    if (o0) original->equip(o0);
    if (o1) original->equip(o1);

    Character copyCtor(*original); // deep copy expected
    std::cout << "original name: " << original->getName() << "\n";
    std::cout << "copyCtor name:  " << copyCtor.getName() << "\n";

    // Use both to ensure they work independently (no crash/double-free later)
    original->use(0, *bob);
    copyCtor.use(0, *bob);

    sep("DEEP COPY: copy assignment");
    Character assigned("assigned");
    assigned = *original; // deep copy expected
    assigned.use(1, *bob);

    sep("CLEANUP");
    // Important: do NOT delete materias you've equipped (Character owns them).
    // We already handed ownership of m0/m1/e2/e3/e4/o0/o1 to Characters.

    delete original;
    delete me;
    delete bob;
    delete src;

    // copyCtor and assigned are stack objects; they will destruct automatically here.
    sep("END");
    return 0;
}