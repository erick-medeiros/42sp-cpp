/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:42:50 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/18 20:09:23 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[])
{
	Zombie *horde;
	int     N = 3;
	int     i = 0;

	if (argc > 1)
		N = std::atoi(argv[1]);
	if (N <= 0)
	{
		std::cerr << "Add at least one zombie" << std::endl;
		return (1);
	}
	if (N > 1024)
	{
		std::cerr << "Too many zombies" << std::endl;
		return (1);
	}
	horde = zombieHorde(N, "alpha");
	i = 0;
	while (i < N)
		horde[i++].announce();
	delete[] horde;
}
