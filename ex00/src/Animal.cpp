/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 21:48:54 by francesca         #+#    #+#             */
/*   Updated: 2026/01/09 10:09:30 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("DefaultAnimal"){
    std::cout << GREEN << "ANIMAL Constructor called." << std::endl;
}
Animal::Animal(const Animal& other){
    std::cout << GREEN << "ANIMAL Copy Constructor called." << std::endl;
    this->type = other.type;
}

Animal& Animal::operator=(const Animal& other){
    std::cout << GREEN << "ANIMAL Copy Assign called." << std::endl;
    if (this != &other)
    {
    this->type = other.type;
    }
    return(*this);
}

Animal::~Animal(){
    std::cout << GREEN << "ANIMAL Destructor called." << std::endl;
}

void Animal::makeSound(){
    std::cout << YELLOW << "Default Animal doesn't do any sounds!" << std::endl;
}

std::string Animal::getType(){
    return(this->type);
}