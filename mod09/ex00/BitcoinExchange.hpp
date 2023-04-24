/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 09:35:43 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/24 18:07:24 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <dirent.h>
#include <fstream>
#include <iostream>
#include <stdexcept>

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
	void _validateInputFile(std::ifstream const &file, std::string const &name);
};

#endif /* BITCOINEXCHANGE_HPP */
