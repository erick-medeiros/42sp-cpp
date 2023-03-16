/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:42:50 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/16 18:34:51 by eandre-f         ###   ########.fr       */
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
		return (1);
	horde = zombieHorde(N, "alpha");
	i = 0;
	while (i < N)
		horde[i++].announce();
	delete[] horde;
}
