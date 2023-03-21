/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:23:31 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/21 18:26:53 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(void) : _value(0)
{
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	if (this != &copy)
		this->setRawBits(copy.getRawBits());
	return *this;
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(const int value) : _value(value << _bits)
{
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _bits)))
{
}

int Fixed::getRawBits(void) const
{
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float) _value / (1 << _bits));
}

int Fixed::toInt(void) const
{
	return (_value >> _bits);
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return (this->getRawBits() > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return (this->getRawBits() < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return (this->getRawBits() >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return (this->getRawBits() <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return (this->getRawBits() == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return (this->getRawBits() != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed &fixed)
{
	Fixed copy;

	copy.setRawBits(this->getRawBits() + fixed.getRawBits());
	return (copy);
}

Fixed Fixed::operator-(const Fixed &fixed)
{
	Fixed copy;

	copy.setRawBits(this->getRawBits() - fixed.getRawBits());
	return (copy);
}

Fixed Fixed::operator*(const Fixed &fixed)
{
	Fixed    copy;
	long int raw = this->getRawBits() * fixed.getRawBits();
	raw += (1 << (_bits - 1)); // rounding
	raw = raw >> _bits;
	if (raw > INT_MAX)
		raw = INT_MAX;
	if (raw < INT_MIN)
		raw = INT_MIN;
	copy.setRawBits(raw);
	return (copy);
}

Fixed Fixed::operator/(const Fixed &fixed)
{
	Fixed    copy;
	long int raw = this->getRawBits();
	long int div = fixed.getRawBits();

	if (div == 0)
	{
		copy.setRawBits(INT_MIN);
		return (copy);
	}

	raw = raw << _bits;
	raw = raw + (div >> 1); // rounding

	copy.setRawBits(raw / div);
	return (copy);
}

Fixed &Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed copy = *this;
	this->setRawBits(this->getRawBits() + 1);
	return (copy);
}

Fixed &Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed copy = *this;
	this->setRawBits(this->getRawBits() - 1);
	return (copy);
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 > fixed2)
		return fixed2;
	else
		return fixed1;
}

const Fixed &Fixed::min(Fixed const &fixed1, Fixed const &fixed2)
{
	if (fixed1 > fixed2)
		return fixed2;
	else
		return fixed1;
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 > fixed2)
		return fixed1;
	else
		return fixed2;
}

const Fixed &Fixed::max(Fixed const &fixed1, Fixed const &fixed2)
{
	if (fixed1 > fixed2)
		return fixed1;
	else
		return fixed2;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
