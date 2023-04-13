/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:23:00 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/13 18:11:50 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "doctest.h"
#include <exception>

TEST_SUITE("Class Intern")
{
	TEST_CASE("Orthodox Canonical Form")
	{
		Intern obj1;
		Intern obj2(obj1);
		Intern obj3 = obj2;
	}
	TEST_CASE("makeForm")
	{
		SUBCASE("presidential pardon")
		{
			Intern      i;
			AForm      *f;
			std::string target("home1");
			f = i.makeForm("presidential pardon", target);
			CHECK_EQ(f->getName(), "PresidentialPardonForm");
			CHECK_EQ(f->getTarget(), target);
			delete f;
		}
		SUBCASE("robotomy request")
		{
			Intern      i;
			AForm      *f;
			std::string target("home2");
			f = i.makeForm("robotomy request", target);
			CHECK_EQ(f->getName(), "RobotomyRequestForm");
			CHECK_EQ(f->getTarget(), target);
			delete f;
		}
		SUBCASE("shrubbery creation")
		{
			Intern      i;
			AForm      *f;
			std::string target("home3");
			f = i.makeForm("shrubbery creation", target);
			CHECK_EQ(f->getName(), "ShrubberyCreationForm");
			CHECK_EQ(f->getTarget(), target);
			delete f;
		}
		SUBCASE("error")
		{
			try
			{
				Intern i;
				AForm *f = i.makeForm("", "target");
				delete f;
				FAIL("not throw");
			}
			catch (std::exception &e)
			{
				CHECK_EQ(std::string(e.what()), "form does not exist");
			}
		}
	}
}
