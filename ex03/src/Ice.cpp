/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:21:19 by francesca         #+#    #+#             */
/*   Updated: 2026/02/02 20:45:12 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include"ICharacter.hpp"

Ice::Ice() : AMateria("ice"){
    //std::cout << BLUE << "Ice Constructor called." << RESET << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other){
    //std::cout << BLUE << "Ice Copy Constructor called." << RESET << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
    //std::cout << BLUE << "Ice Operator AQssign called." << RESET << std::endl;
    if (this != &other)
    {
        AMateria::operator=(other);
    }
    return(*this);
}

Ice::~Ice(){
     //std::cout << BLUE << "Ice Destructor called." << RESET << std::endl;
}

AMateria* Ice::clone() const{
   return(new Ice(*this));
}

void Ice::use(ICharacter& target){
    std::cout << "* shoots an ice bolt at " << target.getName() << " * " << std::endl;
}

/* The use(ICharacter&) member function will display:
        • Ice: "* shoots an ice bolt at <name> *"
        • Cure: "* heals <name>’se wounds *"
*/
