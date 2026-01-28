/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 21:48:54 by francesca         #+#    #+#             */
/*   Updated: 2026/01/28 11:18:16 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("DefaultWrongAnimal"){
    std::cout << ORANGE << "WrongANIMAL Constructor called." << RESET << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other){
    std::cout << ORANGE << "WrongANIMAL Copy Constructor called." << RESET << std::endl;
    this->type = other.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
    std::cout << ORANGE << "WrongANIMAL Copy Assign called." << RESET << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return(*this);
}

WrongAnimal::~WrongAnimal(){
    std::cout << ORANGE << "WrongANIMAL Destructor called." << RESET << std::endl;
}

void WrongAnimal::makeSound()const {
    std::cout << ORANGE << "Default WrongAnimal doesn't do any sounds!" << RESET << std::endl;
}

std::string WrongAnimal::getType(){
    return(this->type);
}