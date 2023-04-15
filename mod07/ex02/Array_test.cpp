/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 10:48:26 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/15 12:12:41 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "doctest.h"

TEST_SUITE("Class Array")
{
	TEST_CASE("constructor default")
	{
		Array<char>  obj1;
		Array<int>   obj2;
		Array<float> obj3;
		CHECK_EQ(obj1.size(), 0);
		CHECK_EQ(obj2.size(), 0);
		CHECK_EQ(obj3.size(), 0);
	}
	TEST_CASE("constructor size")
	{
		Array<char>   obj1(1);
		Array<int>    obj2(2);
		Array<float>  obj3(3);
		Array<double> obj4(0);
		obj1[0];
		obj2[0];
		obj2[1];
		obj3[0];
		obj3[1];
		obj3[2];
	}
	TEST_CASE("copy")
	{
		Array<int> obj1(2);
		obj1[0] = 1;
		obj1[1] = 1;
		Array<int> obj2(obj1);
		obj1[0] = 2;
		Array<int> obj3 = obj1;
		obj1[1] = 3;
		CHECK_EQ(obj1[0], 2);
		CHECK_EQ(obj1[1], 3);
		CHECK_EQ(obj2[0], 1);
		CHECK_EQ(obj2[1], 1);
		CHECK_EQ(obj3[0], 2);
		CHECK_EQ(obj3[1], 1);
	}
	TEST_CASE("acess")
	{
		Array<int> obj(1);
		int       &i1 = obj[0];
		const int &i2 = obj[0];
		CHECK_EQ(&i1, &i2);
		CHECK_EQ(i1, i2);
	}
}
