/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:22:51 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/06 16:26:01 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"
#include <iostream>

class AMateria;

class ICharacter
{
  public:
	virtual ~ICharacter() {}
	virtual std::string const &getName() const = 0;
	virtual void               equip(AMateria *m) = 0;
	virtual void               unequip(int idx) = 0;
	virtual void               use(int idx, ICharacter &target) = 0;

  private:
};

#endif /* ICHARACTER_HPP */
