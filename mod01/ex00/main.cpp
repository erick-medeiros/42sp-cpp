/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:42:50 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/16 17:54:47 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main()
{
	Zombie *zombieInfected = newZombie("Infected");
	Zombie  zombieWalker("Walker");

	zombieWalker.announce();
	zombieInfected->announce();
	randomChump("Chump");
	delete zombieInfected;
}
