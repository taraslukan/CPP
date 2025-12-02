#include <iostream>
#include <string>
#include "contact.hpp"
#include "phonebook.hpp"

int main()
{
	PhoneBook first;
	int choice = 0;
	bool looper = true;

	while (looper)
	{
		std::cout << "Hi, what can I do?" << std::endl;
		std::cout << "1 --> ADD Contact\n2 --> SEARCH Contact\n3 --> EXIT" << std::endl;
		std::cin >> choice;

		while (!(choice == 1 || choice == 2 || choice == 3))
		{
			std::cout << "Invalid option. Please choose 1, 2 or 3." << std::endl;
			std::cin >> choice;
		}

		if (choice == 1)
			first.addContact();
		else if (choice == 2)
			first.searchContact();
		else if (choice == 3)
		{
			std::cout << "Goodbye!" << std::endl;
			looper = false;
		}
	}
	return 0;
}
