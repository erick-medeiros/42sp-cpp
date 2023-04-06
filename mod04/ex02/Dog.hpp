/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:22:55 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/06 08:51:41 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public AAnimal
{
  public:
	Dog(void);
	Dog(const Dog &copy);
	Dog &operator=(const Dog &copy);
	~Dog(void);

	void makeSound(void) const;

  private:
	Brain *brain;
};

#endif /* DOG_HPP */
