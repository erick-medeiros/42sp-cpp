/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:41:04 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/30 14:30:40 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
  public:
	DiamondTrap(void);
	DiamondTrap(const DiamondTrap &copy);
	DiamondTrap &operator=(const DiamondTrap &copy);
	~DiamondTrap(void);

	DiamondTrap(const std::string &name);

	void whoAmI(void);

	const std::string &getName() const;
	void               setName(std::string name);

  protected:
	using FragTrap::_attackDamage;
	using FragTrap::_hitPoints;
	using ScavTrap::_energyPoints;

  private:
	std::string _name;
};

#endif /* DIAMONDTRAP_HPP */
