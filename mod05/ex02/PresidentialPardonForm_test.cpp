/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm_test.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:17:52 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/12 16:13:45 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "doctest.h"

TEST_SUITE("Class PresidentialPardonForm")
{
	TEST_CASE("Orthodox Canonical Form")
	{
		PresidentialPardonForm obj1;
		PresidentialPardonForm obj2(obj1);
		PresidentialPardonForm obj3 = obj2;
	}

	TEST_CASE("constructors")
	{
		SUBCASE("default")
		{
			PresidentialPardonForm obj;
			CHECK_EQ(obj.getName(), "PresidentialPardonForm");
			CHECK_EQ(obj.getGradeToSign(), 25);
			CHECK_EQ(obj.getGradeToExecute(), 5);
			CHECK_EQ(obj.getIsSigned(), false);
			CHECK_EQ(obj.getTarget(), "undefined");
		}
		SUBCASE("target")
		{
			PresidentialPardonForm obj("name");
			CHECK_EQ(obj.getName(), "PresidentialPardonForm");
			CHECK_EQ(obj.getGradeToSign(), 25);
			CHECK_EQ(obj.getGradeToExecute(), 5);
			CHECK_EQ(obj.getIsSigned(), false);
			CHECK_EQ(obj.getTarget(), "name");
		}
	}
}
