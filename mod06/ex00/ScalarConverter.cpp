/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:34:02 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/13 19:41:02 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	if (DEBUG)
		std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	if (DEBUG)
		std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	if (DEBUG)
		std::cout << "ScalarConverter copy assignment operator called"
		          << std::endl;
	if (this != &copy)
	{
	}
	return *this;
}

ScalarConverter::~ScalarConverter(void)
{
	if (DEBUG)
		std::cout << "ScalarConverter destructor called" << std::endl;
}

void ScalarConverter::convert(std::string data)
{
	(void) data;
}
