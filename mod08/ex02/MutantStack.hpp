/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:48:53 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/21 17:15:14 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T> class MutantStack : public std::stack<T>
{
  public:
	typedef typename std::stack<T>::container_type _ct;
	typedef typename _ct::iterator                 iterator;
	typedef typename _ct::const_iterator           const_iterator;
	typedef typename _ct::reverse_iterator         reverse_iterator;
	typedef typename _ct::const_reverse_iterator   const_reverse_iterator;

	MutantStack(void);
	MutantStack(const MutantStack &copy);
	MutantStack &operator=(const MutantStack &copy);
	~MutantStack(void);

	iterator               begin();
	const_iterator         begin() const;
	iterator               end();
	const_iterator         end() const;
	reverse_iterator       rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator       rend();
	const_reverse_iterator rend() const;

  private:
};

template <typename T> MutantStack<T>::MutantStack(void) : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &copy) : std::stack<T>(copy)
{
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &copy)
{
	std::stack<T>::operator=(copy);
	return *this;
}

template <typename T> MutantStack<T>::~MutantStack(void) {}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	return (this->c.rend());
}

#endif /* MUTANTSTACK_HPP */
