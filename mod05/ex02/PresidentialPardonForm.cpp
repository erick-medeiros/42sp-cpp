/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:17:52 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/12 15:17:52 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
{
	if (DEBUG)
		std::cout << "PresidentialPardonForm default constructor called"
		          << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &copy)
{
	if (DEBUG)
		std::cout << "PresidentialPardonForm copy constructor called"
		          << std::endl;
	*this = copy;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (DEBUG)
		std::cout << "PresidentialPardonForm copy assignment operator called"
		          << std::endl;
	if (this != &copy)
	{
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	if (DEBUG)
		std::cout << "PresidentialPardonForm destructor called" << std::endl;
}
