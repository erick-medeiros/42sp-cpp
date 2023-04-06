/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:34:24 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/06 16:58:34 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>

#include "AMateria.hpp"

class Ice : public AMateria
{
  public:
	Ice(void);
	Ice(const Ice &copy);
	Ice &operator=(const Ice &copy);
	~Ice(void);

	AMateria *clone() const;

  private:
};

#endif /* ICE_HPP */
