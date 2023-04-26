/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:27:33 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/26 17:36:52 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <exception>

// merge-insert

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage: PmergeMe <num1 num2 num3 ... numX>" << std::endl;
		return 1;
	}
	try
	{
		if (!PmergeMe::checkArgs(argv))
			throw std::invalid_argument("Error: invalid input");
		PmergeMe mi;
		mi.sort(&argv[1]);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
