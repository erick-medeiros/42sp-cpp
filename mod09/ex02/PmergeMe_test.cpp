/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_test.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:27:23 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/26 09:27:23 by eandre-f         ###   ########.fr       */
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
