/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:25:34 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/28 17:14:56 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
	if (DEBUG)
		std::cout << "RPN default constructor called" << std::endl;
}

RPN::RPN(const RPN &copy)
{
	if (DEBUG)
		std::cout << "RPN copy constructor called" << std::endl;
	*this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
	if (DEBUG)
		std::cout << "RPN copy assignment operator called" << std::endl;
	if (this != &copy)
	{
	}
	return *this;
}

RPN::~RPN(void)
{
	if (DEBUG)
		std::cout << "RPN destructor called" << std::endl;
}

RPN::rpn_t RPN::process(char const *expression) const
{
	static size_t const      NPOS = std::string::npos;
	static char const        SEPARATOR = ' ';
	static std::string const SIGNAL = "+-";
	static std::string const CHARS = "0123456789+-/* ";
	std::stack<rpn_t>        stack;

	unsigned int i = 0;
	char         previous = 0;
	char         current = 0;
	char         next = 0;
	while (expression[i])
	{
		current = expression[i];
		next = expression[i + 1];
		if (CHARS.find(current) == NPOS)
			throw std::invalid_argument("invalid character");
		else if (i && previous != SEPARATOR && current != SEPARATOR)
			throw std::invalid_argument("separate elements by space");
		else if (std::isdigit(next) && SIGNAL.find(current) != NPOS)
		{
			char buffer[] = {current, next, 0};
			stack.push(std::atoi(buffer));
			i++;
		}
		else if (std::isdigit(current))
			stack.push(current - '0');
		else if (current != SEPARATOR)
			_calc(stack, current);
		previous = expression[i];
		++i;
	}
	if (stack.size() != 1)
		throw std::invalid_argument("invalid expression");
	return stack.top();
}

RPN::rpn_t RPN::process(std::string const &expression) const
{
	return process(expression.c_str());
}

void RPN::_calc(std::stack<rpn_t> &stack, char c) const
{
	if (stack.size() < 2)
		throw std::invalid_argument("invalid expression");
	rpn_t b = stack.top();
	stack.pop();
	rpn_t a = stack.top();
	stack.pop();
	switch (c)
	{
	case '+':
		stack.push(a + b);
		break;
	case '-':
		stack.push(a - b);
		break;
	case '*':
		stack.push(a * b);
		break;
	case '/':
		if (b == 0)
			throw std::invalid_argument("division by zero");
		stack.push(a / b);
		break;
	}
}
