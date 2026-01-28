/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 21:45:00 by francesca         #+#    #+#             */
/*   Updated: 2026/01/28 11:16:08 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

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

class WrongAnimal{
    protected:
    std::string type;
    
    public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal&operator=(const WrongAnimal& other);
    ~WrongAnimal();

    void makeSound() const;
    std::string getType();
};

#endif