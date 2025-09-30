#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <cctype>

class PhoneBook
{
	private:
		static const size_t max_size = 8;
		Contact contactsData[max_size];
		size_t size;
		size_t next;

	private:
		static bool validateNames(const std::string &name);
		static bool validateNickname(const std::string &nickname);
		static bool validatePhoneNumber(const std::string &phone);
	private:
		std::string readLine(const std::string &prompt, bool (*check)(const std::string &));
		static std::string trim_spaces_nonprintable(const std::string &s);
		static std::string formattedText(const std::string &field);
		void displayAllContacts() const;
		void displayContact(int index) const;
		void addContact();
		void searchContact();

	public:
		PhoneBook();
		void run();
};

#endif
