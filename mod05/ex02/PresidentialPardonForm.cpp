/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:17:52 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/12 17:24:47 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("PresidentialPardonForm", PPF_SIGN, PPF_EXEC, "undefined")
{
	if (DEBUG)
		std::cout << "PresidentialPardonForm default constructor called"
		          << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &copy)
    : AForm("PresidentialPardonForm", PPF_SIGN, PPF_EXEC, copy.getTarget())
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

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", PPF_SIGN, PPF_EXEC, target)
{
	if (DEBUG)
		std::cout << "PresidentialPardonForm constructor by target called"
		          << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor)
{
	(void) executor;
}
