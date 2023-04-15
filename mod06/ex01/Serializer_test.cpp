/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer_test.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:35:43 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/14 23:47:03 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "doctest.h"

TEST_SUITE("Class Serializer")
{
	TEST_CASE("serialize and deserialize")
	{
		Data     *ptr = new Data("name", 1);
		uintptr_t serialized = Serializer::serialize(ptr);
		Data     *deserialized = Serializer::deserialize(serialized);

		CHECK_EQ(ptr, deserialized);
		CHECK_EQ(ptr->getName(), "name");
		CHECK_EQ(ptr->getNumber(), 1);
		CHECK_EQ(deserialized->getName(), "name");
		CHECK_EQ(deserialized->getNumber(), 1);
		ptr->setName("new");
		ptr->setNumber(2);
		CHECK_EQ(ptr->getName(), "new");
		CHECK_EQ(ptr->getNumber(), 2);
		CHECK_EQ(deserialized->getName(), "new");
		CHECK_EQ(deserialized->getNumber(), 2);
		delete ptr;
	}
}
