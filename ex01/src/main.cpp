/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 22:17:15 by francesca         #+#    #+#             */
/*   Updated: 2026/01/29 12:05:07 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

static void separator(const std::string& title)
{
    std::cout << "\n==================== " << title << " ====================\n";
}

int main()
{
    separator("CLASS DECLARATION");
    const int n = 10;
    Animal* arrAnimals[n];
    for (int i = 0; i < n; i++)
    {
        if ((i % 2) == 0)
            arrAnimals[i] = new Dog();
        else
            arrAnimals[i] = new Cat();
    }
    separator("ARRAY ANIMALS TYPE");
    for (int i = 0; i < n; i++ )
    {
        std::cout << arrAnimals[i]->getType() << " " << std::endl;
    }
    separator("ARRAY ANIMALS SOUNDS");
    for (int i = 0; i < n; i++)
    {
        arrAnimals[i]->makeSound();
    }

    separator("DESTRUCTOR");
    for (int i = 0; i < n; i++)
    {
        delete arrAnimals[i];
    }
    
    separator("DEEP COPY TEST");

    Dog* a = new Dog();
    
    std::cout << "Gio idea 1 before: " << a->getIdea(1) << std::endl;
    a->setIdea(1, "Pappa");
    std::cout << "Gio idea 1 after set: " << a->getIdea(1) << std::endl;

    Dog* b = new Dog(*a);
    std::cout << "b idea 1 after copy: " << b->getIdea(1) << std::endl;
    b->setIdea(1, "Food");
    std::cout << "b idea 1 after set: " << b->getIdea(1) << std::endl;
    std::cout << "And Giotto idea 1 after copy and b set: " << a->getIdea(1) << std::endl;
    
    Dog c;
    
    c.setIdea(1, "BBB");
    std::cout << a->getIdea(1) << std::endl;
    std::cout << c.getIdea(1) << std::endl;
    
    delete a;
    delete b;
    
    return(0);
    
}

/*
int main()
{
    separator("CLASS DECLARATION");
    Animal* meta = new Animal();
    Animal* giotto = new Dog();
    Animal* micia = new Cat();

    separator("new dog & cat");
    Dog* a = new Dog();
    Cat* b = new Cat();
    
    separator("GET TYPE");
    std::cout << meta->getType() << " " << std::endl;
    std::cout << giotto->getType() << " " << std::endl;
    std::cout << micia->getType() << " " << std::endl;
    std::cout << a->getType() << " " << std::endl;
    std::cout << b->getType() << " " << std::endl;
    
    separator("WLL OUTPUT THE RIGHT SOUND");
    meta->makeSound();
    giotto->makeSound();
    micia->makeSound();
    a->makeSound();
    b->makeSound();

    separator("ONLY A CAN PRINT IDEAS");
    a->printIdeas();

    separator("DESTRUCTOR");
    delete meta;
    delete giotto;
    delete micia;

    delete a;
    delete b;
    
    return (0);
}
*/