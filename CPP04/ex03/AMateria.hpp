#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

using std::string;
using std::cout;
using std::endl;

class AMateria
{
    protected:
        string  _type;
    public:
        AMateria();
        AMateria(std::string const &type);
        virtual ~AMateria();
        AMateria(const AMateria &old_obj);

        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);


        AMateria &operator=(const AMateria *ref);

};

#endif