/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:02:35 by francesca         #+#    #+#             */
/*   Updated: 2026/02/02 17:14:07 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
    public:
    Cure(); //constructor
    Cure(const Cure& other); //cpy constr
    Cure&operator=(const Cure& other); //operator
    ~Cure(); //destructor

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif

/*
Of course, their member function
clone() will return a new instance of the same type (i.e., if you clone an Ice Materia,
you will get a new Ice Materia).
The use(ICharacter&) member function will display:
• Ice: "* shoots an ice bolt at <name> *"
• Cure: "* heals <name>’s wounds *"
<name> is the name of the Character passed as a parameter. Don’t print the angle
brackets (< and >).
While assigning a Materia to another, copying the type doesn’t make
sense.1


        protected:
        std::string type;
    
    public:
        AMateria(std::string const & type); //Constructor
        AMateria(const AMateria& other); //cpyCnstr
        AMateria&operator=(const AMateria& other); //Operator
        virtual ~AMateria(); //Destructor


        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target); 
*/