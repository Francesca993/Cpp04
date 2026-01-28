/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 21:48:54 by francesca         #+#    #+#             */
/*   Updated: 2026/01/28 11:43:04 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("DefaultAnimal"){
    std::cout << GREEN << "ANIMAL Constructor called." << RESET << std::endl;
}
Animal::Animal(const Animal& other){
    std::cout << GREEN << "ANIMAL Copy Constructor called." << RESET << std::endl;
    this->type = other.type;
}

Animal& Animal::operator=(const Animal& other){
    std::cout << GREEN << "ANIMAL Copy Assign called." << RESET << std::endl;
    if (this != &other)
    {
    this->type = other.type;
    }
    return(*this);
}

Animal::~Animal(){
    std::cout << GREEN << "ANIMAL Destructor called." << RESET << std::endl;
}

void Animal::makeSound()const {
    std::cout << GREEN << "Default Animal doesn't do any sounds!" << RESET << std::endl;
}

std::string Animal::getType(){
    return(this->type);
}