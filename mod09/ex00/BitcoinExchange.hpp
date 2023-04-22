/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 09:35:43 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/22 09:35:43 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>

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

  private:
};

#endif /* BITCOINEXCHANGE_HPP */
