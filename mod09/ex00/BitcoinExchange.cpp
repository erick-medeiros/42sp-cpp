/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 09:35:43 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/25 08:56:36 by eandre-f         ###   ########.fr       */
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
                                         std::string const   &name)
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

void BitcoinExchange::_validateDate(std::string const &date)
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
		throw std::invalid_argument("Error: invalid date: " + date);
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
		double            value;
		std::getline(ss, date, ',');
		ss >> value;
		_validateDate(date);
		// _database[date] = value;
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
