/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:58:47 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/26 09:04:59 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <exception>
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Usage: RPN <rpn_expression>" << std::endl;
		return 1;
	}
	if (argc > 2)
	{
		std::cout << "Error: too many arguments" << std::endl;
		return 1;
	}
	try
	{
		RPN rpn;
		std::cout << rpn.process(argv[1]) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
