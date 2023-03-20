/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:16:53 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/20 18:31:44 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
  public:
	Fixed(void);
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &copy);
	~Fixed(void);

	Fixed(const int value);
	Fixed(const float value);

	int  getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int   toInt(void) const;

  private:
	int              _value;
	static const int _bits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif /* FIXED_HPP */
