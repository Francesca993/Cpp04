/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:13:40 by francesca         #+#    #+#             */
/*   Updated: 2026/01/29 11:54:41 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Default Brain created." << std::endl;
    for (int i = 0; i < 100; i++)
    {
        std::ostringstream oss;
        oss << "Idea" << i;
        this->ideas[i] = oss.str();
    }
}

Brain::Brain(const Brain& other){
    std::cout << "Copy Constructor Brain called." << std::endl;
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = other.ideas[i];
    }
    
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Operator Assign Brain called." << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = other.ideas[i];
        }
    }
    return(*this);
}

Brain::~Brain(){
    std::cout << "Destructor Brain called." << std::endl;
}


std::string Brain::getIdea(int index)const {
    if (index < 0 || index >= 100)
        return("null");
    else
        return(this->ideas[index]);
}
// void setIdea(int index, std::string idea);
void Brain::setIdea(int index, std::string idea){
    if (index < 0 || index >= 100)
        return ;
    else
        this->ideas[index] = idea;
}

void Brain::printIdeas() const {
    for(int i = 0; i < 100; i++)
    {
        std::cout << this->ideas[i] << std::endl;
    }
}
