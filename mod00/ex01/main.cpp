/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:32:31 by eandre-f          #+#    #+#             */
/*   Updated: 2023/01/25 19:58:13 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

void msgCompleted(Contact contact)
{
	if (contact.isCompleted())
		std::cout << "Contact is completed" << std::endl;
	else
		std::cout << "Contact not is completed" << std::endl;
}

Contact createContact(void)
{
	Contact     contact;
	std::string str;

	std::cout << "What is your first name?" << std::endl;
	std::cin >> str;
	contact.setFirstName(str);
	std::cout << "What is your last name?" << std::endl;
	std::cin >> str;
	contact.setLastName(str);
	std::cout << "What is your nickname?" << std::endl;
	std::cin >> str;
	contact.setNickname(str);
	std::cout << "What is your phone number?" << std::endl;
	std::cin >> str;
	contact.setPhoneNumber(str);
	std::cout << "What is your darkest secret?" << std::endl;
	std::cin >> str;
	contact.setDarkestSecret(str);
	return (contact);
}

Contact populateContact(void)
{
	Contact contact;

	contact.setFirstName("Mr");
	contact.setLastName("Blue");
	contact.setNickname("Dr");
	contact.setPhoneNumber("42");
	contact.setDarkestSecret("sp");
	return (contact);
}

void showInfoOfContact(Contact contact)
{
	std::cout << "\n\n--- Contact ---\n\n";
	std::cout << "First Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last Name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

int main()
{
	PhoneBook phone;
	Contact   contact;

	msgCompleted(contact);
	// contact = createContact();
	contact = populateContact();
	msgCompleted(contact);
	phone.add(contact);
	showInfoOfContact(phone.search(2));
	phone.exit();
}
