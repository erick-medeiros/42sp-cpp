/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:19:43 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/29 15:06:51 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap()
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = copy;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->setName(copy.getName());
		this->setHitPoints(copy.getHitPoints());
		this->setEnergyPoints(copy.getEnergyPoints());
		this->setAttackDamage(copy.getAttackDamage());
	}
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor (name) called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << getName() << " o/\\o (high fives guys!)"
	          << std::endl;
}
