/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 09:35:43 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/24 18:05:54 by eandre-f         ###   ########.fr       */
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

void BitcoinExchange::openDatabase(std::string const &filename)
{
	std::ifstream input(filename.c_str());
	_validateInputFile(input, filename);
	input.close();
}

void BitcoinExchange::openInput(std::string const &filename)
{
	std::ifstream input(filename.c_str());
	_validateInputFile(input, filename);
	input.close();
}
