#include "Zombie.hpp"

int main() {
  Zombie* p = newZombie("Heapster"); // heap
  p->announce();
  delete p;                          // IMPORTANTISSIMO

  randomChump("Stacky");             // stack

  return 0;
}
