/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm_test.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:17:37 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/12 16:13:24 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "doctest.h"

TEST_SUITE("Class ShrubberyCreationForm")
{
	TEST_CASE("Orthodox Canonical Form")
	{
		ShrubberyCreationForm obj1;
		ShrubberyCreationForm obj2(obj1);
		ShrubberyCreationForm obj3 = obj2;
	}

	TEST_CASE("constructors")
	{
		SUBCASE("default")
		{
			ShrubberyCreationForm obj;
			CHECK_EQ(obj.getName(), "ShrubberyCreationForm");
			CHECK_EQ(obj.getGradeToSign(), 145);
			CHECK_EQ(obj.getGradeToExecute(), 137);
			CHECK_EQ(obj.getIsSigned(), false);
			CHECK_EQ(obj.getTarget(), "undefined");
		}
		SUBCASE("target")
		{
			ShrubberyCreationForm obj("name");
			CHECK_EQ(obj.getName(), "ShrubberyCreationForm");
			CHECK_EQ(obj.getGradeToSign(), 145);
			CHECK_EQ(obj.getGradeToExecute(), 137);
			CHECK_EQ(obj.getIsSigned(), false);
			CHECK_EQ(obj.getTarget(), "name");
		}
	}
}
