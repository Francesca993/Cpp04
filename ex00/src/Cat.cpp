/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 22:11:35 by francesca         #+#    #+#             */
/*   Updated: 2026/01/27 14:32:38 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal(){
    type = "Cat";
    std::cout << BLUE << "Cat Constructor called." << std::endl;
}

Cat::Cat(const Cat& other): Animal(other){
    std::cout << BLUE << "Cat Copy Constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& other){
    std::cout << BLUE << "Cat Copy Assign called." << std::endl;
    if (this != &other){
        Animal::operator=(other);
    }
    return (*this);
}

Cat::~Cat(){
    std::cout << BLUE << "Cat Destructor called." << std::endl;
}

void Cat::makeSound()const {
    std::cout << YELLOW << "Cat does: MIAO MIAO!" << std::endl;
}