/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:00:56 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/15 17:34:16 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

// #include <typeinfo> typeid(*).name()

Base *generate(void)
{
	unsigned seed = time(0);
	srand(seed);
	int random = rand() % 3 + 1;

	switch (random)
	{
	case 1:
		return new A;
	case 2:
		return new B;
	case 3:
		return new C;
	}

	return 0;
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Pointer to instance of class A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Pointer to instance of class B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Pointer to instance of class C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		if (&a == &p)
		{
			std::cout << "Pointer to instance of class A" << std::endl;
			return;
		}
	}
	catch (std::exception &)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		if (&b == &p)
		{
			std::cout << "Pointer to instance of class B" << std::endl;
			return;
		}
	}
	catch (std::exception &)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		if (&c == &p)
		{
			std::cout << "Pointer to instance of class C" << std::endl;
			return;
		}
	}
	catch (std::exception &)
	{
	}
}

int main()
{
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}