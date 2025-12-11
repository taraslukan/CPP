#include "contact.hpp"

Contact::Contact() : name(""), surname(""), nickname(""),
                     phoneNumber(""), darkestSecret("")
{
}

void Contact::setName(std::string str)
{
	this->name = str;
}

void Contact::setSurname(std::string str)
{
	this->surname = str;
}

void Contact::setNickname(std::string str)
{
	this->nickname = str;
}

void Contact::setPhoneNumber(std::string str)
{
	this->phoneNumber = str;
}

void Contact::setDarkestSecret(std::string str)
{
	this->darkestSecret = str;
}

std::string Contact::getFirstName() const
{
	return this->name;
}

std::string Contact::getLastName() const
{
	return this->surname;
}

std::string Contact::getNickname() const
{
	return this->nickname;
}

std::string Contact::getPhoneNumber() const
{
	return this->phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return this->darkestSecret;
}

bool Contact::isEmpty() const
{
	return this->name.empty(); // se non ha nome, lo consideriamo vuoto
}
