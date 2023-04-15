/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:34:02 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/15 16:39:12 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cctype>
#include <cerrno>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

class ScalarConverter
{
  public:
	static void convert(std::string data);

  private:
	static const std::string _detectSpecialType(const std::string &data);
	static const std::string _detectLiteralType(const std::string &data);

	static void _convertChar(const std::string &data);
	static void _convertInt(const std::string &data);
	static void _convertFloat(const std::string &data);
	static void _convertDouble(const std::string &data);

	static void _impossible(void);
	static void _print(void);

	static char   _char;
	static int    _int;
	static float  _float;
	static double _double;
};

#endif /* SCALARCONVERTER_HPP */
