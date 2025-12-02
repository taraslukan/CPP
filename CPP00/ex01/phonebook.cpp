#include "phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

// funzione helper per leggere una stringa non vuota
static std::string prompt(const std::string &msg)
{
	std::string input;

	while (true)
	{
		std::cout << msg;
		if (!std::getline(std::cin, input))
		{
			// EOF o errore: usciamo in modo pulito
			std::cout << "\nInput terminated." << std::endl;
			std::exit(0);
		}
		if (!input.empty())
			return input;
		std::cout << "Field cannot be empty. Try again." << std::endl;
	}
}

// stampa una colonna larga 10 caratteri, tronca con '.' se troppo lunga
static void printColumn(const std::string &str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << str;
}

PhoneBook::PhoneBook() : index(0)
{
}

void PhoneBook::addContact()
{
	// siccome nel main usi 'std::cin >> choice', c'è un '\n' rimasto nel buffer:
	// svuotiamo il resto della riga PRIMA di usare getline.
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	Contact &c = this->user[this->index];

	c.setName(prompt("First name: "));
	c.setSurname(prompt("Last name: "));
	c.setNickname(prompt("Nickname: "));
	c.setPhoneNumber(prompt("Phone number: "));
	c.setDarkestSecret(prompt("Darkest secret: "));

	std::cout << "Contact saved in slot " << this->index << "." << std::endl;

	this->index = (this->index + 1) % 8; // ruota fra 0 e 7
}

void PhoneBook::searchContact()
{
	// svuota eventuale '\n' rimasto se arriviamo qui dopo '>>'
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index| FirstName| LastName | Nickname |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	bool any = false;
	for (int i = 0; i < 8; i++)
	{
		if (this->user[i].isEmpty())
			continue;

		any = true;
		std::cout << "|";
		std::cout << std::setw(10) << i << "|";
		printColumn(this->user[i].getFirstName());
		std::cout << "|";
		printColumn(this->user[i].getLastName());
		std::cout << "|";
		printColumn(this->user[i].getNickname());
		std::cout << "|" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;

	if (!any)
	{
		std::cout << "No contacts stored yet." << std::endl;
		return;
	}

	std::string idxStr;
	std::cout << "Enter index (0-7): ";
	if (!std::getline(std::cin, idxStr))
	{
		std::cout << "\nInput terminated." << std::endl;
		std::exit(0);
	}

	if (idxStr.length() != 1 || idxStr[0] < '0' || idxStr[0] > '7')
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}

	int idx = idxStr[0] - '0';
	if (this->user[idx].isEmpty())
	{
		std::cout << "No contact in this slot." << std::endl;
		return;
	}

	std::cout << "First name: "     << this->user[idx].getFirstName()     << std::endl;
	std::cout << "Last name: "      << this->user[idx].getLastName()      << std::endl;
	std::cout << "Nickname: "       << this->user[idx].getNickname()      << std::endl;
	std::cout << "Phone number: "   << this->user[idx].getPhoneNumber()   << std::endl;
	std::cout << "Darkest secret: " << this->user[idx].getDarkestSecret() << std::endl;
}
