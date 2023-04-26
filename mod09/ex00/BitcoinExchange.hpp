/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 09:35:43 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/26 17:16:23 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <dirent.h>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

#ifndef DEBUG
#define DEBUG 0
#endif

#define DATE_FORMAT "%Y-%m-%d"

class BitcoinExchange
{
  public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &copy);
	~BitcoinExchange(void);

	void  openDatabase(std::string const &filename);
	void  openInput(std::string const &filename);
	float exchangeRate(std::string const &date);

	class Error : public std::exception
	{
	  public:
		Error(std::string const &err);
		Error();
		Error(const Error &copy);
		Error &operator=(const Error &copy);
		virtual ~Error(void) throw();
		virtual const char *what() const throw();

	  private:
		std::string _message;
	};

  private:
	void _trim(std::string &s) const;

	void   _validateInputFile(std::ifstream const &file,
	                          std::string const   &name) const;
	bool   _isValidDate(std::string const &date) const;
	void   _validateInputDate(std::string const &date) const;
	float  _getValueInput(std::string const &value) const;
	double _getValueDatabase(std::string const &database,
	                         std::string const &value) const;

	short _getPrecision(std::string const &value) const;
	bool  _getLineInfo(std::string const &line, char delimiter,
	                   std::string &date, std::string &value) const;

	std::map<std::string, double> _database;
};

#endif /* BITCOINEXCHANGE_HPP */
