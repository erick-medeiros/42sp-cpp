/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:36:22 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/05 20:29:16 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "doctest.h"
#include <cstdio>

TEST_SUITE("Class Brain")
{
	TEST_CASE("Orthodox Canonical Form")
	{
		{
			freopen("/dev/null", "w", stdout);
			Brain object1;
			Brain object2(object1);
			Brain object3 = object2;
		}
		freopen("/dev/tty", "w", stdout);
	}

	TEST_CASE("Deep copy")
	{
		{
			freopen("/dev/null", "w", stdout);
			Brain object1;

			for (int i = 0; i < 100; i++)
				object1.setIdea(i, "idea1");

			Brain object2(object1);
			Brain object3 = object1;

			for (int i = 0; i < 100; i++)
				object1.setIdea(i, "idea0");

			freopen("/dev/tty", "w", stdout);
			for (int i = 0; i < 100; i++)
			{
				CHECK_NE(object1.getIdea(i), object2.getIdea(i));
				CHECK_NE(object1.getIdea(i), object3.getIdea(i));
				CHECK_EQ(object2.getIdea(i), object3.getIdea(i));
			}
			freopen("/dev/null", "w", stdout);
		}
		freopen("/dev/tty", "w", stdout);
	}
}
