/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:34:38 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/06 17:21:58 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = copy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		(void) copy;
	}
	return *this;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria *) {}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	if (type == "ice")
		return new Ice();
	if (type == "cure")
		return new Cure();
	return (0);
}
