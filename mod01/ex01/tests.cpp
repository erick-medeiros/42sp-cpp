/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:15:24 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/16 13:13:44 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include "Zombie.hpp"
#include "doctest.h"

TEST_CASE("check zombie announce")
{
	std::ostringstream oss;
	std::streambuf    *p_cout_streambuf = std::cout.rdbuf();

	Zombie zombie1("<name>");
	std::cout.rdbuf(oss.rdbuf());
	zombie1.announce();
	std::cout.rdbuf(p_cout_streambuf);
	CHECK_EQ(oss.str(), "<name>: BraiiiiiiinnnzzzZ...\n");

	oss.str("");
	oss.clear();

	Zombie zombie2("Foo");
	std::cout.rdbuf(oss.rdbuf());
	zombie2.announce();
	std::cout.rdbuf(p_cout_streambuf);
	CHECK_EQ(oss.str(), "Foo: BraiiiiiiinnnzzzZ...\n");
}
