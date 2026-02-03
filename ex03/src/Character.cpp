/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 21:09:26 by francesca         #+#    #+#             */
/*   Updated: 2026/02/03 10:36:05 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

Character::Character() : _name("UndefinedName"), count(0) {
    std::cout << MAGENTA << "Character Default Constructor Called " << RESET << std::endl;
    for(int i = 0; i < INVENTARYMAX; i++)
    {
        _inventary[i] = NULL;
    }
    for(int j = 0; j < MAXINVTODELETE; j++)
    {
        _invToDelet[j] = NULL;
    }
    count = 0;
}

Character::Character(std::string const& name) : _name(name), count(0) {
    std::cout << MAGENTA << "Character Parametric Constructor Called " << RESET << std::endl;
    for(int i = 0; i < INVENTARYMAX; i++)
    {
        _inventary[i] = NULL;
    }
    for(int j = 0; j < MAXINVTODELETE; j++)
    {
        _invToDelet[j] = NULL;
    }
    count = 0;
}

Character &Character::operator=(const Character& other){
    std::cout << MAGENTA << "Character Operator Assign Called " << RESET << std::endl;
    if (this == &other)
        return(*this);
    this->_name = other._name;
    for (int i = 0; i < INVENTARYMAX; i++)
    {
        if (this->_inventary[i])
            delete this->_inventary[i];
        if (other._inventary[i])
            this->_inventary[i] = other._inventary[i]->clone();
        else
            this->_inventary[i] = NULL;
    }
    if (this->count != 0)
    {
        for (int j = 0; j < count; j++)
        {
            if (this->_invToDelet[j] != NULL)
            {
                delete this->_invToDelet[j];
                this->_invToDelet[j] = NULL;
            }
        }
    }
    this->count = 0; 
    return(*this);
}

Character::Character(const Character& other) 
{
    std::cout << MAGENTA << "Character Copy Constructor Called " << RESET << std::endl;
    *this = other;
}

Character::~Character(){
    std::cout << MAGENTA << "Character Destructor Called " << RESET << std::endl;
    for(int i = 0; i < INVENTARYMAX; i++)
    {
        if (this->_inventary[i] != NULL)
            delete this->_inventary[i];
    }
    for(int j = 0; j < MAXINVTODELETE; j++)
    {
        if (_invToDelet[j] != NULL)
            delete _invToDelet[j];
    }
    count = 0;
}



/*
class Character : public ICharacter {
    protected:
    std::string _name;
    AMateria *_inventory[4];
    AMateria *_invToDelet[100];
    int count;
    
    public:
    Character(std::string const& name);
    Character(const Character& other);
    Character&operator=(const Character& other);
    ~Character();
    
    std::string const& getName()const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
    
};
*/