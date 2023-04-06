/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:34:07 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/06 17:19:57 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void)
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria()
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = copy;
}

Cure &Cure::operator=(const Cure &copy)
{
	std::cout << "Cure copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		(void) copy;
	}
	return *this;
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}
