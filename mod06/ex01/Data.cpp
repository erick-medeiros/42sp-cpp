/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:35:35 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/14 23:44:34 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void) : _name("undefined"), _number(0)
{
	if (DEBUG)
		std::cout << "Data default constructor called" << std::endl;
}

Data::Data(const Data &copy)
{
	if (DEBUG)
		std::cout << "Data copy constructor called" << std::endl;
	*this = copy;
}

Data &Data::operator=(const Data &copy)
{
	if (DEBUG)
		std::cout << "Data copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		_name = copy._name;
		_number = copy._number;
	}
	return *this;
}

Data::~Data(void)
{
	if (DEBUG)
		std::cout << "Data destructor called" << std::endl;
}

Data::Data(const std::string &name, const int &number)
    : _name(name), _number(number)
{
	if (DEBUG)
		std::cout << "Data constructor by name and number called" << std::endl;
}

const std::string &Data::getName() const
{
	return _name;
}

void Data::setName(const std::string &name)
{
	_name = name;
}

const int &Data::getNumber() const
{
	return _number;
}

void Data::setNumber(const int &number)
{
	_number = number;
}
