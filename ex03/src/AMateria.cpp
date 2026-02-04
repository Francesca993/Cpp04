/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:30:54 by francesca         #+#    #+#             */
/*   Updated: 2026/02/04 10:40:14 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type) : _type(type){
    //std::cout << RED << "AMateriaBAsed Constructor called." << RESET << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
    //std::cout << RED << "AMateriaBAsed Copy Constructor called." << RESET << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other){
    if (this != &other && this->_type != other._type)
        std::cout << RED
                  << "While assigning a Materia to another the type must be the same."
                  << RESET << std::endl;
    return *this;
}

AMateria::~AMateria(){
    //std::cout << RED << "AMateriaBAsed Destructor called." << RESET << std::endl;
}

std::string const &AMateria::getType() const {
    return(this->_type);
}

void AMateria::use(ICharacter& target){  
    std::cout << RED << "AMateria Defaulte use() does Nothing! Target: " << &target << RESET << std::endl;
}
/*
        The use(ICharacter&) member function will display:
        • Ice: "* shoots an ice bolt at <name> *"
        • Cure: "* heals <name>’s wounds *"
        
*/
