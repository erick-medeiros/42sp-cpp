/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:09:56 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/21 15:45:25 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "doctest.h"

TEST_SUITE("Class Span")
{
	TEST_CASE("Orthodox Canonical Form")
	{
		CHECK_NOTHROW({
			Span obj1;
			Span obj2(obj1);
			Span obj3 = obj2;
		});
	}
	TEST_CASE("constructor by max")
	{
		CHECK_NOTHROW(Span obj(10));
	}
	TEST_CASE("addNumber")
	{
		SUBCASE("full")
		{
			Span obj(3);
			CHECK_NOTHROW(obj.addNumber(1));
			CHECK_NOTHROW(obj.addNumber(2));
			CHECK_NOTHROW(obj.addNumber(3));
		}
		SUBCASE("overflow")
		{
			Span obj(3);
			CHECK_NOTHROW(obj.addNumber(1));
			CHECK_NOTHROW(obj.addNumber(2));
			CHECK_NOTHROW(obj.addNumber(3));
			CHECK_THROWS(obj.addNumber(4));
		}
	}
	TEST_CASE("shortestSpan")
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		CHECK_EQ(sp.shortestSpan(), 2);
	}
	TEST_CASE("longestSpan")
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		CHECK_EQ(sp.longestSpan(), 14);
	}
	TEST_CASE("addManyNumbers")
	{
		int            v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		std::list<int> l(v, v + sizeof(v) / sizeof(int));

		SUBCASE("success")
		{
			Span obj(10);
			obj.addManyNumbers(l.begin(), l.end());
			CHECK_EQ(obj.shortestSpan(), 1);
			CHECK_EQ(obj.longestSpan(), 9);
		}
		SUBCASE("throw")
		{
			Span obj(1);
			CHECK_THROWS(obj.addManyNumbers(l.begin(), l.end()));
		}
	}
	TEST_CASE("negative")
	{
		int            v[] = {-3, -2, 1, 3};
		std::list<int> l(v, v + sizeof(v) / sizeof(int));
		Span           obj(4);
		obj.addManyNumbers(l.begin(), l.end());
		CHECK_EQ(obj.shortestSpan(), 1);
		CHECK_EQ(obj.longestSpan(), 6);
	}
	TEST_CASE("super test")
	{
		int size = 100000;
		int v[size];
		for (int i = 0; i < size; i++)
			v[i] = i;
		std::list<int> l(v, v + sizeof(v) / sizeof(int));
		//
		Span obj(size);
		obj.addManyNumbers(l.begin(), l.end());
		//
		CHECK_EQ(obj.shortestSpan(), 1);
		CHECK_EQ(obj.longestSpan(), size - 1);
	}
}
