/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:34:02 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/14 20:29:46 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char   ScalarConverter::_char = 0;
int    ScalarConverter::_int = 0;
float  ScalarConverter::_float = 0;
double ScalarConverter::_double = 0;

void ScalarConverter::convert(std::string data)
{
	if (_detectSpecialType(data) == "special")
		_convertSpecial(data);
	else
	{
		const std::string &type = _detectLiteralType(data);
		if (type == "char")
			_convertChar(data);
		else if (type == "int")
			_convertInt(data);
		else if (type == "float")
			_convertFloat(data);
		else if (type == "double")
			_convertDouble(data);
		else
			_impossible();
	}
}

void ScalarConverter::_reset(void)
{
	_char = 0;
	_int = 0;
	_float = 0;
	_double = 0;
}

void ScalarConverter::_impossible(void)
{
	_reset();
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::_print(void)
{
	std::cout << "char: ";
	!isascii(_int)      ? std::cout << "impossible" :
	std::isprint(_char) ? std::cout << "'" << _char << "'" :
	                      std::cout << "Non displayable";
	std::cout << std::endl;
	std::cout << "int: " << _int << std::endl;
	if (_float - std::floor(_float))
		std::cout << "float: " << _float << "f" << std::endl;
	else
		std::cout << "float: " << _float << ".0f" << std::endl;
	if (_double - std::floor(_double))
		std::cout << "double: " << _double << std::endl;
	else
		std::cout << "double: " << _double << ".0" << std::endl;
};

const std::string ScalarConverter::_detectSpecialType(const std::string &data)
{
	const int         amount = 8;
	const std::string types[amount] = {"inff", "+inff", "-inff", "inf",
	                                   "+inf", "-inf",  "nan",   "nanf"};
	for (int i = 0; i < amount; ++i)
		if (types[i] == data)
			return "special";
	return "";
}

const std::string ScalarConverter::_detectLiteralType(const std::string &data)
{
	if (data.length() == 1 && !std::isdigit(data[0]))
		return "char";

	bool isNumber = true;
	bool isDecimal = false;
	bool isFloat = false;

	std::string::const_iterator it = data.begin();
	if (data.length() > 1 && (*it == '-' || *it == '+'))
		it++;

	while (it != data.end() && isNumber)
	{
		if (!isDecimal && *it == '.')
		{
			if (!std::isdigit(*(it + 1)))
				isNumber = false;
			isDecimal = true;
		}
		else if (!isFloat && *it == 'f')
		{
			if ((it + 1) != data.end())
				isNumber = false;
			isFloat = true;
		}
		else if (!std::isdigit(*it))
			isNumber = false;
		it++;
	}

	if (isNumber)
	{
		if (!isDecimal && !isFloat)
			return "int";
		if (isDecimal && isFloat)
			return "float";
		if (isDecimal)
			return "double";
	}

	return "";
}

void ScalarConverter::_convertChar(const std::string &data)
{
	_char = static_cast<char>(*data.begin());
	_int = static_cast<int>(_char);
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);
	_print();
}

void ScalarConverter::_convertInt(const std::string &data)
{
	long _value = std::atol(data.c_str());
	if (_value > INT_MAX || _value < INT_MIN)
		_impossible();
	else
	{
		_int = static_cast<int>(_value);
		_char = static_cast<char>(_int);
		_float = static_cast<float>(_int);
		_double = static_cast<double>(_int);
		_print();
	}
}

void ScalarConverter::_convertFloat(const std::string &data)
{
	double _value = std::atof(data.c_str());
	if (_value > FLT_MAX || _value < FLT_MIN)
		_impossible();
	else
	{
		_float = static_cast<float>(_value);
		_char = static_cast<char>(_float);
		_int = static_cast<int>(_float);
		_double = static_cast<double>(_float);
		_print();
	}
}

void ScalarConverter::_convertDouble(const std::string &data)
{
	long double _value = std::strtold(data.c_str(), NULL);
	if (_value > DBL_MAX || _value < -DBL_MAX)
		_impossible();
	else
	{
		_double = static_cast<double>(_value);
		_char = static_cast<char>(_double);
		_int = static_cast<int>(_double);
		_float = static_cast<float>(_double);
		_print();
	}
}

void ScalarConverter::_convertSpecial(const std::string &data)
{
	const int         amount = 4;
	const std::string floatTypes[amount] = {"+inff", "inff", "-inff", "nanf"};
	const std::string doubleTypes[amount] = {"+inf", "inf", "-inf", "nan"};

	_reset();
	int index = 0;
	while (data != floatTypes[index] && data != doubleTypes[index])
		index++;
	if (index == 0)
		index++;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << floatTypes[index] << std::endl;
	std::cout << "double: " << doubleTypes[index] << std::endl;
}
