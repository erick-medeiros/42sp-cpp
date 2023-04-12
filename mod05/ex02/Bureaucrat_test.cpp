/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _Bureaucrat_test.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 08:20:30 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/12 17:19:41 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm_test.hpp"
#include "Bureaucrat.hpp"
#include "doctest.h"
#include <exception>
#include <ostream>
#include <sstream>

TEST_SUITE("Class Bureaucrat")
{
	TEST_CASE("Constructor by name")
	{
		std::string name1("test1");
		std::string name2("test2");
		Bureaucrat  b1(name1);
		Bureaucrat  b2(name2);
		CHECK_EQ(b1.getName(), name1);
		CHECK_EQ(b2.getName(), name2);
	}

	TEST_CASE("Constructor by name and grade")
	{
		std::string name1("test1");
		int         grade1 = 10;
		std::string name2("test2", 20);
		int         grade2 = 20;
		Bureaucrat  b1(name1, grade1);
		Bureaucrat  b2(name2, grade2);
		CHECK_EQ(b1.getName(), name1);
		CHECK_EQ(b2.getName(), name2);
		CHECK_EQ(b1.getGrade(), grade1);
		CHECK_EQ(b2.getGrade(), grade2);
	}

	TEST_CASE("increment grade")
	{
		Bureaucrat b("test", 10);
		CHECK_EQ(b.getGrade(), 10);
		b.incrementGrade();
		CHECK_EQ(b.getGrade(), 9);
		b.incrementGrade();
		CHECK_EQ(b.getGrade(), 8);
	}

	TEST_CASE("decrement grade")
	{
		Bureaucrat b("test", 10);
		CHECK_EQ(b.getGrade(), 10);
		b.decrementGrade();
		CHECK_EQ(b.getGrade(), 11);
		b.decrementGrade();
		CHECK_EQ(b.getGrade(), 12);
	}

	TEST_CASE("output stream")
	{
		std::ostringstream oss;
		std::ostream       os(oss.rdbuf());

		SUBCASE("simple")
		{
			Bureaucrat b("test", 10);
			os << b;
			CHECK_EQ(oss.str(), "test, bureaucrat grade 10.");
		}
		SUBCASE("empty")
		{
			Bureaucrat b;
			os << b;
			CHECK_EQ(oss.str(), "undefined, bureaucrat grade 150.");
		}
		SUBCASE("increment")
		{
			Bureaucrat b("test", 10);
			b.incrementGrade();
			os << b;
			CHECK_EQ(oss.str(), "test, bureaucrat grade 9.");
		}
		SUBCASE("decrement")
		{
			Bureaucrat b("test", 10);
			b.decrementGrade();
			os << b;
			CHECK_EQ(oss.str(), "test, bureaucrat grade 11.");
		}
	}

	TEST_CASE("exception GradeTooHighException")
	{
		SUBCASE("constructor")
		{
			CHECK_NOTHROW(Bureaucrat b("test", 1));
			CHECK_THROWS_AS(Bureaucrat b("test", 0), std::exception);
		}

		SUBCASE("increment grade")
		{
			Bureaucrat b("test", 1);
			CHECK_THROWS_AS(b.incrementGrade(), std::exception);
		}

		SUBCASE("message")
		{
			try
			{
				Bureaucrat b("test", 0);
				FAIL("Did not throw an exception");
			}
			catch (std::exception &e)
			{
				CHECK_EQ(std::string(e.what()), "grade too high!");
			}
		}
	}

	TEST_CASE("exception lowestPossibleGrade")
	{
		SUBCASE("constructor")
		{
			CHECK_NOTHROW(Bureaucrat b("test", 150));
			CHECK_THROWS_AS(Bureaucrat b("test", 151), std::exception);
		}

		SUBCASE("decrement grade")
		{
			Bureaucrat b("test", 150);
			CHECK_THROWS_AS(b.decrementGrade(), std::exception);
		}

		SUBCASE("message")
		{
			try
			{
				Bureaucrat b("test", 151);
				FAIL("Did not throw an exception");
			}
			catch (std::exception &e)
			{
				CHECK_EQ(std::string(e.what()), "grade too low!");
			}
		}
	}
}

TEST_CASE("signForm")
{
	std::streambuf    *coutbuf = std::cout.rdbuf();
	std::ostringstream oss;
	SUBCASE("pass")
	{
		AForm_test f("form", 10, 15);
		Bureaucrat b("bob", 5);

		std::cout.rdbuf(oss.rdbuf());
		b.signForm(f);
		std::cout.rdbuf(coutbuf);
		CHECK_EQ(oss.str(), "bob signed form\n");
	}
	SUBCASE("not pass throw")
	{
		AForm_test f("form", 10, 15);
		Bureaucrat b("bob", 13);

		std::cout.rdbuf(oss.rdbuf());
		b.signForm(f);
		std::cout.rdbuf(coutbuf);
		CHECK_EQ(oss.str(), "bob couldn't sign form because grade too low!\n");
	}
	SUBCASE("not pass throw")
	{
		AForm_test f("form", 10, 15);
		Bureaucrat b("bob", 17);

		std::cout.rdbuf(oss.rdbuf());
		b.signForm(f);
		std::cout.rdbuf(coutbuf);
		CHECK_EQ(oss.str(), "bob couldn't sign form because grade too low!\n");
	}
}
