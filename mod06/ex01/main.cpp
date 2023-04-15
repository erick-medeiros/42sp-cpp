/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:37:41 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/14 23:50:23 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data     *ptr = new Data("name", 1);
	uintptr_t serialized = Serializer::serialize(ptr);
	Data     *deserialized = Serializer::deserialize(serialized);

	std::cout << ptr << " " << deserialized << std::endl;
	std::cout << ptr->getName() << std::endl;
	std::cout << ptr->getNumber() << std::endl;
	std::cout << deserialized->getName() << std::endl;
	std::cout << deserialized->getNumber() << std::endl;
	ptr->setName("new");
	ptr->setNumber(2);
	std::cout << ptr->getName() << std::endl;
	std::cout << ptr->getNumber() << std::endl;
	std::cout << deserialized->getName() << std::endl;
	std::cout << deserialized->getNumber() << std::endl;
	delete ptr;
}
