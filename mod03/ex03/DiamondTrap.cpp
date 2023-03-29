/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:41:04 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/29 19:19:54 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
    : ClapTrap(), ScavTrap(), FragTrap(), _name("mascot")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
    : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = copy;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->setName(copy.getName());
		this->setHitPoints(copy.getHitPoints());
		this->setEnergyPoints(copy.getEnergyPoints());
		this->setAttackDamage(copy.getAttackDamage());
		ClapTrap::setName(copy.getName() + "_clap_name");
	}
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
	std::cout << "DiamondTrap constructor (name) called" << std::endl;
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name is " << _name << " and ClapTrap name is "
	          << ClapTrap::getName() << std::endl;
}

const std::string &DiamondTrap::getName() const
{
	return _name;
}

void DiamondTrap::setName(std::string name)
{
	_name = name;
}
