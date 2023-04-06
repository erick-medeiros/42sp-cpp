/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:33:54 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/06 17:19:19 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const std::string &name) : _name(name)
{
	std::cout << "Character constructor by name called" << std::endl;
}

Character::Character(const Character &copy)
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = copy;
}

Character &Character::operator=(const Character &copy)
{
	std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		(void) copy;
	}
	return *this;
}

Character::~Character(void)
{
	std::cout << "Character destructor called" << std::endl;
}

std::string const &Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria *m)
{
	(void) m;
}

void Character::unequip(int idx)
{
	(void) idx;
}

void Character::use(int idx, ICharacter &target)
{
	(void) idx;
	(void) target;
}
