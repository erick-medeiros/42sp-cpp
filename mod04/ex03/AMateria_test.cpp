/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria_test.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:19:18 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/07 13:27:46 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "doctest.h"
#include <cstdio>
#include <sstream>

TEST_SUITE("Class AMateria")
{
	TEST_CASE("Orthodox Canonical Form")
	{
		freopen("/dev/null", "w", stdout);
		{
			Cure obj1;
			Cure obj2(obj1);
			Cure obj3 = obj2;
		}
		{
			Ice obj1;
			Ice obj2(obj1);
			Ice obj3 = obj2;
		}
		freopen("/dev/tty", "w", stdout);
	}

	TEST_CASE("Type")
	{
		freopen("/dev/null", "w", stdout);
		{
			Cure obj1;
			Ice  obj2;

			freopen("/dev/tty", "w", stdout);

			CHECK_EQ(obj1.getType(), "cure");
			CHECK_EQ(obj2.getType(), "ice");

			freopen("/dev/null", "w", stdout);
		}
		freopen("/dev/tty", "w", stdout);
	}

	TEST_CASE("Copy Materia")
	{
		freopen("/dev/null", "w", stdout);
		{
			Cure c1 = Cure();
			Cure c2 = c1;
			Ice  i1 = Ice();
			Ice  i2 = i1;
			freopen("/dev/tty", "w", stdout);

			CHECK_EQ(c1.getType(), c2.getType());
			CHECK_EQ(i1.getType(), i2.getType());

			freopen("/dev/null", "w", stdout);
		}
		freopen("/dev/tty", "w", stdout);
	}

	TEST_CASE("Clone Materia")
	{
		freopen("/dev/null", "w", stdout);
		{
			AMateria *m1 = new Cure();
			AMateria *m2 = new Ice();
			AMateria *c1 = m1->clone();
			AMateria *c2 = m2->clone();

			freopen("/dev/tty", "w", stdout);

			CHECK_NE(c1, m1);
			CHECK_NE(c2, m2);

			freopen("/dev/null", "w", stdout);
			delete m1;
			delete m2;
			delete c1;
			delete c2;
		}
		freopen("/dev/tty", "w", stdout);
	}

	TEST_CASE("Use")
	{
		freopen("/dev/null", "w", stdout);
		{
			ICharacter *ch = new Character("CH");
			Cure        cure;
			Ice         ice;

			std::streambuf    *coutbuf = std::cout.rdbuf();
			std::ostringstream oss_ice;
			std::ostringstream oss_cure;

			freopen("/dev/tty", "w", stdout);

			std::cout.rdbuf(oss_cure.rdbuf());
			cure.use(*ch);
			std::cout.rdbuf(oss_ice.rdbuf());
			ice.use(*ch);
			std::cout.rdbuf(coutbuf);

			CHECK_EQ(oss_cure.str(), "* heals CH's wounds *\n");
			CHECK_EQ(oss_ice.str(), "* shoots an ice bolt at CH *\n");

			freopen("/dev/null", "w", stdout);

			delete ch;
		}
		freopen("/dev/tty", "w", stdout);
	}
}
