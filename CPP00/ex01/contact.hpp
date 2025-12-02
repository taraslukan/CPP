#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	std::string name;
	std::string surname;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact();

	void setName(std::string str);
	void setSurname(std::string str);
	void setNickname(std::string str);
	void setPhoneNumber(std::string str);
	void setDarkestSecret(std::string str);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

	bool isEmpty() const;
};

#endif
