/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:36:26 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/06 13:22:41 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <cstdlib>

int main(int argc, char *argv[])
{
	const int total = argc == 2 ? atoi(argv[1]) : 10;

	if (total <= 0 || total >= 1000)
		return 1;

	// AAnimal animal; // error: AAnimal is abstract class

	AAnimal *animals[total];

	int i = 0;
	for (; i < total / 2; i++)
		animals[i] = new Cat();
	for (; i < total; i++)
		animals[i] = new Dog();

	for (i = 0; i < total; i++)
		delete animals[i];

	return 0;
}
