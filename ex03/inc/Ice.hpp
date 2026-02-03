/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:09:17 by francesca         #+#    #+#             */
/*   Updated: 2026/02/02 20:22:47 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
    public:
    Ice(); //constructor
    Ice(const Ice& other); //cpy constr
    Ice&operator=(const Ice& other); //operator
    ~Ice(); //destructor

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif