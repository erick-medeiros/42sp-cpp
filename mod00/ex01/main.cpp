/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:32:31 by eandre-f          #+#    #+#             */
/*   Updated: 2023/01/24 14:30:55 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main()
{
	Contact     contact;
	PhoneBook   phone;
	std::string strtmp;

	std::cin >> strtmp;
	contact.setFirstName((char *) strtmp.c_str());
	std::cout << "First Name: " << contact.getFirstName() << std::endl;
	std::cout << phone.get_id() << std::endl;
}
