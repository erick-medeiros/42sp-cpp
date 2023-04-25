/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 09:35:43 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/25 17:42:55 by eandre-f         ###   ########.fr       */
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
		_database = copy._database;
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

void BitcoinExchange::_validateMinDate(std::string const &date) const
{
	std::tm     find_tm = {};
	std::tm     min_tm = {};
	const char *min_date = _database.begin()->first.c_str();
	const char *format = "%Y-%m-%d";

	if (!strptime(date.c_str(), format, &find_tm) ||
	    !strptime(min_date, format, &min_tm))
		throw std::invalid_argument("Error: intern");

	if (std::mktime(&find_tm) < std::mktime(&min_tm))
		throw std::invalid_argument("Error: invalid date " + date +
		                            ". Dates available from " + min_date);
}

void BitcoinExchange::_trimString(std::string &str) const
{
	static const char whitespace[] = " \t\n\r\f\v";

	std::string::size_type start = str.find_first_not_of(whitespace);
	if (start == std::string::npos)
	{
		str.erase();
		return;
	}

	std::string::size_type end = str.find_last_not_of(whitespace);

	str.erase(end + 1).erase(0, start);
}

float BitcoinExchange::_getValueInput(std::string const &value) const
{
	std::stringstream ss1;
	std::stringstream ss2;
	std::string       converted;
	float             number = 0;
	short             precision = _getPrecision(value);

	ss1 << std::fixed << std::setprecision(precision) << value;
	ss1 >> number;
	ss2 << std::fixed << std::setprecision(precision) << number;
	converted = ss2.str();

	if (converted != value)
		throw std::invalid_argument("Error: invalid number.");
	if (number < 0)
		throw std::invalid_argument("Error: not a positive number.");
	if (number > 1000)
		throw std::invalid_argument("Error: too large a number.");
	return number;
}

short BitcoinExchange::_getPrecision(std::string const &value) const
{
	short       precision = 0;
	std::size_t dot = value.find('.');
	if (dot != std::string::npos)
		precision = value.size() - dot - 1;
	return precision;
}

double BitcoinExchange::_getValueDatabase(std::string const &value) const
{
	std::stringstream ss1;
	std::stringstream ss2;
	std::string       converted;
	double            number = 0;
	short             precision = _getPrecision(value);

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

	bool        firstLine = true;
	std::string line;
	while (std::getline(input, line))
	{
		if (firstLine && line == "date,exchange_rate")
		{
			firstLine = false;
			continue;
		}
		std::stringstream ss(line);
		std::string       date;
		std::string       value;
		std::getline(ss, date, ',');
		std::getline(ss, value);
		_trimString(date);
		_trimString(value);
		_validateDate(date, true);
		_database[date] = _getValueDatabase(value);
	}

	if (!input.eof())
		throw std::runtime_error("Error: could not read the file: " + filename);

	input.close();
}

void BitcoinExchange::openInput(std::string const &filename)
{
	std::ifstream input(filename.c_str());
	_validateInputFile(input, filename);

	bool        firstLine = true;
	std::string line;
	while (std::getline(input, line))
	{
		if (firstLine && line == "date | value")
		{
			firstLine = false;
			continue;
		}

		std::stringstream ss(line);
		std::string       date;
		std::string       value;
		std::getline(ss, date, '|');
		if (ss.fail())
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::getline(ss, value);
		if (ss.fail())
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		_trimString(date);
		_trimString(value);
		float number = 0;
		try
		{
			_validateDate(date, true);
			_validateMinDate(date);
			number = _getValueInput(value);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
			continue;
		}
		double result = number * exchangeRate(date);
		std::cout << date << " => " << value << " = " << result << std::endl;
	}

	if (!input.eof())
		throw std::runtime_error("Error: could not read the file: " + filename);

	input.close();
}

float BitcoinExchange::exchangeRate(std::string const &date)
{
	if (_database.empty())
		return 0;

	std::string target = date;
	_trimString(target);
	std::map<std::string, double>::iterator it;

	it = _database.lower_bound(target);

	if (it->first == target)
		return it->second;
	else if (it != _database.begin())
		it--;
	return it->second;
}
