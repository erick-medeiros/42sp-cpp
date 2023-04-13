/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:34:02 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/13 19:41:14 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

#ifndef DEBUG
#define DEBUG 0
#endif

class ScalarConverter
{
  public:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter &copy);
	~ScalarConverter(void);

	static void convert(std::string data);

  private:
};

#endif /* SCALARCONVERTER_HPP */
