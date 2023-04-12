/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm_test.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:17:46 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/12 16:12:45 by eandre-f         ###   ########.fr       */
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

	TEST_CASE("constructors")
	{
		SUBCASE("default")
		{
			RobotomyRequestForm obj;
			CHECK_EQ(obj.getName(), "RobotomyRequestForm");
			CHECK_EQ(obj.getGradeToSign(), 72);
			CHECK_EQ(obj.getGradeToExecute(), 45);
			CHECK_EQ(obj.getIsSigned(), false);
			CHECK_EQ(obj.getTarget(), "undefined");
		}
		SUBCASE("target")
		{
			RobotomyRequestForm obj("name");
			CHECK_EQ(obj.getName(), "RobotomyRequestForm");
			CHECK_EQ(obj.getGradeToSign(), 72);
			CHECK_EQ(obj.getGradeToExecute(), 45);
			CHECK_EQ(obj.getIsSigned(), false);
			CHECK_EQ(obj.getTarget(), "name");
		}
	}
}
