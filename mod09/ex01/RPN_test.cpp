/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:25:34 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/25 19:25:34 by eandre-f         ###   ########.fr       */
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
}
