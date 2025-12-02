#include "Zombie.hpp"
void randomChump(std::string name) {
  Zombie z(name);   // stack
  z.announce();
} // distruzione automatica qui
