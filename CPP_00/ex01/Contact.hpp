#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;
		void		setFirstName(const std::string &s);
		void		setLastName(const std::string &s);
		void		setNickname(const std::string &s);
		void		setPhoneNumber(const std::string &s);
		void		setDarkestSecret(const std::string &s);
};

#endif
