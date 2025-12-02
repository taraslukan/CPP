#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name): name(name) {}
Zombie::Zombie(): name("") {}
Zombie::~Zombie() { std::cout << this->name << ": destroyed\n"; }

void Zombie::setName(const std::string& n)
{
	this->name = n;
}

void Zombie::announce()
{
  std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

