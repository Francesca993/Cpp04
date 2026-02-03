/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:27:47 by francesca         #+#    #+#             */
/*   Updated: 2026/02/02 21:00:43 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "Debug.hpp"

class ICharacter;

class AMateria
{
    protected:
        std::string _type;
    
    public:
        AMateria(std::string const & type); //Constructor
        AMateria(const AMateria& other); //cpyCnstr
        AMateria&operator=(const AMateria& other); //Operator
        virtual ~AMateria(); //Destructor


        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target); 
        /* The use(ICharacter&) member function will display:
        • Ice: "* shoots an ice bolt at <name> *"
        • Cure: "* heals <name>’s wounds *"*/
};

#endif