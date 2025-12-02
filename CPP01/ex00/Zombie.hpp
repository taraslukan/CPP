#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>

class Zombie {
  std::string name;
public:
  Zombie(std::string name);
  Zombie();                  // utile per ex01 (riuso)
  ~Zombie();                 // stampa nome alla distruzione
  void setName(const std::string& n);
  void announce();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
