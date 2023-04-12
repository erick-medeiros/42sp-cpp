/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm_test.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:17:52 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/12 15:17:52 by eandre-f         ###   ########.fr       */
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
}
