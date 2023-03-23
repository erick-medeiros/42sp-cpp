/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:58:38 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/22 23:45:22 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int area(Point const &p1, Point const &p2, Point const &p3)
{
	Fixed x1 = p1.getX();
	Fixed y1 = p1.getY();
	Fixed x2 = p2.getX();
	Fixed y2 = p2.getY();
	Fixed x3 = p3.getX();
	Fixed y3 = p3.getY();
	Fixed r = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / Fixed(2);
	r = r.max(r, Fixed(r * -1));
	return r.toInt();
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	int areaPoint = area(a, b, point) + area(a, point, c) + area(point, b, c);
	int areaTriangle = area(a, b, c);
	return (areaTriangle == areaPoint);
}
