/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:15:01 by francesca         #+#    #+#             */
/*   Updated: 2026/02/04 12:12:31 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#define MAXSRC 4

#include "IMateriaSource.hpp"
#include "Debug.hpp"

class MateriaSource :public IMateriaSource {
    private:
    AMateria* _templates[MAXSRC];
    
    public:
    MateriaSource();
    MateriaSource(MateriaSource const&);
    MateriaSource& operator=(MateriaSource const&);
    ~MateriaSource();

    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};

#endif