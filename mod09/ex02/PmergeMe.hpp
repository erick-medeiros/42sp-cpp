/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:27:23 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/27 18:31:55 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <bits/types/clock_t.h>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <sys/types.h>
#include <vector>

#ifndef DEBUG
#define DEBUG 0
#endif

#define THRESHOLD 10

class PmergeMe
{
  public:
	typedef unsigned long long  unum_t;
	typedef std::list<unum_t>   list_t;
	typedef std::vector<unum_t> vector_t;

	typedef struct
	{
		char const **unsorted;
		list_t       list;
		vector_t     vector;
		double       timeList;
		double       timeVector;
	} sort_t;

	PmergeMe(void);
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &copy);
	~PmergeMe(void);

	static bool checkArgs(char const **argv);

	void sort(const char **numbers);
	void display(sort_t const &data) const;

  private:
	double _clockToMicroSeconds(clock_t &start, clock_t &end) const;
	template <typename T> void _fill(T &container, const char **numbers) const;
	template <typename T> bool _is_sorted(T &container) const;
	void _mergeInsertSort(vector_t &container, unum_t min, unum_t max);
	void _insertSort(vector_t &container, unum_t start, unum_t end);
	void _mergeSort(vector_t &container, unum_t min, unum_t max, unum_t mid);
	void _mergeInsertSort(list_t &container);
	void _divideAndConquer(list_t &container, std::list<list_t> &lists);
	void _insertSort(list_t &container);
	void _mergeSort(list_t &list1, list_t &list2, list_t &merged);
};

#endif /* PMERGEME_HPP */
