/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:36:33 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/21 19:52:39 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
  public:
	Point(void);
	Point(const Point &copy);
	Point &operator=(const Point &copy);
	~Point(void);

	Point(const float &x, const float &y);

	const Fixed &getX(void) const;
	const Fixed &getY(void) const;

  private:
	const Fixed _x;
	const Fixed _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif /* POINT_HPP */
