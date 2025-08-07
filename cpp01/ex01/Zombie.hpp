#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>
# include <iomanip>


class Zombie {
private:
	std::string name;
public:
    void setName(std::string name);
    Zombie();
    Zombie(std::string name);
    ~Zombie();
	void announce(void);
};

#endif