/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange_test.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 09:35:43 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/22 09:35:43 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "doctest.h"

TEST_SUITE("Class BitcoinExchange")
{
	TEST_CASE("Orthodox Canonical Form")
	{
		BitcoinExchange obj1;
		BitcoinExchange obj2(obj1);
		BitcoinExchange obj3 = obj2;
	}
}
