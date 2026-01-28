/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 22:17:15 by francesca         #+#    #+#             */
/*   Updated: 2026/01/28 15:23:59 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

static void separator(const std::string& title)
{
    std::cout << "\n==================== " << title << " ====================\n";
}

int main()
{
separator("RIGHT CLASSES");
Animal* meta = new Animal();
Animal* j = new Dog();
Animal* i = new Cat();
Dog    *giotto = new Dog();

std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
giotto->makeSound();
giotto->getIdeas();
meta->makeSound();


delete meta;
delete j;
delete i;
/*
separator("WRONG CLASSES");
WrongAnimal *x = new WrongAnimal();
WrongAnimal *y = new WrongCat();
std::cout << x->getType() << " " << std::endl;
std::cout << y->getType() << " " << std::endl;
separator("Wrong animal sound");
x->makeSound();
separator("Wrong cat sound");
y->makeSound();
separator("Wrong classes destructors");
delete x;
delete y;
*/

return 0;
}