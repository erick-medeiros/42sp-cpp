/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:23:00 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/13 18:10:05 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include <cstddef>

Intern::Intern(void)
{
	if (DEBUG)
		std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	if (DEBUG)
		std::cout << "Intern copy constructor called" << std::endl;
	*this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
	if (DEBUG)
		std::cout << "Intern copy assignment operator called" << std::endl;
	if (this != &copy)
	{
	}
	return *this;
}

Intern::~Intern(void)
{
	if (DEBUG)
		std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::_newPresidentialPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
};

AForm *Intern::_newRobotomyRequestForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
};

AForm *Intern::_newShrubberyCreationForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
};

const char *Intern::FormDoesNotExist::what() const throw()
{
	return "form does not exist";
};

AForm *Intern::makeForm(const std::string &form,
                        const std::string &target) const
{
	const int amount = 3;
	struct
	{
		std::string name;
		AForm *(*func)(const std::string &target);
	} forms[amount] = {
	    {"presidential pardon", Intern::_newPresidentialPardonForm},
	    {"robotomy request", Intern::_newRobotomyRequestForm},
	    {"shrubbery creation", Intern::_newShrubberyCreationForm},
	};
	AForm *f = 0;

	for (int i = 0; i < amount; ++i)
	{
		if (forms[i].name == form)
		{
			f = forms[i].func(target);
			break;
		}
	}
	if (f)
		std::cout << "Intern creates " << f->getName() << std::endl;
	else
		throw FormDoesNotExist();
	return (f);
}
