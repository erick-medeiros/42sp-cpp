/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:22:57 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/05 15:07:46 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
  public:
	Cat(void);
	Cat(const Cat &copy);
	Cat &operator=(const Cat &copy);
	~Cat(void);

	void makeSound(void) const;

  private:
};

#endif /* CAT_HPP */
