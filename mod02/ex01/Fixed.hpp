/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:16:53 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/20 17:54:20 by eandre-f         ###   ########.fr       */
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

	int  getRawBits(void) const;
	void setRawBits(int const raw);

  private:
	int              _number;
	static const int _bits = 8;
};

#endif /* FIXED_HPP */
