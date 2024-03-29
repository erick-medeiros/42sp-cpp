/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:50:45 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/05 16:17:45 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "doctest.h"

TEST_CASE("Subtype polymorphism")
{
	{
		freopen("/dev/null", "w", stdout);
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		freopen("/dev/tty", "w", stdout);
		std::streambuf    *coutbuf = std::cout.rdbuf();
		std::ostringstream oss_animal;
		std::ostringstream oss_dog;
		std::ostringstream oss_cat;

		SUBCASE("Types")
		{
			CHECK_EQ(i->getType(), "Cat");
			CHECK_EQ(j->getType(), "Dog");
			CHECK_EQ(meta->getType(), "Animal");
		}

		std::cout.rdbuf(oss_cat.rdbuf());
		i->makeSound();
		std::cout.rdbuf(oss_dog.rdbuf());
		j->makeSound();
		std::cout.rdbuf(oss_animal.rdbuf());
		meta->makeSound();
		std::cout.rdbuf(coutbuf);

		CHECK_EQ(oss_cat.str(), "Meow!\n");
		CHECK_EQ(oss_dog.str(), "Woof woof!\n");
		CHECK_EQ(oss_animal.str(), "Roar!\n");

		freopen("/dev/null", "w", stdout);
		delete i;
		delete j;
		delete meta;
	}
	freopen("/dev/tty", "w", stdout);
}