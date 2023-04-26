/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:27:23 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/26 18:09:59 by eandre-f         ###   ########.fr       */
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

	void sort(const char **numbers) const;
	void display(sort_t const &data) const;

  private:
	double _clockToMicroSeconds(clock_t &start, clock_t &end) const;
	void   _fill(list_t &container, const char **numbers) const;
	void   _fill(vector_t &container, const char **numbers) const;
	void   _mergeInsert(list_t &container);
	void   _mergeInsert(vector_t &container);
};

#endif /* PMERGEME_HPP */
