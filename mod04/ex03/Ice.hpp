/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:34:24 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/07 13:23:35 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria
{
  public:
	Ice(void);
	Ice(const Ice &copy);
	Ice &operator=(const Ice &copy);
	~Ice(void);

	AMateria *clone() const;
	void      use(ICharacter &target);

  private:
};

#endif /* ICE_HPP */
