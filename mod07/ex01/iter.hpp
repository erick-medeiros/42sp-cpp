/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 09:22:26 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/15 10:07:56 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T> void iter(T *array, const size_t &size, void (*f)(T &))
{
	if (!array)
		return;
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

template <typename T>
void iter(T const *array, const size_t &size, void (*f)(const T &))
{
	if (!array)
		return;
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

template <typename T> void print(T &t)
{
	std::cout << t << std::endl;
}

#endif /* ITER_HPP */
