/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:36:33 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/21 19:56:12 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0))
{
}

Point::Point(const Point &copy)
{
	*this = copy;
}

Point &Point::operator=(const Point &copy)
{
	if (this != &copy)
	{
		(Fixed &) this->_x = copy.getX();
		(Fixed &) this->_y = copy.getY();
	}
	return *this;
}

Point::~Point(void)
{
}

const Fixed &Point::getX(void) const
{
	return (_x);
}

const Fixed &Point::getY(void) const
{
	return (_y);
}

Point::Point(const float &x, const float &y) : _x(Fixed(x)), _y(Fixed(y))
{
}
