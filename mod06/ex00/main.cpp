/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:34:31 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/13 19:42:43 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		if (argc > 2)
			std::cerr << "Error: too many arguments" << std::endl;
		else
			std::cerr << "Error: missing command 'convert DATA'" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
