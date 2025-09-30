#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : size(0), next(0) {}

bool PhoneBook::validateNames(const std::string &name)
{
	for (size_t i = 0; i < name.length(); ++i)
	{
		if (std::isalpha(static_cast<unsigned char>(name[i]))
			|| name[i] == ' ')
				continue ;
		std::cout << "Field must contain only letters or spaces\n";
		return false;
	}
	return true;
}

bool PhoneBook::validateNickname(const std::string &nickname)
{
	for (size_t i = 0; i < nickname.length(); ++i)
	{
		if (std::isalnum(static_cast<unsigned char>(nickname[i]))
			|| nickname[i] == '_')
				continue ;
		std::cout << "Field must contain only letters, numbers or underscore\n";
		return false;
	}
	return true;
}

bool PhoneBook::validatePhoneNumber(const std::string &phone)
{
	size_t i = 0;
	if (!phone.empty())
	{
		if (phone[i] == '+')
			++i;
	}
	for (; i < phone.length(); ++i)
	{
		if (std::isdigit(static_cast<unsigned char>(phone[i])))
				continue ;
		std::cout << "Field must contain only digits\n";
		return false;
	}
	return true;
}

std::string PhoneBook::trim_spaces_nonprintable(const std::string &s)
{
	size_t start = 0;
	while (start < s.length() && (std::isspace(static_cast<unsigned char>(s[start]))
			|| !std::isprint(static_cast<unsigned char>(s[start]))))
		++start;
	if (start == s.length())
		return "";
	size_t end = s.length() - 1;
	while (end > start && (std::isspace(static_cast<unsigned char>(s[end]))
			|| !std::isprint(static_cast<unsigned char>(s[end]))))
		--end;
	return s.substr(start, end - start + 1);
}

std::string PhoneBook::formattedText(const std::string &field)
{
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return field;
}
