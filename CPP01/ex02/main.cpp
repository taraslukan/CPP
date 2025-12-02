#include <iostream>
#include <string>

int main() {
  std::string s = "HI THIS IS BRAIN";
  std::string* stringPTR = &s;
  std::string& stringREF = s;

  std::cout << &s << "\n" << stringPTR << "\n" << &stringREF << "\n";
  std::cout << s << "\n" << *stringPTR << "\n" << stringREF << "\n";
  return 0;
}
