/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:48:20 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/12 10:15:41 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "doctest.h"
#include <exception>
#include <sstream>

TEST_SUITE("Class Form")
{
	TEST_CASE("Constructor default")
	{
		Form f;
		CHECK_EQ(f.getName(), "undefined");
		CHECK_EQ(f.getIsSigned(), false);
		CHECK_EQ(f.getGradeToSign(), 10);
		CHECK_EQ(f.getGradeToExecute(), 100);
	}

	TEST_CASE("Constructor by name, gradeToSign and gradeToExecute")
	{
		Form f("form1", 42, 101);
		CHECK_EQ(f.getName(), "form1");
		CHECK_EQ(f.getIsSigned(), false);
		CHECK_EQ(f.getGradeToSign(), 42);
		CHECK_EQ(f.getGradeToExecute(), 101);

		SUBCASE("throw high")
		{
			try
			{
				Form f("form", Bureaucrat::highestPossibleGrade - 1,
				       Bureaucrat::lowestPossibleGrade);
				FAIL("not throw");
			}
			catch (std::exception &e)
			{
				CHECK_EQ(std::string(e.what()), "grade too high!");
			}
			try
			{
				Form f("form", Bureaucrat::highestPossibleGrade,
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
				Form f("form", Bureaucrat::lowestPossibleGrade + 1,
				       Bureaucrat::lowestPossibleGrade);
				FAIL("not throw");
			}
			catch (std::exception &e)
			{
				CHECK_EQ(std::string(e.what()), "grade too low!");
			}
			try
			{
				Form f("form", Bureaucrat::highestPossibleGrade,
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
		Form               f("Name", 10, 100);

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
			Form       f("form", gradeToSign, gradeToExecute);
			Bureaucrat b("bob", gradeToSign - 1);
			f.beSigned(b);
			CHECK_EQ(f.getIsSigned(), true);
		}
		SUBCASE("pass limit")
		{
			Form       f("form", gradeToSign, gradeToExecute);
			Bureaucrat b("bob", gradeToSign);
			f.beSigned(b);
			CHECK_EQ(f.getIsSigned(), true);
		}
		SUBCASE("not pass high")
		{
			Form       f("form", gradeToSign, gradeToExecute);
			Bureaucrat b("bob", gradeToSign + 1);
			f.beSigned(b);
			CHECK_EQ(f.getIsSigned(), false);
		}
		SUBCASE("not pass low")
		{
			Form       f("form", gradeToSign, gradeToExecute);
			Bureaucrat b("bob", gradeToExecute - 1);
			f.beSigned(b);
			CHECK_EQ(f.getIsSigned(), false);
		}
		SUBCASE("throw low grade")
		{
			Form       f("form", gradeToSign, gradeToExecute);
			Bureaucrat b("bob", gradeToExecute);
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
