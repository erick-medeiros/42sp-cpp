/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:36:33 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/21 18:36:33 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

class Point
{
  public:
	Point(void);
	Point(const Point &copy);
	Point &operator=(const Point &copy);
	~Point(void);

  private:
};

#endif /* POINT_HPP */
