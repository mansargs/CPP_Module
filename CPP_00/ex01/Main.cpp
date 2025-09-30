#include <limits>
#include <iomanip>
#include <cstdlib>
#include "PhoneBook.hpp"

std::string PhoneBook::readLine(const std::string &prompt, bool (*check)(const std::string &))
{
	std::string input;
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof())
				std::cout << "\nEOF detected. Exiting...\n";
			else
				std::cout << "\nStream has failed\n";
			std::exit(0);
		}
		input = trim_spaces_nonprintable(input);
		if (input.empty())
		{
			std::cout << "Invalid field try again. Field can't be empty, nonprintable symbols or all spaces\n";
			continue;
		}
		if (!check || check(input))
			break;
	}
	return input;
}

void PhoneBook::displayAllContacts() const
{
	std::cout << std::right;
	std::cout << std::setw(10) << "Index" << '|'
		  << std::setw(10) << "First Name" << '|'
		  << std::setw(10) << "Last Name" << '|'
		  << std::setw(10) << "Nickname" << '\n';
	for (size_t i = 0; i < size; ++i)
	{
        std::cout << std::setw(10) << i + 1 << '|'
        << std::setw(10) << formattedText(contactsData[i].getFirstName()) << '|'
        << std::setw(10) << formattedText(contactsData[i].getLastName()) << '|'
        << std::setw(10) << formattedText(contactsData[i].getNickname()) << '\n';
	}
	std::cout << std::left;
}

void PhoneBook::displayContact(int index) const
{
	std::cout << "Firstname: " << contactsData[index].getFirstName() << '\n'
			  << "Lastname: " << contactsData[index].getLastName() << '\n'
			  << "Nickname: " << contactsData[index].getNickname() << '\n'
			  << "Phone number: " << contactsData[index].getPhoneNumber() << '\n'
			  << "Darkest Secret: " << contactsData[index].getDarkestSecret() << '\n';
}

void PhoneBook::addContact()
{
	Contact newContact;

	newContact.setFirstName(readLine("Enter Firstname: ", PhoneBook::validateNames));
	newContact.setLastName(readLine("Enter Lastname: ", PhoneBook::validateNames));
	newContact.setNickname(readLine("Enter Nickname: ", PhoneBook::validateNickname));
	newContact.setPhoneNumber(readLine("Enter Phone number: ", PhoneBook::validatePhoneNumber));
	newContact.setDarkestSecret(readLine("Enter Darkest secret: ", NULL));

	contactsData[next] = newContact;
	next = (next + 1) % max_size;
	if (size < max_size)
		++size;
}

void PhoneBook::searchContact()
{
	if (size == 0)
	{
		std::cout << "Phonebook is empty\n";
		return;
	}
	while (true)
	{
		try
		{
			displayAllContacts();
		}
		catch (const std::exception &e)
		{
			std::cout << std::endl << e.what() << std::endl;
			std::exit(1);
		}
		std::string choice = readLine("Enter the index of the contact: ", NULL);
		if (choice.length() != 1 || choice[0] < '1' || choice[0] > '0' + static_cast<int>(size))
		{
			std::cout << "Invalid index\n";
			continue;
		}
		displayContact(choice[0] - '0' - 1);
        while (true)
        {
            choice = readLine("Search again (Y/N): ", NULL);
            if (choice.length() == 1 && (choice[0] == 'Y' || choice[0] == 'y' || choice[0] == 'N' || choice[0] == 'n'))
                break;
        }
        if (choice == "N" || choice == "n")
            break;
	}
}

void PhoneBook::run()
{
	while (true)
	{
		std::string command = readLine("Enter the command (ADD, SEARCH, EXIT) : ", NULL);

		if (command == "ADD")
			addContact();
		else if (command == "SEARCH")
			searchContact();
		else if (command == "EXIT")
			std::exit(0);
		else
			std::cout << "Error: command must be ADD, SEARCH or EXIT\n";
	}
}

int main()
{
	PhoneBook instance;
	instance.run();
}
