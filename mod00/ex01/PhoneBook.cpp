/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:32:35 by eandre-f          #+#    #+#             */
/*   Updated: 2023/01/25 20:00:40 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_size = 0;
}

void PhoneBook::add(Contact contact)
{
	size_t index;

	this->_size++;
	if (this->_size > 8)
	{
		index = 0;
		while (++index < CONTACTS_MAX)
			this->_contacts[index - 1] = this->_contacts[index];
	}
	this->_contacts[this->_size - 1] = contact;
}

Contact PhoneBook::search(size_t index)
{
	if (index == 0 || index > this->_size)
	{
		std::cerr << "err: search for contact: invalid index: ";
		std::cerr << index << std::endl;
		std::cin >> index;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cin >> index;
		}
		return (PhoneBook::search(index));
	}
	return (this->_contacts[index - 1]);
}

void PhoneBook::exit(void)
{
	std::exit(0);
}
