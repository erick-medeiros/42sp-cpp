/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:32:38 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/15 15:49:18 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

#define CONTACTS_MAX 8

class PhoneBook
{
  private:
	Contact _contacts[CONTACTS_MAX];
	size_t  _size;
	Contact _createContact(void);
	bool _isNumber(const std::string& str);
	std::string _formatColumn(std::string column);

  public:
	PhoneBook();
	void	chooseCommand(PhoneBook &phonebook);
	size_t	chooseIndex(void);
	size_t	getSize(void);
	void	displaySavedContacts(void);
	void	displayContactInformation(size_t index);
	void    add(Contact contact);
	void    exit(void);
};

#endif
