/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:41:04 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/05 15:58:25 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
  public:
	Animal(void);
	Animal(const Animal &copy);
	Animal &operator=(const Animal &copy);
	virtual ~Animal(void);

	const std::string &getType(void) const;

	virtual void makeSound(void) const;

  protected:
	std::string type;

  private:
};

#endif /* ANIMAL_HPP */
