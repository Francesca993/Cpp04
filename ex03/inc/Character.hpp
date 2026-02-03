/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:35:39 by francesca         #+#    #+#             */
/*   Updated: 2026/02/03 10:27:05 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#define INVENTARYMAX 4
#define MAXINVTODELETE 100

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
    private:
    std::string _name;
    AMateria *_inventary[4];
    AMateria *_invToDelet[100];
    int count;
    
    public:
    Character();
    Character(std::string const& name);
    Character(const Character& other);
    Character&operator=(const Character& other);
    ~Character();
    
    std::string const& getName()const;
    int getCount();
    
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
    
};

#endif

/*
Write the concrete class Character which will implement the following interface:
- The Character possesses an inventory of 4 slots, which means at most 4 Materias.
- The inventory is empty upon construction. 
- They equip the Materias in the first empty slot they find, in the following order: from slot 0 to slot 3. 
- If they try to add a Materia to a full inventory, or use/unequip a non-existent Materia, nothing should happen (but bugs
are still forbidden). 
- The unequip() member function must NOT delete the Materia!
- Handle the Materias your character leaves on the floor as you like.
- Save the addresses before calling unequip(), or anything else, but don’t forget that you have to avoid memory leaks.
- The use(int, ICharacter&) member function will have to use the Materia at the
slot[idx], and pass the target parameter to the AMateria::use function.
- Your character’s inventory will be able to support any type of
AMateria.
- Your Character must have a constructor taking its name as a parameter. 
- Any copy (using copy constructor or copy assignment operator) of a Character must be deep.
- During copy, the Materias of a Character must be deleted before the new ones are added
totheirinventory. 
- Ofcourse, theMateriasmustbedeletedwhenaCharacterisdestroyed.
*/