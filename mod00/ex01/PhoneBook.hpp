/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:32:38 by eandre-f          #+#    #+#             */
/*   Updated: 2023/01/25 20:00:47 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstdlib>
#include <iostream>

#define CONTACTS_MAX 8

class PhoneBook
{
  private:
	Contact _contacts[CONTACTS_MAX];
	size_t  _size;

  public:
	PhoneBook();
	void    add(Contact contact);
	Contact search(size_t index);
	void    exit();
};

#endif
