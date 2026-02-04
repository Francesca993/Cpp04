/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 22:11:35 by francesca         #+#    #+#             */
/*   Updated: 2026/02/04 11:21:43 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(): Animal(){
    this->type = "Cat";
    this->_brain = new Brain();
    std::cout << BLUE << "Cat Constructor called." << RESET << std::endl;
}

Cat::Cat(const Cat& other): Animal(other){
    this->_brain = new Brain(*other._brain);
    std::cout << BLUE << "Cat Copy Constructor called." << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& other){
    std::cout << BLUE << "Cat Copy Assign called." << RESET << std::endl;
    if (this != &other)
    {
        delete _brain;
        Animal::operator=(other);
        _brain = new Brain(*other._brain);
    }
    return (*this);
}

Cat::~Cat(){
    delete _brain;
    std::cout << BLUE << "Cat Destructor called." << RESET << std::endl;
}

void Cat::makeSound()const {
    std::cout << BLUE << "Cat does: MIAO MIAO!" << RESET << std::endl;
}

std::string Cat::getIdea(int index) const{
    return(this->_brain->getIdea(index));
}

void Cat::setIdea(int index, std::string idea){
    this->_brain->setIdea(index, idea);
}

