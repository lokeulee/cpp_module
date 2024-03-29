#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

using std::cout;
using std::endl;
using std::string;

class AAnimal
{
	protected:
		string _type;
	public:
		AAnimal();
		virtual ~AAnimal();
		AAnimal(const AAnimal &old_obj);
		virtual void 	makeSound() const = 0;
		// virtual Brain 	*getBrain(void) const = 0;
		const string	&getType( void ) const;
		AAnimal &operator=(const AAnimal &ref);

};

#endif