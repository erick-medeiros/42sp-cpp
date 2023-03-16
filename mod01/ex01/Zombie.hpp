/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:18:45 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/16 18:26:34 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
  private:
	std::string _name;

  public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);
	void announce(void);
	void setName(std::string name);
};

Zombie *zombieHorde(int N, std::string name);

#endif
