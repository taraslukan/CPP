#include <iostream>
#include <string>
#include "contact.hpp"
#include "phonebook.hpp"

int main()
{
	PhoneBook   first;
	std::string command;
	bool        looper = true;

	while (looper)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
		{
			// EOF (Ctrl+D) o errore input → usciamo puliti
			std::cout << std::endl << "Input terminated." << std::endl;
			break;
		}

		if (command == "ADD")
			first.addContact();
		else if (command == "SEARCH")
			first.searchContact();
		else if (command == "EXIT")
		{
			std::cout << "Goodbye!" << std::endl;
			looper = false;
		}
		else
		{
			std::cout << "Invalid command. Please type ADD, SEARCH or EXIT." << std::endl;
		}
	}
	return 0;
}

