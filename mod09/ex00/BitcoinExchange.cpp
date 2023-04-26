/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 09:35:43 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/26 17:16:35 by eandre-f         ###   ########.fr       */
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

// error init

BitcoinExchange::Error::Error() {}

BitcoinExchange::Error::Error(std::string const &err)
{
	BitcoinExchange::Error::_message = err;
}

BitcoinExchange::Error::Error(const BitcoinExchange::Error &copy)
{
	*this = copy;
}

BitcoinExchange::Error &
BitcoinExchange::Error::operator=(const BitcoinExchange::Error &copy)
{
	_message = copy._message;
	return *this;
}

BitcoinExchange::Error::~Error() throw() {}

const char *BitcoinExchange::Error::what() const throw()
{
	return BitcoinExchange::Error::_message.c_str();
}

// error end

void BitcoinExchange::_validateInputFile(std::ifstream const &file,
                                         std::string const   &name) const
{
	if (!file.is_open())
		throw Error("could not open file: " + name);
	// is dir
	DIR *dir = opendir(name.c_str());
	if (dir != NULL)
	{
		closedir(dir);
		throw Error("filename is not a file: " + name);
	}
}

bool BitcoinExchange::_isValidDate(std::string const &date) const
{
	std::tm tm = {};
	bool    is_valid = true;

	if (!strptime(date.c_str(), DATE_FORMAT, &tm))
		is_valid = false;
	else
	{
		char buffer[11];
		std::strftime(buffer, 11, DATE_FORMAT, &tm);
		std::string result(buffer);
		if (result != date)
			is_valid = false;
	}
	return (is_valid);
}

void BitcoinExchange::_validateInputDate(std::string const &date) const
{
	if (_database.empty())
		return;
	std::tm     date_tm = {};
	std::tm     min_tm = {};
	const char *min = _database.begin()->first.c_str();

	if (!_isValidDate(date))
		throw Error("invalid date: " + date);
	if (!strptime(date.c_str(), DATE_FORMAT, &date_tm) ||
	    !strptime(min, DATE_FORMAT, &min_tm))
		throw Error("intern");
	if (std::mktime(&date_tm) < std::mktime(&min_tm))
		throw Error("invalid date " + date + ". Dates available from " + min);
}

void BitcoinExchange::_trim(std::string &s) const
{
	static const char      whitespace[] = " \t\n\r\f\v";
	std::string::size_type start = s.find_first_not_of(whitespace);
	if (start == std::string::npos)
	{
		s.erase();
		return;
	}
	std::string::size_type end = s.find_last_not_of(whitespace);
	s.erase(end + 1).erase(0, start);
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
		throw Error("invalid number.");
	if (number < 0)
		throw Error("not a positive number.");
	if (number > 1000)
		throw Error("too large a number.");
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

double BitcoinExchange::_getValueDatabase(std::string const &database,
                                          std::string const &value) const
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
		throw Error("in database " + database + ": invalid number: " + value);
	if (number < 0)
		throw Error("in database " + database + ": negative number: " + value);
	return number;
}

bool BitcoinExchange::_getLineInfo(std::string const &line, char delimiter,
                                   std::string &date, std::string &value) const
{
	std::stringstream ss(line);
	std::getline(ss, date, delimiter);
	if (ss.fail())
		return false;
	std::getline(ss, value);
	if (ss.fail())
		return false;
	_trim(date);
	_trim(value);
	return true;
};

void BitcoinExchange::openDatabase(std::string const &filename)
{
	std::ifstream input(filename.c_str());
	_validateInputFile(input, filename);

	bool        firstLine = true;
	std::string line, date, value;
	while (std::getline(input, line))
	{
		if (firstLine)
		{
			if (line == "date,exchange_rate")
				continue;
			firstLine = false;
		}
		if (line.empty())
			continue;
		if (!_getLineInfo(line, ',', date, value))
			throw Error("in database " + filename + ": bad line: " + line);
		if (!_isValidDate(date))
			throw Error("in database " + filename + ": invalid date: " + date);
		_database[date] = _getValueDatabase(filename, value);
	}
	input.close();
	if (_database.empty())
		throw Error("database empty");
}

void BitcoinExchange::openInput(std::string const &filename)
{
	if (_database.empty())
		throw Error("database empty");
	std::ifstream input(filename.c_str());
	_validateInputFile(input, filename);

	bool        firstLine = true;
	std::string line, date, value;
	while (std::getline(input, line))
	{
		if (firstLine)
		{
			if (line == "date | value")
				continue;
			firstLine = false;
		}

		if (line.empty())
			continue;

		try
		{
			if (!_getLineInfo(line, '|', date, value))
				throw Error("bad input => " + line);
			_validateInputDate(date);
			float  number = _getValueInput(value);
			double result = number * exchangeRate(date);
			std::cout << date << " => " << value << " = " << result
			          << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	input.close();
}

float BitcoinExchange::exchangeRate(std::string const &date)
{
	if (_database.empty())
		return 0;

	std::string target = date;
	_trim(target);
	std::map<std::string, double>::iterator it;

	it = _database.lower_bound(target);

	if (it->first == target)
		return it->second;
	else if (it != _database.begin())
		it--;
	return it->second;
}
