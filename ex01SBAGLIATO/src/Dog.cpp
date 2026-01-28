/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 22:11:35 by francesca         #+#    #+#             */
/*   Updated: 2026/01/27 14:49:06 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(){
    type = "Dog";
    std::cout << RED << "Dog Constructor called." << std::endl;
}
Dog::Dog(const Dog& other): Animal(other) {
    std::cout << RED << "Dog Copy Constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& other){
    std::cout << RED << "Dog Copy Assign called." << std::endl;
    if (this != &other){
        Animal::operator=(other);
    }
    return (*this);
}

Dog::~Dog(){
    std::cout << RED << "Dog Destructor called." << std::endl;
}

void Dog::makeSound() const{
    std::cout << YELLOW << "Dog does: BAU BAU!" << std::endl;
}
