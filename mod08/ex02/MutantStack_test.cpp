/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack_test.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:06:45 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/21 17:34:42 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "doctest.h"
#include <list>

TEST_SUITE("Class MutantStack")
{
	TEST_CASE("Orthodox Canonical Form")
	{
		MutantStack<int> obj1;
		MutantStack<int> obj2(obj1);
		MutantStack<int> obj3 = obj2;
	}

	TEST_CASE("stack: member functions")
	{
		SUBCASE("empty")
		{
			MutantStack<int> ms;
			CHECK_EQ(ms.empty(), true);
		}
		SUBCASE("size")
		{
			MutantStack<int> ms;
			CHECK_EQ(ms.size(), 0);
			ms.push(1);
			CHECK_EQ(ms.size(), 1);
		}
		SUBCASE("top")
		{
			MutantStack<int> ms;
			ms.push(1);
			CHECK_EQ(ms.top(), 1);
		}
		SUBCASE("push")
		{
			MutantStack<int> ms;
			ms.push(1);
			CHECK_EQ(ms.top(), 1);
			ms.push(2);
			CHECK_EQ(ms.top(), 2);
			std::string              str("str");
			MutantStack<std::string> ms_str;
			ms_str.push(str);
			str = "str2";
			CHECK_EQ(ms_str.top(), "str");
		}
		SUBCASE("pop")
		{
			MutantStack<int> ms;
			ms.push(1);
			CHECK_EQ(ms.size(), 1);
			ms.pop();
			CHECK_EQ(ms.size(), 0);
		}
	}

	TEST_CASE("iterators")
	{
		MutantStack<int> ms;
		ms.push(1);
		ms.push(2);
		ms.push(3);
		//
		MutantStack<int>::iterator beginIt = ms.begin();
		MutantStack<int>::iterator endIt = ms.end();
		CHECK_EQ(*beginIt++, 1);
		CHECK_EQ(*beginIt++, 2);
		CHECK_EQ(*beginIt++, 3);
		CHECK_EQ(beginIt, endIt);
		//
		MutantStack<int>::const_iterator beginCIt = ms.begin();
		MutantStack<int>::const_iterator endCIt = ms.end();
		CHECK_EQ(*beginCIt++, 1);
		CHECK_EQ(*beginCIt++, 2);
		CHECK_EQ(*beginCIt++, 3);
		CHECK_EQ(beginCIt, endCIt);
		//
		MutantStack<int>::reverse_iterator rbeginIt = ms.rbegin();
		MutantStack<int>::reverse_iterator rendIt = ms.rend();
		CHECK_EQ(*rbeginIt++, 3);
		CHECK_EQ(*rbeginIt++, 2);
		CHECK_EQ(*rbeginIt++, 1);
		CHECK_EQ(rbeginIt, rendIt);
		//
		MutantStack<int>::const_reverse_iterator rbeginCIt = ms.rbegin();
		MutantStack<int>::const_reverse_iterator rendCIt = ms.rend();
		CHECK_EQ(*rbeginCIt++, 3);
		CHECK_EQ(*rbeginCIt++, 2);
		CHECK_EQ(*rbeginCIt++, 1);
		CHECK_EQ(rbeginCIt, rendCIt);
	}
}
