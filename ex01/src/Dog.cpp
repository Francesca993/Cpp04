/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 22:11:35 by francesca         #+#    #+#             */
/*   Updated: 2026/01/29 11:57:00 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal(){
    std::cout << RED << "Dog Constructor called." << RESET << std::endl;
    this->type = "Dog";
    this->_brain = new Brain();
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

void Dog::printIdeas() const {
    this->_brain->printIdeas();
}

std::string Dog::getIdea(int index) const{
    return(this->_brain->getIdea(index));
}

void Dog::setIdea(int index, std::string idea){
    this->_brain->setIdea(index, idea);
}