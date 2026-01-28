/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 22:11:35 by francesca         #+#    #+#             */
/*   Updated: 2026/01/28 15:08:59 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal(){
    this->type = "Dog";
    this->_brain = new Brain();
    std::cout << RED << "Dog Constructor called." << RESET << std::endl;
}
Dog::Dog(const Dog& other):Animal(other){
    this->_brain = new Brain(*other._brain);
    std::cout << RED << "Dog Copy Constructor called." << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other){
    std::cout << RED << "Dog Copy Assign called." << RESET << std::endl;
    if (this != &other){
        delete this->_brain;
        Animal::operator=(other);
        this->_brain = new Brain(*other._brain);
    }
    return (*this);
}

Dog::~Dog(){
    delete _brain;
    std::cout << RED << "Dog Destructor called." << RESET << std::endl;
}

void Dog::makeSound() const {
    std::cout << RED << "Dog does: BAU BAU!" << RESET << std::endl;
}