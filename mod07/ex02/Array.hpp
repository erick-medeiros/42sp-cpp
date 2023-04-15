/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 10:11:27 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/15 12:09:50 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

#ifndef DEBUG
#define DEBUG 0
#endif

template <typename T> class Array
{
  public:
	Array(void);
	Array(unsigned int n);
	Array(const Array &copy);
	Array &operator=(const Array &copy);
	~Array();

	T	   &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;

	const unsigned int &size(void) const;

  private:
	T	       *_array;
	unsigned int _size;
};

template <typename T> Array<T>::Array(void) : _array(0), _size(0)
{
	if (DEBUG)
		std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
	if (DEBUG)
		std::cout << "Array default constructor called" << std::endl;
	for (unsigned int i = 0; i < _size; ++i)
		_array[i] = 0;
}

template <typename T> Array<T>::Array(const Array &copy) : _array(0), _size(0)
{
	if (DEBUG)
		std::cout << "Array copy constructor called" << std::endl;
	*this = copy;
}

template <typename T> Array<T> &Array<T>::operator=(const Array &copy)
{
	if (DEBUG)
		std::cout << "Array copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		delete[] _array;
		_size = copy._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_array[i] = copy._array[i];
	}
	return *this;
}

template <typename T> Array<T>::~Array(void)
{
	if (DEBUG)
		std::cout << "Array destructor called" << std::endl;
	delete[] _array;
}

template <typename T> T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Index is out of bound");
	return _array[index];
};

template <typename T> const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("Index is out of bound");
	return _array[index];
};

template <typename T> const unsigned int &Array<T>::size(void) const
{
	return _size;
}

#endif /* ARRAY_HPP */
