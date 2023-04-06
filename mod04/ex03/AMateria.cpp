/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:33:46 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/06 16:40:29 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "AMateria constructor by type called" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = copy;
}

AMateria &AMateria::operator=(const AMateria &copy)
{
	std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		_type = copy._type;
	}
	return *this;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return _type;
};

void AMateria::use(ICharacter &target)
{
	(void) target;
}
