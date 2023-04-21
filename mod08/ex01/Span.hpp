/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:09:56 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/21 15:31:48 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <list>
#include <stdexcept>

#ifndef DEBUG
#define DEBUG 0
#endif

class Span
{
  public:
	Span(void);
	Span(const Span &copy);
	Span &operator=(const Span &copy);
	~Span(void);

	Span(unsigned int const &max);

	void addNumber(int const &number);
	int  shortestSpan();
	int  longestSpan();

	class LessThanTwoElementsException : public std::exception
	{
		virtual const char *what() const throw();
	};

	void addManyNumbers(std::list<int>::iterator begin,
	                    std::list<int>::iterator end);

  private:
	unsigned int   _max;
	std::list<int> _values;
};

#endif /* SPAN_HPP */
