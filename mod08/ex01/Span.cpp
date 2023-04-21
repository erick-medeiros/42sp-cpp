/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:09:56 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/21 15:42:37 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _max(0), _values(std::list<int>())
{
	if (DEBUG)
		std::cout << "Span default constructor called" << std::endl;
}

Span::Span(const Span &copy)
{
	if (DEBUG)
		std::cout << "Span copy constructor called" << std::endl;
	*this = copy;
}

Span &Span::operator=(const Span &copy)
{
	if (DEBUG)
		std::cout << "Span copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		_max = copy._max;
		_values = copy._values;
	}
	return *this;
}

Span::~Span(void)
{
	if (DEBUG)
		std::cout << "Span destructor called" << std::endl;
}

Span::Span(unsigned int const &max) : _max(max), _values(std::list<int>())
{
	if (DEBUG)
		std::cout << "Span constructor by max called" << std::endl;
}

void Span::addNumber(int const &number)
{
	if (_values.size() >= _max)
		throw std::overflow_error("max limit of elements exceeded");
	_values.push_back(number);
}

void Span::addManyNumbers(std::list<int>::iterator begin,
                          std::list<int>::iterator end)
{
	while (begin != end)
		addNumber(*begin++);
}

const char *Span::LessThanTwoElementsException::what() const throw()
{
	return "no Span can be found because it has less than 2 elements";
}

int Span::shortestSpan()
{
	if (_values.size() <= 1)
		throw Span::LessThanTwoElementsException();

	std::list<int>::iterator prev;
	std::list<int>::iterator it;
	int                      shortest;
	int                      distance;

	_values.sort();

	for (it = _values.begin(); it != _values.end(); ++it)
	{
		if (it != _values.begin())
		{
			distance = abs(*it - *prev);
			if (prev == _values.begin())
				shortest = distance;
			shortest = (distance < shortest) ? distance : shortest;
		}
		prev = it;
	}

	return shortest;
};

int Span::longestSpan()
{
	if (_values.size() <= 1)
		throw Span::LessThanTwoElementsException();
	_values.sort();
	return _values.back() - _values.front();
};
