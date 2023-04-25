/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 09:35:43 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/25 13:52:29 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	if (DEBUG)
		std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	if (DEBUG)
		std::cout << "BitcoinExchange copy constructor called" << std::endl;
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (DEBUG)
		std::cout << "BitcoinExchange copy assignment operator called"
		          << std::endl;
	if (this != &copy)
	{
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
	if (DEBUG)
		std::cout << "BitcoinExchange destructor called" << std::endl;
}

void BitcoinExchange::_validateInputFile(std::ifstream const &file,
                                         std::string const   &name) const
{
	if (!file.is_open())
		throw std::invalid_argument("Error: could not open file: " + name);
	// is dir
	DIR *dir = opendir(name.c_str());
	if (dir != NULL)
	{
		closedir(dir);
		throw std::invalid_argument("Error: filename is not a file: " + name);
	}
}

void BitcoinExchange::_validateDate(std::string const &date, bool detail) const
{
	std::tm     tm = {};
	const char *format = "%Y-%m-%d";
	bool        is_valid = true;

	if (!strptime(date.c_str(), format, &tm))
		is_valid = false;
	else
	{
		char buffer[11];
		std::strftime(buffer, 11, format, &tm);
		std::string result(buffer);
		if (result != date)
			is_valid = false;
	}

	if (!is_valid)
	{
		if (detail)
			throw std::invalid_argument("Error: invalid date: " + date);
		else
			throw std::invalid_argument("Error: invalid date.");
	}
}

void BitcoinExchange::_validateValue(std::string const &value) const
{
	std::stringstream ss;
	double            number;

	ss << value;
	ss >> number;
	ss << number;

	if (ss.str() != value)
		throw std::invalid_argument("Error: invalid number.");
	if (number < 0)
		throw std::invalid_argument("Error: not a positive number.");
	if (number > 1000)
		throw std::invalid_argument("Error: too large a number.");
}

double BitcoinExchange::_convertValueDataBase(std::string const &value) const
{
	std::stringstream ss1;
	std::stringstream ss2;
	std::string       converted;
	double            number = 0;
	short             precision = 0;

	{ // get precision
		std::size_t dot = value.find('.');
		if (dot != std::string::npos)
			precision = value.size() - dot - 1;
	}

	ss1 << std::fixed << std::setprecision(precision) << value;
	ss1 >> number;
	ss2 << std::fixed << std::setprecision(precision) << number;
	converted = ss2.str();

	if (converted != value)
		throw std::invalid_argument("Error: invalid number: " + value);
	if (number < 0)
		throw std::invalid_argument("Error: not a positive number: " + value);

	return number;
}

void BitcoinExchange::openDatabase(std::string const &filename)
{
	std::ifstream input(filename.c_str());
	_validateInputFile(input, filename);

	bool        firstLine = false;
	std::string line;
	while (std::getline(input, line))
	{
		if (!firstLine && line == "date,exchange_rate")
		{
			firstLine = true;
			continue;
		}
		std::stringstream ss(line);
		std::string       date;
		std::string       value;
		std::getline(ss, date, ',');
		std::getline(ss, value);
		_validateDate(date, true);
		_database[date] = _convertValueDataBase(value);
	}

	if (!input.eof())
		throw std::runtime_error("Error: could not read the file: " + filename);

	input.close();
}

void BitcoinExchange::openInput(std::string const &filename)
{
	std::ifstream input(filename.c_str());
	_validateInputFile(input, filename);
	input.close();
}
