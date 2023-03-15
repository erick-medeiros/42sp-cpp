/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:32:35 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/15 12:10:33 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_size = 0;
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

Contact PhoneBook::_createContact(void)
{
	Contact     contact;
	std::string input;

	std::cout << std::endl;
	std::cout << "===== CREATE A NEW CONTACT =====" << std::endl;
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
	std::cout << "==============================" << std::endl;
	return (contact);
}

void PhoneBook::chooseCommand(PhoneBook &phonebook)
{
	Contact     contact;
	std::string input;

	std::cout << "Choose a option: ";
	std::getline(std::cin, input);
	if (input.compare("1") == 0)
	{
		contact = this->_createContact();
		if (contact.isCompleted())
			phonebook.add(contact);
		else
			std::cerr << std::endl << "Error: incomplete contact" << std::endl;
	}
	else if (input.compare("2") == 0)
		phonebook.search();
	else if (input.compare("3") == 0)
		phonebook.exit();
	else if (std::cin.eof())
	{
		std::cout << std::endl;
		phonebook.exit();
	}
	else
	{
		std::cout << "Invalid option" << std::endl;
		return (this->chooseCommand(phonebook));
	}
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

void PhoneBook::search(void)
{
	Contact     contact;
	size_t      index;
	std::string input;

	if (this->_size == 0)
	{
		std::cerr << std::endl << "Empty phone book" << std::endl;
		return;
	}
	std::cout << "Choose an index from 1 to " << this->_size << ": ";
	std::getline(std::cin, input);
	index = std::atoi(input.c_str());
	if (!this->_isNumber(input) || index == 0 || index > this->_size)
	{
		std::cerr << "Error: invalid index: " << input << std::endl;
		return (PhoneBook::search());
	}
	contact = this->_contacts[index - 1];
	std::cout << std::endl;
	std::cout << "=========== Contact ==========" << std::endl;
	std::cout << "First Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last Name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
	std::cout << "==============================" << std::endl;
}

void PhoneBook::exit(void)
{
	std::exit(0);
}
