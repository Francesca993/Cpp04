/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 22:11:35 by francesca         #+#    #+#             */
/*   Updated: 2026/01/28 11:20:23 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal(){
    type = "WrongCat";
    std::cout << MAGENTA << "WrongCat Constructor called." << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other){
    std::cout << MAGENTA << "WrongCat Copy Constructor called." << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other){
    std::cout << MAGENTA << "WrongCat Copy Assign called." << RESET << std::endl;
    if (this != &other){
        WrongAnimal::operator=(other);
    }
    return (*this);
}

WrongCat::~WrongCat(){
    std::cout << MAGENTA << "WrongCat Destructor called." << RESET << std::endl;
}

void WrongCat::makeSound()const {
    std::cout << MAGENTA << "WrongCat does: MIAO MIAO!" << RESET << std::endl;
}