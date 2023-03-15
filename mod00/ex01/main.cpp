/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:32:31 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/15 17:03:32 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main(void)
{
	PhoneBook pb;

	std::cout << "Welcome to awesome low quality phone book!!!" << std::endl;
	while (true)
	{
		std::cout << std::endl;
		std::cout << "Menu:" << std::endl;
		std::cout << std::endl;
		std::cout << "	(1) ADD" << std::endl;
		std::cout << "	(2) SEARCH" << std::endl;
		std::cout << "	(3) EXIT" << std::endl;
		std::cout << std::endl;
		if (pb.chooseCommand())
			break;
	}
}
