/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:01:04 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/07 15:32:56 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "doctest.h"
#include <cstdio>
#include <sstream>

TEST_SUITE("Class Character")
{
	TEST_CASE("Orthodox Canonical Form")
	{
		freopen("/dev/null", "w", stdout);
		{
			Character obj1;
			Character obj2(obj1);
			Character obj3 = obj2;
		}
		freopen("/dev/tty", "w", stdout);
	}

	TEST_CASE("Name")
	{
		freopen("/dev/null", "w", stdout);
		{
			Character obj("test");
			Character obj1(obj);
			freopen("/dev/tty", "w", stdout);
			CHECK_EQ(obj.getName(), "test");
			CHECK_EQ(obj.getName(), obj1.getName());
			freopen("/dev/null", "w", stdout);
		}
		freopen("/dev/tty", "w", stdout);
	}

	TEST_CASE("Materia")
	{
		freopen("/dev/null", "w", stdout);
		{
			std::streambuf    *coutbuf = std::cout.rdbuf();
			std::ostringstream oss_ice;
			std::ostringstream oss_cure;

			AMateria *m1 = new Ice();
			AMateria *m2 = new Cure();
			Character obj_ch("CH");

			Character obj("test");

			obj.equip(m1);
			obj.equip(m2);
			freopen("/dev/tty", "w", stdout);

			std::cout.rdbuf(oss_ice.rdbuf());
			obj.use(0, obj_ch);
			std::cout.rdbuf(oss_cure.rdbuf());
			obj.use(1, obj_ch);
			std::cout.rdbuf(coutbuf);

			CHECK_EQ(oss_cure.str(), "* heals CH's wounds *\n");
			CHECK_EQ(oss_ice.str(), "* shoots an ice bolt at CH *\n");

			freopen("/dev/null", "w", stdout);

			obj.unequip(0);
			obj.unequip(1);

			delete m1;
			delete m2;
		}
		freopen("/dev/tty", "w", stdout);
	}

	TEST_CASE("Deep copy")
	{
		freopen("/dev/null", "w", stdout);
		{
			Character obj("test");

			obj.equip(new Ice());
			obj.equip(new Cure());

			Character copy(obj);

			freopen("/dev/tty", "w", stdout);

			for (int i = 0; i < SLOTS; i++)
				if (obj.getMateria(i))
					CHECK_NE(obj.getMateria(i), copy.getMateria(i));
				else
					CHECK_EQ(obj.getMateria(i), copy.getMateria(i));

			freopen("/dev/null", "w", stdout);
		}
		freopen("/dev/tty", "w", stdout);
	}
}
