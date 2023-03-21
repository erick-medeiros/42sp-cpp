/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:23:45 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/21 18:35:34 by eandre-f         ###   ########.fr       */
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
		Fixed f1(1);
		Fixed f2(1);
		Fixed f3 = f1 - f2;

		CHECK_EQ(f3.toInt(), 0);
	}
	SUBCASE("*")
	{
		Fixed f1(2);
		Fixed f2(2);
		Fixed f3 = f1 * f2;

		CHECK_EQ(f3.toInt(), 4);

		// 1.5f * 1.5f = 2.25f
		// n = 1.5f
		// n == 1.5f == fixed<23, 8> 384 == 0B1_1000_0000
		// n * n == fixed<x, 16> 147456 == 0B10_0100_0000_0000_0000
		// (n * n) >> 8 == fixed<23, 8> 576 == 0B10_0100_0000
		// ((n * n) >> 8) >> 8 = 2.25f

		f1 = Fixed(1.5f);
		f2 = Fixed(1.5f);
		f3 = f1 * f2;

		CHECK_EQ(f3.toFloat(), 2.25f);
	}
	SUBCASE("/")
	{
		Fixed f1(2);
		Fixed f2(2);
		Fixed f3 = f1 / f2;

		CHECK_EQ(f3.toInt(), 1);

		// (n1 << _bits) / n2

		f1 = Fixed(4);
		f2 = Fixed(1.6f);
		f3 = f1 / f2; // == 2.5f
		CHECK_GT(f3.toFloat(), 2.4f);
		CHECK_LE(f3.toFloat(), 2.5f);
	}
}

/*                Point                    */
