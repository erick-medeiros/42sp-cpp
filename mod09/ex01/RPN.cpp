/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:25:34 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/25 20:46:49 by eandre-f         ###   ########.fr       */
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

void RPN::process(char *expression)
{
	static std::string const chars = "0123456789+-/* ";
	std::stack<int>          stack;

	unsigned int i = 0;
	char         previous = 0;
	char         current = 0;
	while (expression[i])
	{
		current = expression[i];
		if (chars.find(current) == std::string::npos)
			throw std::invalid_argument("invalid character");
		if (i && previous != ' ' && current != ' ')
			throw std::invalid_argument("separate elements by space");
		if (std::isdigit(current))
			stack.push(current);
		else if (current != ' ')
			_calc(stack, current);
		++i;
		previous = current;
	}
	if (stack.size() != 1)
		throw std::invalid_argument("invalid expression");
	std::cout << stack.top() << std::endl;
}

void RPN::_calc(std::stack<int> &stack, char c)
{
	if (stack.size() < 2)
		throw std::invalid_argument("invalid expression");
	int a = stack.top();
	stack.pop();
	int b = stack.top();
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
