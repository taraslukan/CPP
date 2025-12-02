#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
  if (N <= 0) return NULL;
  Zombie* h = new Zombie[N];         // richiede costruttore di default
  for (int i = 0; i < N; ++i)
    h[i].setName(name);
  return h;
}
