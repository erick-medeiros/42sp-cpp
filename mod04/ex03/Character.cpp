/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:33:54 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/08 10:34:10 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _inventory()
{
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const std::string &name) : _name(name), _inventory()
{
	std::cout << "Character constructor by name called" << std::endl;
}

Character::Character(const Character &copy) : _inventory()
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = copy;
}

Character &Character::operator=(const Character &copy)
{
	std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		_name = copy._name;
		for (int i = 0; i < SLOTS; i++)
			_inventory[i] =
			    copy._inventory[i] ? copy._inventory[i]->clone() : 0;
	}
	return *this;
}

Character::~Character(void)
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < SLOTS; i++)
		delete _inventory[i];
}

std::string const &Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria *newMateria)
{
	for (int i = 0; i < SLOTS; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = newMateria;
			if (newMateria)
			{
				std::cout << "Materia " << newMateria->getType() << " equipped"
				          << std::endl;
			}
			return;
		}
	}
	std::cout << "Unable to equip Materia";
	if (newMateria)
	{
		std::cout << " " << newMateria->getType();
		delete newMateria;
	}
	std::cout << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 || idx < SLOTS)
	{
		_inventory[idx] = 0;
		std::cout << "Materia unequipped in slot " << idx << std::endl;
	}
	else
		std::cout << "Could	not unequip, invalid idx " << idx << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 || idx < SLOTS)
	{
		if (_inventory[idx])
			_inventory[idx]->use(target);
		else
			std::cout << "Could	not use, slot " << idx << " empty" << std::endl;
	}
	else
		std::cout << "Could	not use, invalid idx " << idx << std::endl;
}

const AMateria *Character::getMateria(int idx) const
{
	if (idx >= 0 && idx < SLOTS)
		return _inventory[idx];
	return (0);
}
