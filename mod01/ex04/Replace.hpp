/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:34:30 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/18 19:08:22 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <fstream>
#include <iostream>
#include <string>

class Replace
{
  public:
	Replace(std::string &filename, std::string &search, std::string &replace);
	void run(void);

  private:
	const std::string &_filename;
	const std::string &_search;
	const std::string &_replace;
};

#endif /* REPLACE_HPP */