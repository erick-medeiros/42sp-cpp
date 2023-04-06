/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:41:04 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/06 09:01:48 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
  public:
	AAnimal(void);
	AAnimal(const AAnimal &copy);
	AAnimal &operator=(const AAnimal &copy);
	virtual ~AAnimal(void);

	const std::string &getType(void) const;

	virtual void makeSound(void) const;

  protected:
	std::string type;

  private:
};

#endif /* AANIMAL_HPP */
