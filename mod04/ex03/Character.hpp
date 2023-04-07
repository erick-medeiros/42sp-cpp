/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:33:54 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/07 15:35:12 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

#define SLOTS 4

class Character : public ICharacter
{
  public:
	Character(void);
	Character(const Character &copy);
	Character &operator=(const Character &copy);
	~Character(void);

	Character(const std::string &name);

	std::string const &getName() const;
	void               equip(AMateria *m);
	void               unequip(int idx);
	void               use(int idx, ICharacter &target);

	const AMateria *getMateria(int idx) const;

  private:
	std::string _name;
	AMateria   *_inventory[SLOTS];
};

#endif /* CHARACTER_HPP */
