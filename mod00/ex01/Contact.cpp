/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:02:00 by eandre-f          #+#    #+#             */
/*   Updated: 2023/01/24 15:35:38 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(std::string first_name)
{
	this->_first_name = first_name;
}

std::string Contact::getFirstName(void)
{
	return (this->_first_name);
}

void Contact::setLastName(std::string last_name)
{
	this->_last_name = last_name;
}

std::string Contact::getLastName(void)
{
	return (this->_last_name);
}

void Contact::setNickname(std::string nickname)
{
	this->_nickname = nickname;
}

std::string Contact::getNickname(void)
{
	return (this->_nickname);
}

void Contact::setPhoneNumber(std::string phone_number)
{
	this->_phone_number = phone_number;
}

std::string Contact::getPhoneNumber(void)
{
	return (this->_phone_number);
}

void Contact::setDarkestSecret(std::string darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}

std::string Contact::getDarkestSecret(void)
{
	return (this->_darkest_secret);
}

bool Contact::isCompleted()
{
	return (!this->_first_name.empty() && !this->_last_name.empty() &&
	        !this->_nickname.empty() && !this->_phone_number.empty() &&
	        !this->_darkest_secret.empty());
}
