/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 09:43:37 by francesca         #+#    #+#             */
/*   Updated: 2026/01/29 11:55:03 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

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
#include <sstream>
#include "Animal.hpp"

class Brain{
    protected:
    std::string ideas[100];

    public:
    Brain();
    Brain(const Brain& other);
    Brain&operator=(const Brain& other);
    ~Brain();
    
    // Getters
    void printIdeas() const;
    std::string getIdea(int index) const;
    void setIdea(int index, std::string idea);
};
#endif