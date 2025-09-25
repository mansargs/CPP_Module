#include <limits>
#include <iomanip>
#include "PhoneBook.hpp"

int PhoneBook::check_stream(std::istream &in = std::cin)
{
	if (in.eof())
		return 1;
	if (in.fail())
	{
		std::cerr << "Input has failed\n";
		in.clear();
		in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return 1;
	}
	else if (in.bad())
	{
		std::cerr << "Serious input problem\n";
		in.clear();
		in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::exit(1);
	}
	return 0;
}

static std::string	formated_text(const std::string &field)
{
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return field;
}

void	PhoneBook::display_contact(std::ostream &out = std::cout, int index)
{
	out << std::right;
	out << std::setw(10) << index + 1 << '|'
		<< std::setw(10) << formated_text(ContactsData[index].FirstName) << '|'
		<< std::setw(10) << formated_text(ContactsData[index].LastName) << '|'
		<< std::setw(10) << formated_text(ContactsData[index].)

}

void PhoneBook::search_contact()
{
	std::string index;

	while (1)
	{
		std::cout << "Enter the index of the contact: ";
		std::cin >> index;
		if (check_stream(std::cin))
			continue ;
		if (index.length() > 1 || index[0] < '1' || index[0] > '8')
		{
			std::cout << "Invalid index\n";
			continue ;
		}


	}
}

void	PhoneBook::run()
{
	std::string	command;

	while(1)
	{
		std::cout << "Enter the command (ADD, SEARCH, EXIT)\n";
		std::getline(std::cin, command);
		if (check_stream(std::cin))
			return ;
		if (command == "ADD")
			add_contact();
		else if (command == "SEARCH")
			search_contact();
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
