/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:02:52 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/17 23:18:27 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include "Replace.hpp"
#include "doctest.h"

TEST_CASE("Error opening")
{
	std::string argFilename("_filename_");
	std::string argNot("_not_");
	std::string argExist("_exist_");

	Replace replace(argFilename, argNot, argExist);
	try
	{
		replace.run();
		CHECK(false);
	}
	catch (std::string error)
	{
		CHECK_EQ(error, "Error opening: _filename_");
	}
}
