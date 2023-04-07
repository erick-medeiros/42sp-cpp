/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:34:38 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/07 17:26:43 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _inventory()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy) : _inventory()
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = copy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < SLOTS; i++)
			_inventory[i] =
			    copy._inventory[i] ? copy._inventory[i]->clone() : 0;
	}
	return *this;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < SLOTS; i++)
		delete _inventory[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < SLOTS; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			break;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < SLOTS; i++)
	{
		if (_inventory[i] && _inventory[i]->getType() == type)
		{
			return (_inventory[i]->clone());
			break;
		}
	}
	return (0);
}

const AMateria *MateriaSource::getMateria(int idx) const
{
	if (idx >= 0 || idx < SLOTS)
		return _inventory[idx];
	return (0);
}
