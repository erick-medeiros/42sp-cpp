/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:16:53 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/20 12:16:53 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
  public:
	Fixed(void);
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &copy);
	~Fixed(void);

  private:
};

#endif /* FIXED_HPP */
