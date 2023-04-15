/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:35:35 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/14 23:43:32 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

#ifndef DEBUG
#define DEBUG 0
#endif

class Data
{
  public:
	Data(void);
	Data(const Data &copy);
	Data &operator=(const Data &copy);
	~Data(void);

	Data(const std::string &name, const int &number);

	const std::string &getName() const;
	void               setName(const std::string &name);

	const int &getNumber() const;
	void       setNumber(const int &number);

  private:
	std::string _name;
	int         _number;
};

#endif /* DATA_HPP */
