/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:27:23 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/26 09:27:23 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	if (DEBUG)
		std::cout << "PmergeMe default constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	if (DEBUG)
		std::cout << "PmergeMe copy constructor called" << std::endl;
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	if (DEBUG)
		std::cout << "PmergeMe copy assignment operator called" << std::endl;
	if (this != &copy)
	{
	}
	return *this;
}

PmergeMe::~PmergeMe(void)
{
	if (DEBUG)
		std::cout << "PmergeMe destructor called" << std::endl;
}
