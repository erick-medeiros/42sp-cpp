/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm_test.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:17:46 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/12 15:17:46 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "doctest.h"

TEST_SUITE("Class RobotomyRequestForm")
{
	TEST_CASE("Orthodox Canonical Form")
	{
		RobotomyRequestForm obj1;
		RobotomyRequestForm obj2(obj1);
		RobotomyRequestForm obj3 = obj2;
	}
}
