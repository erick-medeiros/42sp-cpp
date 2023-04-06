/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:34:38 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/06 17:15:04 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource
{
  public:
	MateriaSource(void);
	MateriaSource(const MateriaSource &copy);
	MateriaSource &operator=(const MateriaSource &copy);
	~MateriaSource(void);

	void      learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);

  private:
};

#endif /* MATERIASOURCE_HPP */
