/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:31:51 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/05 15:32:50 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "doctest.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

TEST_SUITE("Class Dog")
{
	TEST_CASE("Orthodox Canonical Form")
	{
		{
			freopen("/dev/null", "w", stdout);
			Dog dog1;
			Dog dog2(dog1);
			Dog dog3 = dog2;
			freopen("/dev/tty", "w", stdout);
			CHECK_EQ(dog1.getType(), dog2.getType());
			freopen("/dev/null", "w", stdout);
		}
		freopen("/dev/tty", "w", stdout);
	}

	TEST_CASE("Type field")
	{
		{
			freopen("/dev/null", "w", stdout);
			Dog dog;
			freopen("/dev/tty", "w", stdout);

			CHECK_EQ(dog.getType(), "Dog");
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
			Dog dog;
			freopen("/dev/tty", "w", stdout);

			std::cout.rdbuf(oss.rdbuf());
			// Woof woof! (barking sound)
			// Aaaauuuuuuu! (howl sound)
			// Grrrrrr... (growling sound)
			dog.makeSound();
			std::cout.rdbuf(coutbuf);
			CHECK_EQ(oss.str(), "Woof woof!\n");
			freopen("/dev/null", "w", stdout);
		}
		freopen("/dev/tty", "w", stdout);
	}
}
