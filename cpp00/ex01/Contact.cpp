#include "Contact.hpp"
#include <iostream>
#include <iomanip>

void Contact::setInfo() {
	std::cout << "First name: ";
	std::getline(std::cin, firstName);
	std::cout << "Last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Phone number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, darkestSecret);
}

bool isalpha(std::string chare)
{
	for(unsigned long i = 0; i < chare.length(); i++)
	{
		if ((chare[i] < 65 || chare[i] > 90) && (chare[i] < 97 || chare[i] > 122))
			return false;
	}
	return true;
}
bool isnum (std::string chare)
{
	for(unsigned long i = 0; i < chare.length(); i++)
	{
		if (chare[i] < 48 || chare[i] > 57)
			return false;
	}
	return true;
}


bool Contact::isValid() const {
	if (!isalpha(firstName) || !isalpha(lastName))
		return (false);
	if (!isnum(phoneNumber))
		return false;
	return !firstName.empty() && !lastName.empty() && !nickname.empty()
		&& !phoneNumber.empty() && !darkestSecret.empty();
}

void Contact::displayShort(int index) const {
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName);
	std::cout << "|" << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName);
	std::cout << "|" << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname);
	std::cout << "|" << std::endl;
}

void Contact::displayFull() const {
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
}
