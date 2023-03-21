/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:23:45 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/21 00:07:54 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include "Fixed.hpp"
#include "doctest.h"

TEST_CASE("Test fixed-point of Class Fixed")
{
	Fixed fixed(1);

	CHECK_EQ(fixed.toInt(), 1);
	CHECK_EQ(fixed.toFloat(), 1.0f);

	fixed = Fixed(1.1f);

	CHECK_EQ(fixed.toInt(), 1);
	//
	CHECK_GT(fixed.toFloat(), 1.10156f);
	CHECK_LT(fixed.toFloat(), 1.10157f);
	//

	fixed = Fixed(1.11f);
	CHECK_EQ(fixed.toInt(), 1);
	//
	CHECK_GT(fixed.toFloat(), 1.10937f);
	CHECK_LT(fixed.toFloat(), 1.10938f);
	//

	fixed = Fixed(1.9921875f);

	CHECK_EQ(fixed.toInt(), 1);
	//
	CHECK_GT(fixed.toFloat(), 1.99218f);
	CHECK_LT(fixed.toFloat(), 1.99219f);
	//
}

TEST_CASE("Test rawBits of Class Fixed")
{
	Fixed fixed = Fixed(1);
	CHECK_EQ(fixed.getRawBits(), 0B100000000);
	fixed = Fixed(1.1f); // 1.0001100110011001101
	CHECK_EQ(fixed.getRawBits(), 0B100011010);
}

TEST_CASE("Comparison operators of Class Fixed")
{
	SUBCASE(">")
	{
		Fixed f1(0B11);
		Fixed f2(0B10);

		CHECK(f1 > f2);
		CHECK_FALSE(f2 > f1);
	}
	SUBCASE("<")
	{
		Fixed f1(0B11);
		Fixed f2(0B10);

		CHECK(f2 < f1);
		CHECK_FALSE(f1 < f2);
	}
	SUBCASE(">=")
	{
		Fixed f1(0B11);
		Fixed f2(0B10);
		Fixed f3(0B10);

		CHECK(f1 >= f2);
		CHECK(f2 >= f3);
		CHECK_FALSE(f1 < f2);
		CHECK_FALSE(f2 < f3);
	}
	SUBCASE("<=")
	{
		Fixed f1(0B10);
		Fixed f2(0B11);
		Fixed f3(0B11);

		CHECK(f1 <= f2);
		CHECK(f2 <= f3);
		CHECK_FALSE(f1 > f2);
		CHECK_FALSE(f2 > f3);
	}
	SUBCASE("==")
	{
		Fixed f1(0B11);
		Fixed f2(0B11);

		CHECK(f1 == f2);
		CHECK_FALSE(f1 != f2);
	}
	SUBCASE("!=")
	{
		Fixed f1(0B10);
		Fixed f2(0B11);

		CHECK(f1 != f2);
		CHECK_FALSE(f1 == f2);
	}
}

TEST_CASE("Arithmetic operators of Class Fixed")
{
	SUBCASE("+")
	{
		Fixed f1(1);
		Fixed f2(1);
		Fixed f3 = f1 + f2;

		CHECK_EQ(f3.toInt(), 2);
	}
	SUBCASE("-")
	{
	}
	SUBCASE("*")
	{
	}
	SUBCASE("/")
	{
	}
}
