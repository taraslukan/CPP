#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
private:
	std::string name;
	Weapon* weapon; // può essere assente

public:
	HumanB(const std::string& name);
	~HumanB();

	void setWeapon(Weapon& weapon);
	void attack() const;
};

#endif
