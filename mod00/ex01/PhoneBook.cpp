/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:32:35 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/15 18:03:15 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_size = 0;
}

size_t PhoneBook::getSize(void)
{
	return (this->_size);
}

bool PhoneBook::_isNumber(const std::string &str)
{
	std::string::const_iterator it;

	it = str.begin();
	while (it != str.end())
	{
		if (std::isdigit(*it) == 0)
			return false;
		it++;
	}
	return true;
}

std::string PhoneBook::_formatColumn(std::string column)
{
	if (column.length() > 10)
	{
		column.resize(9);
		column.append(".");
		return (column);
	}
	else
		return (column);
}

void PhoneBook::_addSeparator(std::string title)
{
	const int size = 43;

	int result = (size - title.length()) / 2;
	std::cout << std::setfill('=') << std::setw(size - result) << title;
	std::cout << std::setfill('=') << std::setw(result) << "";
	std::cout << std::endl << std::setfill(' ') << std::setw(0);
}

Contact PhoneBook::_createContact(void)
{
	Contact     contact;
	std::string input;

	std::cout << std::endl;
	this->_addSeparator(" CREATE A NEW CONTACT ");
	std::cout << std::endl;
	std::cout << "What is your first name?" << std::endl;
	std::getline(std::cin, input);
	contact.setFirstName(input);
	std::cout << "What is your last name?" << std::endl;
	std::getline(std::cin, input);
	contact.setLastName(input);
	std::cout << "What is your nickname?" << std::endl;
	std::getline(std::cin, input);
	contact.setNickname(input);
	std::cout << "What is your phone number?" << std::endl;
	std::getline(std::cin, input);
	contact.setPhoneNumber(input);
	std::cout << "What is your darkest secret?" << std::endl;
	std::getline(std::cin, input);
	contact.setDarkestSecret(input);
	this->_addSeparator("");
	return (contact);
}

int PhoneBook::chooseCommand()
{
	std::string input;

	std::cout << "Choose a option: ";
	std::getline(std::cin, input);
	if (input.compare("1") == 0)
	{
		Contact contact = this->_createContact();
		if (contact.isCompleted())
			this->add(contact);
		else
			std::cerr << std::endl << "Error: incomplete contact" << std::endl;
	}
	else if (input.compare("2") == 0)
	{
		if (this->_size == 0)
			std::cout << std::endl << "Empty phone book" << std::endl;
		else
		{
			this->displaySavedContacts();
			size_t index = this->chooseIndex();
			if (index == 0)
				return (1);
			this->displayContactInformation(index);
		}
	}
	else if (input.compare("3") == 0)
		return (1);
	else if (std::cin.eof())
	{
		std::cout << std::endl;
		return (1);
	}
	else
	{
		std::cout << "Invalid option" << std::endl;
		return (this->chooseCommand());
	}
	return (0);
}

size_t PhoneBook::chooseIndex(void)
{
	Contact     contact;
	size_t      index;
	std::string input;

	if (this->_size == 0)
		return 0;
	std::cout << "Choose an index from 1 to " << this->_size << ": ";
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		return (0);
	}
	index = std::atoi(input.c_str());
	if (!this->_isNumber(input) || index == 0 || index > this->_size)
	{
		std::cerr << "Error: invalid index: " << input << std::endl;
		return (PhoneBook::chooseIndex());
	}
	return (index);
}

void PhoneBook::add(Contact contact)
{
	size_t index;

	if (contact.isCompleted())
	{
		this->_size++;
		if (this->_size > 8)
		{
			this->_size = 8;
			index = 0;
			while (++index < CONTACTS_MAX)
				this->_contacts[index - 1] = this->_contacts[index];
		}
		this->_contacts[this->_size - 1] = contact;
	}
}

void PhoneBook::displaySavedContacts(void)
{
	size_t  index;
	Contact ct;

	std::cout << std::endl;
	this->_addSeparator(" CONTACTS ");
	std::cout << std::setw(10) << "INDEX"
	          << "|" << std::setw(10) << "FIRST NAME"
	          << "|" << std::setw(10) << "LAST NAME"
	          << "|" << std::setw(10) << "NICKNAME" << std::endl;
	index = 0;
	while (index < this->_size)
	{
		ct = this->_contacts[index];
		index++;
		std::cout << std::setw(10) << index << "|" << std::setw(10)
		          << this->_formatColumn(ct.getFirstName()) << "|"
		          << std::setw(10) << this->_formatColumn(ct.getLastName())
		          << "|" << std::setw(10)
		          << this->_formatColumn(ct.getNickname()) << std::endl;
	}
	this->_addSeparator("");
	std::cout << std::endl;
}

void PhoneBook::displayContactInformation(size_t index)
{
	Contact contact;

	if (index > this->_size)
		return;
	contact = this->_contacts[index - 1];
	std::cout << std::endl;
	this->_addSeparator("CONTACT");
	std::cout << "First Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last Name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
	this->_addSeparator("");
}
