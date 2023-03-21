/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:36:33 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/21 18:36:33 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void)
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
		(void) copy;
	}
	return *this;
}

Point::~Point(void)
{
}
