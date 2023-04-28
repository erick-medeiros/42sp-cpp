/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:25:34 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/28 17:15:01 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <cstdlib>
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
	typedef long long int rpn_t;

	RPN(void);
	RPN(const RPN &copy);
	RPN &operator=(const RPN &copy);
	~RPN(void);

	rpn_t process(char const *expression) const;
	rpn_t process(std::string const &expression) const;

  private:
	void _calc(std::stack<rpn_t> &stack, char c) const;
};

#endif /* RPN_HPP */
