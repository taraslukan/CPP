#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name) : name(name), weapon(0) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}

void HumanB::attack() const {
	// Il subject non richiede output senza arma; stampiamo solo se c'è un'arma,
	// così l'output coincide con l'esempio fornito.
	if (this->weapon) {
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	}
}
