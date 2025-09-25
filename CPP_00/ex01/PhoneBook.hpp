#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>

class PhoneBook
{
	private:
		Contact	ContactsData[8];
		size_t	size;
	private:
		static int			check_stream(std::istream &in = std::cin);
		static std::string	formated_text(const std::string &field);
		void				display_contact(std::ostream &out = std::cout, int index);
		void				add_contact();
		void				search_contact();
		void				exit_phonebook();
		void				execute_command(const std::string &command);

	public:
		PhoneBook();
		void run();
};

#endif
