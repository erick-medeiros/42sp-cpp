/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:13:35 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/12 12:18:57 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const int Bureaucrat::highestPossibleGrade = 1;
const int Bureaucrat::lowestPossibleGrade = 150;

Bureaucrat::Bureaucrat(void) : _name("undefined"), _grade(lowestPossibleGrade)
{
	if (DEBUG)
		std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name)
{
	if (DEBUG)
		std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (DEBUG)
		std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		_grade = copy._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	if (DEBUG)
		std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name)
    : _name(name), _grade(lowestPossibleGrade)
{
	if (DEBUG)
		std::cout << "Bureaucrat constructor by name called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : _name(name)
{
	_setGrade(grade);
	if (DEBUG)
		std::cout << "Bureaucrat constructor by name and grade called"
		          << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade too high!";
};

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade too low!";
};

const std::string &Bureaucrat::getName() const
{
	return _name;
}

const int &Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::_setGrade(const int &grade)
{
	if (grade < highestPossibleGrade)
		throw GradeTooHighException();
	if (grade > lowestPossibleGrade)
		throw GradeTooLowException();
	_grade = grade;
}

void Bureaucrat::incrementGrade()
{
	_setGrade(_grade - 1);
}

void Bureaucrat::decrementGrade()
{
	_setGrade(_grade + 1);
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << getName() << " couldn't sign " << form.getName()
		          << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
