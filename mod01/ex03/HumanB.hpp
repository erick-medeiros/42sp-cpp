/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:38:20 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/17 14:30:56 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{
  public:
	HumanB(std::string name);

	void setWeapon(Weapon &w);
	void attack(void) const;

  private:
	std::string _name;
	Weapon     *_weapon;
};

#endif /* HUMANB_HPP */
