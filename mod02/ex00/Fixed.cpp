/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:32:26 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/20 13:32:26 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
}

Fixed::Fixed(const Fixed &copy)
{
	(void) copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	if (this != &copy)
	{
		(void) copy;
	}
	return *this;
}

Fixed::~Fixed(void)
{
}
