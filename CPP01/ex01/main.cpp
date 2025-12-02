#include "Zombie.hpp"
#include <cstddef>

Zombie* zombieHorde(int N, std::string name);

int main() {
  int N = 5;
  Zombie* h = zombieHorde(N, "Zed");
  if (!h) return 0;

  for (int i = 0; i < N; ++i)
    h[i].announce();

  delete[] h; // IMPORTANTISSIMO (delete[])
  return 0;
}
