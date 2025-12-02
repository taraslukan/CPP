#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "contact.hpp"

class PhoneBook
{
private:
	Contact user[8];
	int     index;

public:
	PhoneBook();

	void addContact();
	void searchContact();
};

#endif
