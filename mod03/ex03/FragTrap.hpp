/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:19:43 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/29 18:51:32 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
  public:
	FragTrap(void);
	FragTrap(const FragTrap &copy);
	FragTrap &operator=(const FragTrap &copy);
	~FragTrap(void);

	FragTrap(std::string name);

	void highFivesGuys(void);

  private:
};

#endif /* FRAGTRAP_HPP */
