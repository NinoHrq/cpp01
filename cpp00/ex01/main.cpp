#include "PhoneBook.hpp"
#include <iostream>

int main() {
	PhoneBook book;
	std::string command;

	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			break;
		if (command == "ADD")
			book.addContact();
		else if (command == "SEARCH")
			book.searchContact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Unknown command.\n";
	}
	return 0;
}
