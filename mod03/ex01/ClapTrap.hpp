/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:52:53 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/30 14:03:56 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
  public:
	ClapTrap(void);
	ClapTrap(const ClapTrap &copy);
	ClapTrap &operator=(const ClapTrap &copy);
	~ClapTrap(void);

	ClapTrap(const std::string &name);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	const std::string &getName() const;
	const int         &getHitPoints() const;
	const int         &getEnergyPoints() const;
	const int         &getAttackDamage() const;

  protected:
	std::string _name;
	int         _hitPoints;
	int         _energyPoints;
	int         _attackDamage;
};

#endif /* CLAPTRAP_HPP */
