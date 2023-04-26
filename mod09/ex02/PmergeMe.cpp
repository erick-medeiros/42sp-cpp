/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:27:23 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/26 18:09:52 by eandre-f         ###   ########.fr       */
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

bool PmergeMe::checkArgs(char const **argv)
{
	if (!argv)
		return false;
	for (int i = 1; argv[i]; i++)
	{
		int j = 0;
		if (std::strlen(argv[i]) > 1 && argv[i][0] == '+')
			j++;
		for (; argv[i][j]; j++)
			if (!std::isdigit(argv[i][j]))
				return false;
	}
	return true;
}

double PmergeMe::_clockToMicroSeconds(clock_t &start, clock_t &end) const
{
	static const int SEC_TO_MICRO = 1e6; // 10^6

	double diff = (end - start);
	return (diff / CLOCKS_PER_SEC) * SEC_TO_MICRO;
}

void PmergeMe::display(sort_t const &data) const
{
	std::cout << "Before: ";
	for (int i = 0; data.unsorted[i]; i++)
		std::cout << data.unsorted[i] << " ";
	std::cout << std::endl;
	std::cout << "After:  ";
	for (std::list<unum_t>::const_iterator it = data.list.begin();
	     it != data.list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << data.list.size()
	          << " elements with std::list : " << data.timeList << " µs"
	          << std::endl;
	std::cout << "Time to process a range of " << data.vector.size()
	          << " elements with std::list : " << data.timeVector << " µs"
	          << std::endl;
}

void PmergeMe::sort(char const **numbers) const
{
	if (!numbers)
		return;
	sort_t  data;
	clock_t start, end;
	data.unsorted = numbers;
	start = clock();
	_fill(data.list, numbers);
	end = clock();
	data.timeList = _clockToMicroSeconds(start, end);
	start = clock();
	_fill(data.vector, numbers);
	end = clock();
	data.timeVector = _clockToMicroSeconds(start, end);
	display(data);
}

void PmergeMe::_fill(list_t &container, const char **numbers) const
{
	if (numbers)
		for (int i = 0; numbers[i]; i++)
			container.push_back(std::atoll(numbers[i]));
}

void PmergeMe::_fill(vector_t &container, const char **numbers) const
{
	if (numbers)
		for (int i = 0; numbers[i]; i++)
			container.push_back(std::atoll(numbers[i]));
}

void PmergeMe::_mergeInsert(list_t &container)
{
	(void) container;
}

void PmergeMe::_mergeInsert(vector_t &container)
{
	(void) container;
}
