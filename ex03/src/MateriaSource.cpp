/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:20:39 by francesca         #+#    #+#             */
/*   Updated: 2026/02/04 10:43:19 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"


MateriaSource::MateriaSource() {
    for (int i = 0; i < MAXSRC; i++)
    {
        this->_templates[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(MateriaSource const& other){
    if (this == &other)
        return(*this);
    for (int i = 0; i < MAXSRC; i++)
    {
        if (this->_templates[i])
            delete this->_templates[i];
        if (other._templates[i])
            this->_templates[i] = other._templates[i]->clone();
        else
            this->_templates[i] = NULL;
    }
    return(*this);
        
}

MateriaSource::MateriaSource(MateriaSource const& other) {
    *this = other;
}

void MateriaSource::learnMateria(AMateria* src){
    if (src)
    {
        for (int i = 0; i < MAXSRC; i++)
        {
            if (this->_templates[i] == NULL)
            {
                this->_templates[i] = src->clone();
                return;
            }
        }
        std::cout << RED << "Templates Full. Delete Materia." << std::endl;
        return ;
    }
    std::cout << RED << "INvalid Materia." << std::endl;
    return ;
}

MateriaSource::~MateriaSource(){
    for (int i = 0; i < MAXSRC; i++)
    {
        if (this->_templates[i])
            delete this->_templates[i];
    }
}

AMateria* MateriaSource::createMateria(std::string const & type){
    int i = 0;
    while (i < MAXSRC)
    {
        if (type == _templates[i]->getType() && _templates[i])
            return(this->_templates[i]->clone());
        else    
            i++;
    }
    return(NULL);
}



/*
        
class MateriaSource :public IMateriaSource {
    private:
    AMateria* _templates[4];
    
    public:
    MateriaSource();
    MateriaSource(MateriaSource const&);
    MateriaSource& operator=(MateriaSource const&);
    ~MateriaSource() {};

    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};
*/