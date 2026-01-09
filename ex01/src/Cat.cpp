/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 22:11:35 by francesca         #+#    #+#             */
/*   Updated: 2026/01/09 10:20:35 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(){
    type = "Cat";
    std::cout << BLUE << "Cat Constructor called." << std::endl;
}
Cat::Cat(const Cat& other){
    std::cout << BLUE << "Cat Copy Constructor called." << std::endl;
    this->type = other.type;
}

Cat& Cat::operator=(const Cat& other){
    std::cout << BLUE << "Cat Copy Assign called." << std::endl;
    if (this != &other){
        this->type = other.type;
    }
    return (*this);
}

Cat::~Cat(){
    std::cout << BLUE << "Cat Destructor called." << std::endl;
}

void Cat::makeSound() const{
    std::cout << YELLOW << "Cat does: MIAO MIAO!" << std::endl;
}
