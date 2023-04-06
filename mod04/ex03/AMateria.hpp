/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:33:46 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/06 16:25:57 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
  public:
	AMateria(void);
	AMateria(const AMateria &copy);
	AMateria &operator=(const AMateria &copy);
	~AMateria(void);

	AMateria(std::string const &type);
	std::string const &getType() const; // Returns the materia type
	virtual AMateria  *clone() const = 0;
	virtual void       use(ICharacter &target);

  protected:
	std::string _type;

  private:
};

#endif /* AMATERIA_HPP */
