/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:48:20 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/12 15:19:17 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "doctest.h"
#include <exception>
#include <sstream>

TEST_SUITE("Class Form")
{
	TEST_CASE("Constructor default")
	{
		AForm f;
		CHECK_EQ(f.getName(), "undefined");
		CHECK_EQ(f.getIsSigned(), false);
		CHECK_EQ(f.getGradeToSign(), 10);
		CHECK_EQ(f.getGradeToExecute(), 100);
	}

	TEST_CASE("Constructor by name, gradeToSign and gradeToExecute")
	{
		AForm f("form1", 42, 101);
		CHECK_EQ(f.getName(), "form1");
		CHECK_EQ(f.getIsSigned(), false);
		CHECK_EQ(f.getGradeToSign(), 42);
		CHECK_EQ(f.getGradeToExecute(), 101);

		SUBCASE("throw high")
		{
			try
			{
				AForm f("form", Bureaucrat::highestPossibleGrade - 1,
				        Bureaucrat::lowestPossibleGrade);
				FAIL("not throw");
			}
			catch (std::exception &e)
			{
				CHECK_EQ(std::string(e.what()), "grade too high!");
			}
			try
			{
				AForm f("form", Bureaucrat::highestPossibleGrade,
				        Bureaucrat::highestPossibleGrade - 1);
				FAIL("not throw");
			}
			catch (std::exception &e)
			{
				CHECK_EQ(std::string(e.what()), "grade too high!");
			}
		}
		SUBCASE("throw low")
		{
			try
			{
				AForm f("form", Bureaucrat::lowestPossibleGrade + 1,
				        Bureaucrat::lowestPossibleGrade);
				FAIL("not throw");
			}
			catch (std::exception &e)
			{
				CHECK_EQ(std::string(e.what()), "grade too low!");
			}
			try
			{
				AForm f("form", Bureaucrat::highestPossibleGrade,
				        Bureaucrat::lowestPossibleGrade + 1);
				FAIL("not throw");
			}
			catch (std::exception &e)
			{
				CHECK_EQ(std::string(e.what()), "grade too low!");
			}
		}
	}

	TEST_CASE("operator<<")
	{
		std::ostringstream oss;
		std::ostream       os(oss.rdbuf());
		AForm              f("Name", 10, 100);

		os << f;
		CHECK_EQ(oss.str(), "Name form, not is signed, grade to sign is 10 and "
		                    "grade to execute is 100");
	}

	TEST_CASE("beSigned")
	{
		const int gradeToSign = 5;
		const int gradeToExecute = 10;

		SUBCASE("pass")
		{
			AForm      f("form", gradeToSign, gradeToExecute);
			Bureaucrat b("bob", gradeToSign - 1);
			f.beSigned(b);
			CHECK_EQ(f.getIsSigned(), true);
		}
		SUBCASE("pass limit")
		{
			AForm      f("form", gradeToSign, gradeToExecute);
			Bureaucrat b("bob", gradeToSign);
			f.beSigned(b);
			CHECK_EQ(f.getIsSigned(), true);
		}
		SUBCASE("not pass high")
		{
			AForm      f("form", gradeToSign, gradeToExecute);
			Bureaucrat b("bob", gradeToSign + 1);
			try
			{
				f.beSigned(b);
				FAIL("not throw");
			}
			catch (std::exception &e)
			{
				CHECK_EQ(std::string(e.what()), "grade too low!");
			}
		}
	}
}
