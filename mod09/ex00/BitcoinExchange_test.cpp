/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange_test.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 09:35:43 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/25 12:16:30 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "doctest.h"
#include <sstream>
#include <string>

bool fileExists(const char *name)
{
	FILE *file = fopen(name, "r");
	if (file)
	{
		fclose(file);
		return true;
	}
	return false;
}

std::string intToString(int num)
{
	std::stringstream ss;
	std::string       str;
	ss << num;
	ss >> str;
	return str;
}

TEST_SUITE("Class BitcoinExchange")
{
	TEST_CASE("Orthodox Canonical Form")
	{
		BitcoinExchange obj1;
		BitcoinExchange obj2(obj1);
		BitcoinExchange obj3 = obj2;
	}

	TEST_CASE("database")
	{
		SUBCASE("success")
		{
			BitcoinExchange btc;
			CHECK_NOTHROW(btc.openDatabase("data.csv"));
		}
		SUBCASE("error")
		{
			int i = 0;
			while (true)
			{
				std::string num = "00" + intToString(i);
				num = num.substr(num.length() - 2, 2);
				std::string database = "tests/data_err" + num + ".csv";
				if (!fileExists(database.c_str()))
					break;
				BitcoinExchange btc;
				CHECK_THROWS_MESSAGE(btc.openDatabase(database), database);
				++i;
			}
		}
	}
}
