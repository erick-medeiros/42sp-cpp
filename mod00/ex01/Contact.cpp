/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:02:00 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/16 16:10:46 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(std::string first_name, std::string last_name,
                 std::string nickname, std::string phone_number,
                 std::string darkest_secret)
{
	this->_first_name = first_name;
	this->_last_name = last_name;
	this->_nickname = nickname;
	this->_phone_number = phone_number;
	this->_darkest_secret = darkest_secret;
}

std::string Contact::_removeWhitspace(std::string str)
{
	std::string result;
	size_t      i;

	i = 0;
	while (i < str.size())
	{
		if (!std::isspace(str[i]))
			result += str[i];
		i++;
	}
	return (result);
}

bool Contact::setFirstName(std::string first_name)
{
	std::string::iterator it;

	if (first_name.size() == 0)
		return (false);
	it = first_name.begin();
	while (it != first_name.end())
	{
		if (!std::isalpha(*it))
			return (false);
		it++;
	}
	this->_first_name = this->_removeWhitspace(first_name);
	return (true);
}

std::string Contact::getFirstName(void)
{
	return (this->_first_name);
}

bool Contact::setLastName(std::string last_name)
{
	std::string::iterator it;

	if (last_name.size() == 0)
		return (false);
	it = last_name.begin();
	while (it != last_name.end())
	{
		if (!std::isalpha(*it))
			return (false);
		it++;
	}
	this->_last_name = this->_removeWhitspace(last_name);
	return (true);
}

std::string Contact::getLastName(void)
{
	return (this->_last_name);
}

bool Contact::setNickname(std::string nickname)
{
	if (nickname.size() == 0)
		return (false);
	this->_nickname = this->_removeWhitspace(nickname);
	return (true);
}

std::string Contact::getNickname(void)
{
	return (this->_nickname);
}

bool Contact::setPhoneNumber(std::string phone_number)
{
	std::string::const_iterator it;
	int                         i;

	phone_number = this->_removeWhitspace(phone_number);
	if (phone_number.length() < 7)
		return (false);
	if (phone_number.length() > 15)
		return (false);
	i = 0;
	it = phone_number.begin();
	while (it != phone_number.end())
	{
		if (i == 0)
			if ((*it != '+' && !std::isdigit(*it)) || *it == '0')
				return (false);
		if (i > 0 && !std::isdigit(*it))
			return (false);
		i++;
		it++;
	}
	this->_phone_number = phone_number;
	return (true);
}

std::string Contact::getPhoneNumber(void)
{
	return (this->_phone_number);
}

bool Contact::setDarkestSecret(std::string darkest_secret)
{
	if (darkest_secret.size() == 0)
		return (false);
	this->_darkest_secret = darkest_secret;
	return (true);
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
