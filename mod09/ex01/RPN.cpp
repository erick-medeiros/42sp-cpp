/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:25:34 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/25 19:29:15 by eandre-f         ###   ########.fr       */
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
		_stack = copy._stack;
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
	(void) expression;
}
