/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:23:41 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/22 23:57:12 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <sstream>
#include <string>

// the program is not 100% accurate

int main(int argc, char *argv[])
{
	Point a, b, c, point;

	if (argc < 9)
	{
		a = Point(0, 0);
		b = Point(10, 10);
		c = Point(15, 0);
		point = Point(5, 5);
	}
	else
	{
		std::stringstream ss;
		float             f1, f2;

		for (int i = 1; i < 9; i++)
			ss << argv[i] << std::endl;
		ss >> f1;
		ss >> f2;
		a = Point(f1, f2);
		ss >> f1;
		ss >> f2;
		b = Point(f1, f2);
		ss >> f1;
		ss >> f2;
		c = Point(f1, f2);
		ss >> f1;
		ss >> f2;
		point = Point(f1, f2);
	}

	std::cout << "The point[" << point.getX() << "," << point.getY() << "]";
	if (bsp(a, b, c, point))
		std::cout << " is inside ";
	else
		std::cout << " is not inside ";
	std::cout << "the triangle";
	std::cout << "[" << a.getX() << "," << a.getY() << "]";
	std::cout << "[" << b.getX() << "," << b.getY() << "]";
	std::cout << "[" << c.getX() << "," << c.getY() << "]";
	std::cout << std::endl;
	return 0;
}
