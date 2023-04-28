/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:25:34 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/28 16:40:56 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "doctest.h"

TEST_SUITE("Class RPN")
{
	TEST_CASE("Orthodox Canonical Form")
	{
		RPN obj1;
		RPN obj2(obj1);
		RPN obj3 = obj2;
	}
	RPN rpn;
	TEST_CASE("expressions")
	{
		SUBCASE("+")
		{
			CHECK_EQ(rpn.process("2 3 +"), 5);
		}
		SUBCASE("-")
		{
			CHECK_EQ(rpn.process("3 2 -"), 1);
		}
		SUBCASE("*")
		{
			CHECK_EQ(rpn.process("2 3 *"), 6);
		}
		SUBCASE("/")
		{
			CHECK_EQ(rpn.process("4 2 /"), 2);
		}
		SUBCASE("division by zero")
		{
			CHECK_THROWS(rpn.process("2 0 /"));
		}
		SUBCASE("multi")
		{
			// pdf
			CHECK_EQ(rpn.process("8 9 * 9 - 9 - 9 - 4 - 1 +"), 42);
			CHECK_EQ(rpn.process("7 7 * 7 -"), 42);
			CHECK_EQ(rpn.process("1 2 * 2 / 2 * 2 4 - +"), 0);
			// extras
			std::string expr = "9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *";
			CHECK_EQ(rpn.process(expr), 3486784401);
			CHECK_EQ(rpn.process("-1 1 +"), 0);
			CHECK_EQ(rpn.process("+1 +1 +"), 2);
			CHECK_EQ(rpn.process("-1 2 *"), -2);
			CHECK_EQ(rpn.process("2 -1 *"), -2);
			CHECK_EQ(rpn.process("-2 -2 *"), 4);
		}
		SUBCASE("error")
		{
			CHECK_THROWS(rpn.process("(1 + 1)"));
			CHECK_THROWS(rpn.process("1 + 1"));
			CHECK_THROWS(rpn.process("1 + -1"));
		}
	}
}
