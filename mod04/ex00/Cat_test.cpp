/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:31:12 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/05 14:58:27 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "doctest.h"
#include <cstdio>

TEST_SUITE("Class Cat")
{
	TEST_CASE("Orthodox Canonical Form")
	{
		{
			freopen("/dev/null", "w", stdout);
			Cat cat1;
			Cat cat2(cat1);
			Cat cat3 = cat2;
			freopen("/dev/tty", "w", stdout);
			CHECK_EQ(cat1.getType(), cat2.getType());
			freopen("/dev/null", "w", stdout);
		}
		freopen("/dev/tty", "w", stdout);
	}

	TEST_CASE("Type field")
	{
		{
			freopen("/dev/null", "w", stdout);
			Cat cat;
			freopen("/dev/tty", "w", stdout);

			CHECK_EQ(cat.getType(), "Cat");
			freopen("/dev/null", "w", stdout);
		}
		freopen("/dev/tty", "w", stdout);
	}
}
