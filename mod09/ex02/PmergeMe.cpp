/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:27:23 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/28 11:03:58 by eandre-f         ###   ########.fr       */
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
	if (!_isSorted(data.vector))
	{
		std::cout << "Error: vector unsorted" << std::endl;
		return;
	}
	if (!_isSorted(data.list))
	{
		std::cout << "Error: list unsorted" << std::endl;
		return;
	}

	if (!_isEqualContainer(data.list, data.vector))
	{
		std::cout << "Error: vector and list are different" << std::endl;
		return;
	}

	size_t elem = 4;
	std::cout << "Before: ";
	_printContainer(data.unsorted, elem);
	std::cout << "After:  ";
	_printContainer(data.vector, elem);
	std::cout << "Time to process a range of " << data.list.size()
	          << " elements with std::list :   " << data.timeList << " µs"
	          << std::endl;
	std::cout << "Time to process a range of " << data.vector.size()
	          << " elements with std::vector : " << data.timeVector << " µs"
	          << std::endl;
}

void PmergeMe::sort(char const **numbers)
{
	if (!numbers)
		return;
	sort_t  data;
	clock_t start, end;
	data.unsorted = numbers;
	start = clock();
	_fill(data.list, numbers);
	_mergeInsertSort(data.list);
	end = clock();
	data.timeList = _clockToMicroSeconds(start, end);
	start = clock();
	_fill(data.vector, numbers);
	_mergeInsertSort(data.vector, 0, data.vector.size());
	end = clock();
	data.timeVector = _clockToMicroSeconds(start, end);
	display(data);
}

template <typename T>
void PmergeMe::_fill(T &container, const char **numbers) const
{
	if (!numbers)
		return;
	for (int i = 0; numbers[i]; i++)
		container.push_back(std::atoll(numbers[i]));
}

template <typename T> bool PmergeMe::_isSorted(T &container) const
{
	typename T::const_iterator it, prev;
	prev = container.begin();
	it = container.begin();
	for (++it; it != container.end(); it++)
	{
		if (*it < *prev)
			return false;
	}
	return true;
}

template <typename T, typename J>
bool PmergeMe::_isEqualContainer(T &container1, J &container2) const
{
	typename T::const_iterator it1 = container1.begin();
	typename J::const_iterator it2 = container2.begin();
	while (it1 != container1.end() && it2 != container2.end())
		if (*it1++ != *it2++)
			return false;
	if (it1 != container1.end() && it2 != container2.end())
		return false;
	return true;
}

template <typename T> void PmergeMe::_printContainer(T &container) const
{
	typename T::const_iterator it;
	for (it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template <typename T>
void PmergeMe::_printContainer(T &container, size_t size) const
{
	typename T::const_iterator it;
	size_t                     i = 0;
	for (it = container.begin(); it != container.end(); it++)
	{
		if (i++ >= size)
			break;
		std::cout << *it << " ";
	}
	std::cout << "[...]" << std::endl;
}

void PmergeMe::_printContainer(const char **numbers, size_t size) const
{
	for (size_t i = 0; numbers[i] && i < size; i++)
		std::cout << numbers[i] << " ";
	std::cout << "[...]" << std::endl;
}

// vector

void PmergeMe::_mergeInsertSort(vector_t &container, unum_t min, unum_t max)
{
	if ((max - min) <= THRESHOLD)
		_insertSort(container, min, max);
	else
	{
		unum_t mid = (max + min) >> 1; // n/2

		_mergeInsertSort(container, min, mid);
		_mergeInsertSort(container, mid, max);

		_mergeSort(container, min, max, mid);
	}
}

void PmergeMe::_insertSort(vector_t &container, unum_t start, unum_t end)
{
	unum_t i = 0, j = 0, prev = 0;

	for (i = start; i < end; i++)
	{
		unum_t curr = container[i];
		j = i;
		while (j > start)
		{
			prev = container[j - 1];
			if (curr < prev)
				container[j--] = prev;
			else
				break;
		}
		container[j] = curr;
	}
}

void PmergeMe::_mergeSort(vector_t &container, unum_t min, unum_t max,
                          unum_t mid)
{
	unum_t it1 = min;
	unum_t it2 = mid;
	unum_t index;

	vector_t temp(max - min, 0);

	for (index = min; index < max; index++)
	{
		if (it1 < mid && (it2 >= max || container[it1] <= container[it2]))
			temp[index - min] = container[it1++];
		else
			temp[index - min] = container[it2++];
	}

	index = 0;
	while ((index + min) < max)
	{
		container[index + min] = temp[index];
		index++;
	}
}

// list

void PmergeMe::_mergeInsertSort(list_t &container)
{
	std::list<list_t> lists;
	_divideAndConquer(container, lists);
	while (lists.size() > 1)
	{
		list_t merged, left, right;

		list_t &list1 = lists.front();
		left.splice(left.begin(), list1, list1.begin(), list1.end());
		lists.pop_front();
		list_t &list2 = lists.front();
		right.splice(right.begin(), list2, list2.begin(), list2.end());
		lists.pop_front();

		_mergeSort(left, right, merged);
		lists.push_back(merged);
	}
	if (!lists.empty())
		container = lists.front();
}

void PmergeMe::_divideAndConquer(list_t &container, std::list<list_t> &lists)
{
	if (container.size() <= THRESHOLD)
	{
		_insertSort(container);
		lists.push_back(container);
	}
	else
	{
		list_t::iterator mid = container.begin();
		std::advance(mid, container.size() / 2);

		list_t list1;
		list_t list2;
		list1.splice(list1.begin(), container, container.begin(), mid);
		list2.splice(list2.begin(), container, mid, container.end());

		_divideAndConquer(list1, lists);
		_divideAndConquer(list2, lists);
	}
}

void PmergeMe::_insertSort(list_t &list)
{
	list_t::iterator i, j;

	for (i = list.begin(); i != list.end(); i++)
	{
		unum_t curr = *i;
		j = i;
		while (j != list.begin())
		{
			list_t::iterator prev = j;
			--prev;
			if (curr < *prev)
				*j-- = *prev;
			else
				break;
		}
		*j = curr;
	}
}

void PmergeMe::_mergeSort(list_t &list1, list_t &list2, list_t &merged)
{
	list_t::iterator it1 = list1.begin();
	list_t::iterator it2 = list2.begin();

	while (it1 != list1.end() && it2 != list2.end())
	{
		if (*it1 <= *it2)
			merged.splice(merged.end(), list1, it1++);
		else
			merged.splice(merged.end(), list2, it2++);
	}
	merged.splice(merged.end(), list1);
	merged.splice(merged.end(), list2);
}
