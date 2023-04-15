/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:35:35 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/14 23:45:38 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "doctest.h"

TEST_SUITE("Class Data")
{
	TEST_CASE("Orthodox Canonical Form")
	{
		Data obj1;
		Data obj2(obj1);
		Data obj3 = obj2;
	}
	TEST_CASE("data")
	{
		Data obj("name", 1);
		CHECK_EQ(obj.getName(), "name");
		CHECK_EQ(obj.getNumber(), 1);
		obj.setName("new");
		obj.setNumber(2);
		CHECK_EQ(obj.getName(), "new");
		CHECK_EQ(obj.getNumber(), 2);
	}
}
