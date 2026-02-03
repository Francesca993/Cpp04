/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:40:02 by francesca         #+#    #+#             */
/*   Updated: 2026/02/02 20:46:20 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include"ICharacter.hpp"

Cure::Cure() : AMateria("cure"){
    //std::cout << BLUE << "Cure Constructor called." << RESET << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other){
    //std::cout << BLUE << "Cure Copy Constructor called." << RESET << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
    //std::cout << BLUE << "Cure Operator AQssign called." << RESET << std::endl;
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    return(*this);
}

Cure::~Cure(){
     //std::cout << BLUE << "Cure Destructor called." << RESET << std::endl;
}

AMateria* Cure::clone() const{
   return(new Cure(*this));
}

void Cure::use(ICharacter& target){
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}