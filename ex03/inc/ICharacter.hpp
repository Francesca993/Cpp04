/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:37:51 by francesca         #+#    #+#             */
/*   Updated: 2026/02/02 21:08:42 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"
#include "Debug.hpp"

class AMateria; // forward declaration

class ICharacter
{
public:
    virtual ~ICharacter() {};

    virtual std::string const& getName() const = 0;

    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

#endif

/*
3️⃣ ICharacter (INTERFACCIA)
Questa è una classe puramente astratta.
👉 Dice SOLO cosa un personaggio può fare, non come.
*/

