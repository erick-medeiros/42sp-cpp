/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:04:54 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/05 16:11:05 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "doctest.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

TEST_SUITE("Class Animal")
{
	TEST_CASE("Orthodox Canonical Form")
	{
		{
			freopen("/dev/null", "w", stdout);
			Animal animal1;
			Animal animal2(animal1);
			Animal animal3 = animal2;
		}
		freopen("/dev/tty", "w", stdout);
	}

	TEST_CASE("Type field")
	{
		{
			freopen("/dev/null", "w", stdout);
			Animal animal;
			freopen("/dev/tty", "w", stdout);

			CHECK_EQ(animal.getType(), "Animal");
			freopen("/dev/null", "w", stdout);
		}
		freopen("/dev/tty", "w", stdout);
	}

	TEST_CASE("makeSound")
	{
		{
			std::ostringstream oss;
			std::streambuf    *coutbuf = std::cout.rdbuf();

			freopen("/dev/null", "w", stdout);
			Animal animal;
			freopen("/dev/tty", "w", stdout);

			std::cout.rdbuf(oss.rdbuf());
			// Roar! (roar sound)
			animal.makeSound();
			std::cout.rdbuf(coutbuf);
			CHECK_EQ(oss.str(), "Roar!\n");
			freopen("/dev/null", "w", stdout);
		}
		freopen("/dev/tty", "w", stdout);
	}
}
