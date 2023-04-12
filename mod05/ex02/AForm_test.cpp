/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:48:20 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/12 19:28:11 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm_test.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "doctest.h"
#include <exception>
#include <sstream>

TEST_SUITE("Class Form")
{
	TEST_CASE("Constructor default")
	{
		AForm_test f;
		CHECK_EQ(f.getName(), "undefined");
		CHECK_EQ(f.getIsSigned(), false);
		CHECK_EQ(f.getGradeToSign(), 10);
		CHECK_EQ(f.getGradeToExecute(), 100);
	}

	TEST_CASE("Constructor by name, gradeToSign and gradeToExecute")
	{
		AForm_test f("form1", 42, 101);
		CHECK_EQ(f.getName(), "form1");
		CHECK_EQ(f.getIsSigned(), false);
		CHECK_EQ(f.getGradeToSign(), 42);
		CHECK_EQ(f.getGradeToExecute(), 101);

		SUBCASE("throw high")
		{
			try
			{
				AForm_test f("form", Bureaucrat::highestPossibleGrade - 1,
				             Bureaucrat::lowestPossibleGrade);
				FAIL("not throw");
			}
			catch (std::exception &e)
			{
				CHECK_EQ(std::string(e.what()), "grade too high!");
			}
			try
			{
				AForm_test f("form", Bureaucrat::highestPossibleGrade,
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
				AForm_test f("form", Bureaucrat::lowestPossibleGrade + 1,
				             Bureaucrat::lowestPossibleGrade);
				FAIL("not throw");
			}
			catch (std::exception &e)
			{
				CHECK_EQ(std::string(e.what()), "grade too low!");
			}
			try
			{
				AForm_test f("form", Bureaucrat::highestPossibleGrade,
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
		AForm_test         f("Name", 10, 100);

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
			AForm_test f("form", gradeToSign, gradeToExecute);
			Bureaucrat b("bob", gradeToSign - 1);
			f.beSigned(b);
			CHECK_EQ(f.getIsSigned(), true);
		}
		SUBCASE("pass limit")
		{
			AForm_test f("form", gradeToSign, gradeToExecute);
			Bureaucrat b("bob", gradeToSign);
			f.beSigned(b);
			CHECK_EQ(f.getIsSigned(), true);
		}
		SUBCASE("not pass high")
		{
			AForm_test f("form", gradeToSign, gradeToExecute);
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

	TEST_CASE("execute")
	{
		const int gradeToSign = 10;
		const int gradeToExecute = 5;

		SUBCASE("success")
		{
			AForm_test f("form", gradeToSign, gradeToExecute);
			Bureaucrat b("bob", gradeToExecute);
			f.beSigned(b);
			f.execute(b);
		}
		SUBCASE("not signed")
		{
			AForm_test f("form", gradeToSign, gradeToExecute);
			Bureaucrat b("bob", gradeToExecute + 1);
			// f.beSigned(b);
			try
			{
				f.execute(b);
				FAIL("not throw");
			}
			catch (std::exception &e)
			{
				CHECK_EQ(std::string(e.what()), "form is not signed!");
			}
		}
		SUBCASE("grade too low to execute")
		{
			AForm_test f("form", gradeToSign, gradeToExecute);
			Bureaucrat b("bob", gradeToExecute + 1);
			f.beSigned(b);
			try
			{
				f.execute(b);
				FAIL("not throw");
			}
			catch (std::exception &e)
			{
				CHECK_EQ(std::string(e.what()), "grade too low to execute!");
			}
		}
	}
}
