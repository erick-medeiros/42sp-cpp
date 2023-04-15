/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 09:00:09 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/15 09:05:02 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T> void swap(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}

template <typename T> T min(T a, T b)
{
	return (a < b) ? a : b;
}

template <typename T> T max(T a, T b)
{
	return (a > b) ? a : b;
}

#endif /* WHATEVER_HPP */
