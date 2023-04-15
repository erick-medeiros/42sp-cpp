/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 09:12:00 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/15 09:18:04 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include "doctest.h"
#include "whatever.hpp"

TEST_CASE("swap")
{
	SUBCASE("int")
	{
		int a = 1;
		int b = 2;
		::swap(a, b);
		CHECK_EQ(a, 2);
		CHECK_EQ(b, 1);
	}
	SUBCASE("float")
	{
		float a = 1.1f;
		float b = 2.2f;
		::swap(a, b);
		CHECK_EQ(a, 2.2f);
		CHECK_EQ(b, 1.1f);
	}
	SUBCASE("double")
	{
		double a = 1.1;
		double b = 2.2;
		::swap(a, b);
		CHECK_EQ(a, 2.2);
		CHECK_EQ(b, 1.1);
	}
	SUBCASE("char")
	{
		char a = 'a';
		char b = 'b';
		::swap(a, b);
		CHECK_EQ(a, 'b');
		CHECK_EQ(b, 'a');
	}
}

TEST_CASE("min")
{
	SUBCASE("int")
	{
		int a = 1;
		int b = 2;
		CHECK_EQ(::min(a, b), 1);
	}
	SUBCASE("float")
	{
		float a = 1.1f;
		float b = 2.2f;
		CHECK_EQ(::min(a, b), 1.1f);
	}
	SUBCASE("double")
	{
		double a = 1.1;
		double b = 2.2;
		CHECK_EQ(::min(a, b), 1.1);
	}
	SUBCASE("char")
	{
		char a = 'a';
		char b = 'b';
		CHECK_EQ(::min(a, b), 'a');
	}
}

TEST_CASE("max")
{
	SUBCASE("int")
	{
		int a = 1;
		int b = 2;
		CHECK_EQ(::max(a, b), 2);
	}
	SUBCASE("float")
	{
		float a = 1.1f;
		float b = 2.2f;
		CHECK_EQ(::max(a, b), 2.2f);
	}
	SUBCASE("double")
	{
		double a = 1.1;
		double b = 2.2;
		CHECK_EQ(::max(a, b), 2.2);
	}
	SUBCASE("char")
	{
		char a = 'a';
		char b = 'b';
		CHECK_EQ(::max(a, b), 'b');
	}
}
