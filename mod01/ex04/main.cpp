/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:24:17 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/17 16:55:05 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "usage: replace [FILENAME] [SEARCH] [REPLACE]"
		          << std::endl;
		return (1);
	}
	else if (argc < 4)
	{
		std::cerr << "few arguments" << std::endl;
		return (1);
	}
	else if (argc > 4)
	{
		std::cerr << "many arguments" << std::endl;
		return (1);
	}

	std::string argFilename(argv[1]);
	std::string argSearch(argv[2]);
	std::string argReplace(argv[3]);

	Replace replace(argFilename, argSearch, argReplace);

	try
	{
		replace.run();
	}
	catch (std::string error)
	{
		std::cerr << error << std::endl;
	}
}
