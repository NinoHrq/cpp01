#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

PhoneBook::PhoneBook() : totalContacts(0), indexToReplace(0) {}

void PhoneBook::addContact() {
	contacts[indexToReplace].setInfo();
	if (!contacts[indexToReplace].isValid()) {
		std::cout << "Invalid contact. Skipping.\n";
		return;
	}
	indexToReplace = (indexToReplace + 1) % 8;
	if (totalContacts < 8)
		totalContacts++;
	std::cout << "Contact added!\n";
}

void PhoneBook::searchContact() const {
	if (totalContacts == 0) {
		std::cout << "No contacts yet.\n";
		return;
	}
	std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
	for (int i = 0; i < totalContacts; ++i)
		contacts[i].displayShort(i);

	std::cout << "Enter index: ";
	int i;
	std::cin >> i;
	if (std::cin.fail() || i < 0 || i >= totalContacts) {
		std::cout << "Invalid index\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}
	std::cin.ignore();
	contacts[i].displayFull();
}
