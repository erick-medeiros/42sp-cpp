/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 09:22:11 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/15 10:07:15 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void printInt(int &value)
{
	std::cout << value << std::endl;
}

void printInt(const int &value)
{
	std::cout << value << std::endl;
}

void printString(std::string &value)
{
	std::cout << value << std::endl;
}

void printFloat(float &value)
{
	std::cout << value << std::endl;
}

int main()
{
	size_t size;
	{
		std::cout << "int:" << std::endl;
		size = 3;
		int array[] = {1, 2, 3};
		::iter(array, size, &printInt);
	}
	{
		std::cout << "string:" << std::endl;
		std::string array[] = {"a", "b", "c"};
		size = 3;
		::iter(array, size, &printString);
	}
	{
		std::cout << "float:" << std::endl;
		float array[] = {1.1, 2.2, 3.3};
		size = 3;
		::iter(array, size, &printFloat);
	}
	{
		std::cout << "const int:" << std::endl;
		const int array[] = {1, 2, 3};
		size = 3;
		::iter(array, size, &printInt);
	}
	{
		std::cout << "null:" << std::endl;
		int *array = 0;
		size = 1;
		::iter(array, size, &printInt);
		size = 0;
		::iter(array, size, &printInt);
	}
	{
		std::cout << "template print:" << std::endl;
		int array[] = {1, 2, 3};
		size = 3;
		::iter(array, size, &print);
	}
	{
		std::cout << "template const print:" << std::endl;
		const int array[] = {1, 2, 3};
		size = 3;
		::iter(array, size, &print);
	}
	return 0;
}
