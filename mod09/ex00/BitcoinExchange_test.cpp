/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange_test.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 09:35:43 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/25 18:26:36 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "doctest.h"
#include <fstream>
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
	TEST_CASE("input")
	{
		std::streambuf   *coutbuf = std::cout.rdbuf();
		std::stringstream oss;
		//
		BitcoinExchange btc;

		try
		{
			btc.openDatabase("data.csv");
			std::cout.rdbuf(oss.rdbuf());
			btc.openInput("tests/input.txt");
			std::cout.rdbuf(coutbuf);
		}
		catch (...)
		{
			std::cout.rdbuf(coutbuf);
			FAIL("throw");
		}

		std::ifstream result("tests/result.txt");

		if (!result.is_open())
			FAIL("not open file result.txt");

		std::string line_input;
		std::string line_output;
		while (1)
		{
			std::getline(oss, line_input);
			std::getline(result, line_output);

			CHECK_EQ(line_input, line_output);

			if (oss.eof())
				break;
			if (result.eof())
				FAIL("result.txt eof");
		}
	}

	TEST_CASE("database empty")
	{
		BitcoinExchange btc;
		CHECK_THROWS(btc.openInput("input.txt"));
	}
}
