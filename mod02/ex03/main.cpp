/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:23:41 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/22 20:03:54 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main(void)
{
	bsp(Point(0, 0), Point(0, 1), Point(1, 0), Point(1, 0));
	bsp(Point(0, 0), Point(0, 1), Point(1, 0), Point(1, 0));
	bsp(Point(0, 0), Point(0, 1), Point(1, 0), Point(0.9, 0));
	bsp(Point(0, 0), Point(5, 5), Point(10, 0), Point(1, 1));
	return 0;
}
