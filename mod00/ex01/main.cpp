/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:32:31 by eandre-f          #+#    #+#             */
/*   Updated: 2023/01/24 15:51:06 by eandre-f         ###   ########.fr       */
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

int main()
{
	Contact     contact;
	std::string str;

	msgCompleted(contact);
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
	msgCompleted(contact);
	std::cout << "\n\n--- Contact ---\n\n";
	std::cout << "First Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last Name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}
