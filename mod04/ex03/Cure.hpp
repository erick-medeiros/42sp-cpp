/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:34:07 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/06 16:58:44 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria
{
  public:
	Cure(void);
	Cure(const Cure &copy);
	Cure &operator=(const Cure &copy);
	~Cure(void);

	AMateria *clone() const;

  private:
};

#endif /* CURE_HPP */
