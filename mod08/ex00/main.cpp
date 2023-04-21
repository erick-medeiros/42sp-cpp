/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:05:35 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/20 19:49:10 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

// stl - stantard template library
// containers c++98:
// sequence: vector, deque, list
// adaptors: stack, queue, priority_queue
// associative: set, multiset, map, multimap

int main()
{
	{
		std::vector<int>           vector(1, 1);
		std::vector<int>::iterator vectorIterator;

		vectorIterator = ::easyfind(vector, 1);
		std::cout << *vectorIterator << std::endl;
	}
	{
		std::deque<int>           deque(1, 2);
		std::deque<int>::iterator dequeIterator;

		dequeIterator = ::easyfind(deque, 2);
		std::cout << *dequeIterator << std::endl;
	}
	{
		std::list<int>           list(1, 3);
		std::list<int>::iterator listIterator;

		listIterator = ::easyfind(list, 3);
		std::cout << *listIterator << std::endl;
	}
}
