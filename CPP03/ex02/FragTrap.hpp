#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		FragTrap();
	public:
		FragTrap(string name);
		~FragTrap();
		FragTrap (const FragTrap &old_obj);
		// void attack(const std::string& target);
		// void takeDamage(unsigned int amount);
		// void beRepaired(unsigned int amount);
		void highFivesGuys(void);
		FragTrap 	&operator=(const FragTrap &ref);

};

std::ostream &operator<<(std::ostream &out, FragTrap const &ref);


#endif