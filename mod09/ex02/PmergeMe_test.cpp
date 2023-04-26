/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_test.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:27:23 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/26 12:57:12 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "doctest.h"

TEST_SUITE("Class PmergeMe")
{
	TEST_CASE("Orthodox Canonical Form")
	{
		PmergeMe obj1;
		PmergeMe obj2(obj1);
		PmergeMe obj3 = obj2;
	}
}

TEST_SUITE("checkArgs")
{
	TEST_CASE("not a number")
	{
		{
			const char *argv[] = {"./", "a", NULL};
			CHECK_FALSE(PmergeMe::checkArgs(argv));
		}
		{
			const char *argv[] = {"./", "^", NULL};
			CHECK_FALSE(PmergeMe::checkArgs(argv));
		}
		{
			const char *argv[] = {"./", "-", NULL};
			CHECK_FALSE(PmergeMe::checkArgs(argv));
		}
	}
	TEST_CASE("simbols")
	{
		{
			const char *argv[] = {"./", "-1", NULL};
			CHECK_FALSE(PmergeMe::checkArgs(argv));
		}
		{
			const char *argv[] = {"./", "+1", NULL};
			CHECK_FALSE(PmergeMe::checkArgs(argv));
		}
	}
	TEST_CASE("decimal numbers")
	{
		{
			const char *argv[] = {"./", "1.1", NULL};
			CHECK_FALSE(PmergeMe::checkArgs(argv));
		}
	}
	TEST_CASE("positives")
	{
		{
			const char *argv[] = {"./", "10", NULL};
			CHECK(PmergeMe::checkArgs(argv));
		}
		{
			const char *argv[] = {"./", "20", NULL};
			CHECK(PmergeMe::checkArgs(argv));
		}
	}
}