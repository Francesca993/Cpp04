/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal1.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 21:45:00 by francesca         #+#    #+#             */
/*   Updated: 2026/01/09 10:22:05 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL1_HPP
#define ANIMAL1_HPP

//–––––––––––––––––––––––––––––
// Colors for Output
// –––––––––––––––––––––––––––––
# define GREEN "\033[32m"
# define ORANGE "\033[38;5;214m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define RESET "\033[0m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"

#include <iostream>
#include <string>

class Animal{
    protected:
    std::string type;
    
    public:
    Animal();
    Animal(const Animal& other);
    Animal&operator=(const Animal& other);
    virtual ~Animal();

    virtual void makeSound() const;
    std::string getType() const;
};

#endif