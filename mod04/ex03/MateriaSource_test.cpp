/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource_test.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:38:35 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/08 10:34:56 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "doctest.h"

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "doctest.h"
#include <cstdio>
#include <sstream>

TEST_SUITE("Class MateriaSource")
{
	TEST_CASE("Orthodox Canonical Form")
	{
		freopen("/dev/null", "w", stdout);
		{
			MateriaSource obj1;
			MateriaSource obj2(obj1);
			MateriaSource obj3 = obj2;
		}
		freopen("/dev/tty", "w", stdout);
	}

	TEST_CASE("Copy")
	{
		freopen("/dev/null", "w", stdout);
		{
			MateriaSource ms;

			Ice  *ice = new Ice;
			Cure *cure = new Cure;

			ms.learnMateria(ice);
			ms.learnMateria(cure);

			MateriaSource copy(ms);

			freopen("/dev/tty", "w", stdout);

			for (int i = 0; i < SLOTS; i++)
			{
				if (i == 0)
				{
					CHECK(ms.getMateria(i));
					CHECK_EQ(ms.getMateria(i)->getType(), "ice");
				}
				else if (i == 1)
				{
					CHECK(ms.getMateria(i));
					CHECK_EQ(ms.getMateria(i)->getType(), "cure");
				}
				if (ms.getMateria(i))
					CHECK_NE(ms.getMateria(i), copy.getMateria(i));
				else
					CHECK_EQ(ms.getMateria(i), copy.getMateria(i));
			}

			freopen("/dev/null", "w", stdout);
		}
		freopen("/dev/tty", "w", stdout);
	}

	TEST_CASE("learnMateria")
	{
		freopen("/dev/null", "w", stdout);
		{
			MateriaSource ms;

			for (int i = 0; i < SLOTS; i++)
				ms.learnMateria(0);

			AMateria *cm = ms.createMateria("ice");

			freopen("/dev/tty", "w", stdout);

			CHECK_FALSE(cm);

			freopen("/dev/null", "w", stdout);

			ms.learnMateria(new Ice());
			ms.learnMateria(new Ice());
			ms.learnMateria(new Ice());
			ms.learnMateria(new Ice());
			ms.learnMateria(new Cure());

			AMateria *ice = ms.createMateria("ice");
			AMateria *cure = ms.createMateria("cure");

			freopen("/dev/tty", "w", stdout);

			CHECK(ice);
			CHECK_EQ(ice->getType(), "ice");
			CHECK_FALSE(cure);
			CHECK_FALSE(ms.getMateria(SLOTS));

			freopen("/dev/null", "w", stdout);

			delete ice;
		}
		freopen("/dev/tty", "w", stdout);
	}

	TEST_CASE("createMateria")
	{
		freopen("/dev/null", "w", stdout);
		{
			MateriaSource ms;

			Ice  *ice = new Ice;
			Cure *cure = new Cure;

			ms.learnMateria(ice);
			ms.learnMateria(cure);
			AMateria *crIce = ms.createMateria("ice");
			AMateria *crCure = ms.createMateria("cure");
			AMateria *undefined = ms.createMateria("undefined");

			freopen("/dev/tty", "w", stdout);

			CHECK_EQ(crIce->getType(), "ice");
			CHECK_EQ(crCure->getType(), "cure");
			CHECK_FALSE(undefined);

			freopen("/dev/null", "w", stdout);

			delete crIce;
			delete crCure;
		}
		freopen("/dev/tty", "w", stdout);
	}
}
