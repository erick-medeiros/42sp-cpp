/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:34:24 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/06 17:19:46 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void)
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria()
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = copy;
}

Ice &Ice::operator=(const Ice &copy)
{
	std::cout << "Ice copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		(void) copy;
	}
	return *this;
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
}

AMateria *Ice::clone() const
{
	return new Ice(*this);
}
