/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:27:20 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/21 10:06:21 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include "doctest.h"
#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

TEST_SUITE("easyfind")
{
	TEST_CASE("vector")
	{
		SUBCASE("fill constructor") // firts, last
		{
			int ints[] = {1, 2, 3};

			std::vector<int> c(ints, ints + sizeof(ints) / sizeof(int));
			std::vector<int>::iterator it;

			it = easyfind(c, 1);
			CHECK_EQ(*it, 1);
		}
		SUBCASE("range constructor") // elem, val
		{
			std::vector<int>           c(3, 1);
			std::vector<int>::iterator it;

			it = easyfind(c, 1);
			CHECK_EQ(*it, 1);
		}
	}
	TEST_CASE("deque")
	{
		std::deque<int>           c(1, 1);
		std::deque<int>::iterator it;

		it = easyfind(c, 1);
		CHECK_EQ(*it, 1);
	}
	TEST_CASE("list")
	{
		std::list<int>           c(1, 1);
		std::list<int>::iterator it;

		it = easyfind(c, 1);
		CHECK_EQ(*it, 1);
	}
	TEST_CASE("throw")
	{
		SUBCASE("vector")
		{
			std::vector<int> c;
			CHECK_THROWS(::easyfind(c, 1));
		}
		SUBCASE("list")
		{
			std::list<int> c;
			CHECK_THROWS(::easyfind(c, 1));
		}
		SUBCASE("deque")
		{
			std::deque<int> c;
			CHECK_THROWS(::easyfind(c, 1));
		}
	}
	TEST_CASE("const")
	{
		std::vector<int> const           c(1, 1);
		std::vector<int>::const_iterator it = ::easyfind(c, 1);
		CHECK_EQ(*it, 1);
	}
}
