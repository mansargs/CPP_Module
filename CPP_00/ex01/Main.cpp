#include <limits>
#include <iomanip>
#include <cstdlib>
#include "PhoneBook.hpp"

int PhoneBook::checkStream()
{
	if (std::cin.eof())
		return 1;
	if (std::cin.fail())
	{
		std::cerr << "Input has failed\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return 1;
	}
	else if (std::cin.bad())
	{
		std::cerr << "Serious input problem\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::exit(1);
	}
	return 0;
}

std::string	formatedText(const std::string &field)
{
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return field;
}

std::string PhoneBook::trim(const std::string &s)
{
	size_t start = 0;
	while (start < s.length() && std::isspace(static_cast<unsigned char>(s[start])))
		++start;
	if (start == s.length())
		return "";
	size_t end = s.length() - 1;
	while (end > start && std::isspace(static_cast<unsigned char>(s[end])))
		--end;
	return s.substr(start, end - start + 1);
}

void	PhoneBook::displayAllContacts() const
{
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << std::right;
		std::cout << std::setw(10) << i + 1 << '|'
			<< std::setw(10) << formatedText(contactsData[i].getFirstName()) << '|'
			<< std::setw(10) << formatedText(contactsData[i].getLastName()) << '|'
			<< std::setw(10) << formatedText(contactsData[i].getNickname()) << std::endl;
	}
	std::cout << std::left;
}

void	PhoneBook::displayContact(int index) const
{
	std::cout << "Firstname: " << contactsData[index].getFirstName() << std::endl
			  << "Lastname: " << contactsData[index].getLastName() << std::endl
			  << "Nickname: " << contactsData[index].getNickname() << std::endl
			  << "Phone number: " << contactsData[index].getPhoneNumber() << std::endl
			  << "Darkest Secret: " << contactsData[index].getDarkestSecret() << std::endl;
}

void PhoneBook::searchContact()
{
	std::string choice;

	while (true)
	{
		displayAllContacts();
		std::cout << "Enter the index of the contact: ";
		std::cin >> choice;
		if (checkStream())
			break;
		choice = trim(choice);
		if (choice.length() != 1 || choice[0] < '1' || choice[0] > '0' + max_size)
		{
			std::cout << "Invalid index\n";
			continue;
		}
		displayContact(choice[0] - '0' - 1);
		std::cout << "Search again (Y/N): ";
		std::cin >> choice;
		if (checkStream())
			break;
		choice = trim(choice);
		if (choice.length() != 1 || (choice[0] != 'Y' && choice[0] != 'y'))
			break;
	}
}

std::string PhoneBook::readValue(const std::string &prompt)
{
	std::string input;
	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (checkStream())
			continue ;
		input = trim(input);
		if (!input.empty())
		{
			std::cout << "Field can't contain only spaces\n";
			continue ;
		}
		std::cout << "Field can't be empty. Please try again.\n";
	}
	return input;
}
std::string foo()
{
	return (std::string("asd"));
}
void PhoneBook::addContact()
{
	Contact newContact;

	newContact.setFirstName(PhoneBook::readValue("Enter Firstname: "));
	newContact.setLastName(PhoneBook::readValue("Enter Lastname: "));
	newContact.setNickname(PhoneBook::readValue("Enter Nickname: "));
	newContact.setPhoneNumber(PhoneBook::readValue("Enter Phone number: "));
	newContact.setDarkestSecret(PhoneBook::readValue("Enter Darkest secret: "));
	contactsData[next] = newContact;
	next = (next + 1) % max_size;
	if (size < max_size)
		++size;
}


void	PhoneBook::run()
{
	std::string	command;

	while(1)
	{
		std::cout << "Enter the command (ADD, SEARCH, EXIT)\n";
		std::getline(std::cin, command);
		if (checkStream())
			return ;
		if (command == "ADD")
			addContact();
		else if (command == "SEARCH")
			searchContact();
		else if (command == "EXIT")
			std::exit(0);
		else
			std::cout << "Command not found: Write the command in capital letters\n";
	}
}

int main()
{
	PhoneBook	instance;

	instance.run();
}
