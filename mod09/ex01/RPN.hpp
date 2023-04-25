/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:25:34 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/25 20:47:03 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <iostream>
#include <stack>

#ifndef DEBUG
#define DEBUG 0
#endif

// Reverse Polish Notation

class RPN
{
  public:
	RPN(void);
	RPN(const RPN &copy);
	RPN &operator=(const RPN &copy);
	~RPN(void);

	void process(char *expression);

  private:
	void _calc(std::stack<int> &stack, char c);
};

#endif /* RPN_HPP */
