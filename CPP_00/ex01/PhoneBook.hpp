#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	ContactsData[8];
		size_t	size;
	public:
		PhoneBook();
};

#endif
