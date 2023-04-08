/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:34:38 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/08 10:35:04 by eandre-f         ###   ########.fr       */
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

void MateriaSource::learnMateria(AMateria *newMateria)
{
	for (int i = 0; i < SLOTS; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = newMateria;
			if (newMateria)
			{
				std::cout << "Materia " << newMateria->getType() << " learned"
				          << std::endl;
			}
			return;
		}
	}
	std::cout << "Unable to learn Materia";
	if (newMateria)
	{
		std::cout << " " << newMateria->getType();
		delete newMateria;
	}
	std::cout << std::endl;
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
	std::cout << "Could not create Materia " << type << std::endl;
	return (0);
}

const AMateria *MateriaSource::getMateria(int idx) const
{
	if (idx >= 0 && idx < SLOTS)
		return _inventory[idx];
	return (0);
}
