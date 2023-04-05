/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:41:04 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/05 14:35:45 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

Animal &Animal::operator=(const Animal &copy)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		type = copy.type;
	}
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

const std::string &Animal::getType(void) const
{
	return type;
}
