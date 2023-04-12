/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:17:37 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/12 19:15:31 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("ShrubberyCreationForm", SCF_SIGN, SCF_EXEC, "undefined")
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm default constructor called"
		          << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
    : AForm("ShrubberyCreationForm", SCF_SIGN, SCF_EXEC, copy.getTarget())
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm copy constructor called"
		          << std::endl;
	*this = copy;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm copy assignment operator called"
		          << std::endl;
	if (this != &copy)
	{
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", SCF_SIGN, SCF_EXEC, target)
{
	if (DEBUG)
		std::cout << "ShrubberyCreationForm constructor by target called"
		          << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	(void) executor;
}
