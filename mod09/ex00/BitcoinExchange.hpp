/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 09:35:43 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/25 13:52:34 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <ctime>
#include <dirent.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

#ifndef DEBUG
#define DEBUG 0
#endif

class BitcoinExchange
{
  public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &copy);
	~BitcoinExchange(void);

	void openDatabase(std::string const &filename);
	void openInput(std::string const &filename);

  private:
	void   _validateInputFile(std::ifstream const &file,
	                          std::string const   &name) const;
	void   _validateDate(std::string const &date, bool detail) const;
	void   _validateValue(std::string const &value) const;
	double _convertValueDataBase(std::string const &value) const;

	std::map<std::string, double> _database;
};

#endif /* BITCOINEXCHANGE_HPP */
