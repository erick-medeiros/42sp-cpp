/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter_test.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:34:02 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/13 18:34:02 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "doctest.h"

TEST_SUITE("Class ScalarConverter")
{
	TEST_CASE("Orthodox Canonical Form")
	{
		ScalarConverter obj1;
		ScalarConverter obj2(obj1);
		ScalarConverter obj3 = obj2;
	}
}
