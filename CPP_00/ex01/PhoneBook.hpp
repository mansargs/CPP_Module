#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>

class PhoneBook
{
	private:
		static const int max_size = 8;
		Contact contactsData[max_size];
		size_t size;
		size_t next;

	private:
		static std::string formatText(const std::string &field);
		static int checkStream();
		static std::string trim(const std::string &s);
		static std::string readValue(const std::string &prompt);

		void displayAllContacts() const;
		void displayContact(int index) const;
		void addContact();
		void searchContact();

	public:
		PhoneBook();
		void run();
};

#endif
