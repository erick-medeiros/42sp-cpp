/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:23:38 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/21 00:14:13 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
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
	// comparison
	bool operator>(const Fixed &fixed) const;
	bool operator<(const Fixed &fixed) const;
	bool operator>=(const Fixed &fixed) const;
	bool operator<=(const Fixed &fixed) const;
	bool operator==(const Fixed &fixed) const;
	bool operator!=(const Fixed &fixed) const;
	// arithmetic
	Fixed operator+(const Fixed &fixed);
	Fixed operator-(const Fixed &fixed);
	Fixed operator*(const Fixed &fixed);
	Fixed operator/(const Fixed &fixed);
	// increment/decrement
	Fixed &operator++(void);
	Fixed &operator++(int);
	Fixed &operator--(void);
	Fixed &operator--(int);

	int  getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int   toInt(void) const;

	static Fixed       &min(Fixed &fixed1, Fixed &fixed2);
	static const Fixed &min(Fixed const &fixed1, Fixed const &fixed2);
	static Fixed       &max(Fixed &fixed1, Fixed &fixed2);
	static const Fixed &max(Fixed const &fixed1, Fixed const &fixed2);

  private:
	int              _value;
	static const int _bits;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif /* FIXED_HPP */
