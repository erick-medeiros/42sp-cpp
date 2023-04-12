/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm_test.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:17:37 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/12 15:17:37 by eandre-f         ###   ########.fr       */
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
}
