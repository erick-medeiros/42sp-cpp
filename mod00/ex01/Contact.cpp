/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:02:00 by eandre-f          #+#    #+#             */
/*   Updated: 2023/01/24 14:26:45 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	this->_first_name = NULL;
	this->_last_name = NULL;
	this->_nickname = NULL;
	this->_phone_number = NULL;
	this->_darkest_secret = NULL;
}

Contact::~Contact(void)
{
	// delete this->_first_name;
	// delete this->_last_name;
	// delete this->_nickname;
	// delete this->_phone_number;
	// delete this->_darkest_secret;
}

void Contact::setFirstName(char *first_name)
{
	this->_first_name = first_name;
}

char *Contact::getFirstName(void)
{
	return (this->_first_name);
}

void Contact::setLastName(char *last_name)
{
	this->_last_name = last_name;
}

char *Contact::getLastName(void)
{
	return (this->_last_name);
}

void Contact::setNickname(char *nickname)
{
	this->_nickname = nickname;
}

char *Contact::getNickname(void)
{
	return (this->_nickname);
}

void Contact::setPhoneNumber(char *phone_number)
{
	this->_phone_number = phone_number;
}

char *Contact::getPhoneNumber(void)
{
	return (this->_phone_number);
}

void Contact::setDarkestSecret(char *darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}

char *Contact::getDarkestSecret(void)
{
	return (this->_darkest_secret);
}
