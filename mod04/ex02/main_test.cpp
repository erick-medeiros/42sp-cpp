/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:50:45 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/06 13:23:10 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "doctest.h"

TEST_CASE("Subtype polymorphism")
{
	{
		freopen("/dev/null", "w", stdout);
		const AAnimal *j = new Dog();
		const AAnimal *i = new Cat();
		freopen("/dev/tty", "w", stdout);
		std::streambuf    *coutbuf = std::cout.rdbuf();
		std::ostringstream oss_animal;
		std::ostringstream oss_dog;
		std::ostringstream oss_cat;

		SUBCASE("Types")
		{
			CHECK_EQ(i->getType(), "Cat");
			CHECK_EQ(j->getType(), "Dog");
		}

		std::cout.rdbuf(oss_cat.rdbuf());
		i->makeSound();
		std::cout.rdbuf(oss_dog.rdbuf());
		j->makeSound();
		std::cout.rdbuf(oss_animal.rdbuf());
		std::cout.rdbuf(coutbuf);

		CHECK_EQ(oss_cat.str(), "Meow!\n");
		CHECK_EQ(oss_dog.str(), "Woof woof!\n");

		freopen("/dev/null", "w", stdout);
		delete i;
		delete j;
	}
	freopen("/dev/tty", "w", stdout);
}