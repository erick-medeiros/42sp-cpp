/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:13:35 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/10 10:55:11 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const int Bureaucrat::_highestPossibleGrade = 1;
const int Bureaucrat::_lowestPossibleGrade = 150;

Bureaucrat::Bureaucrat(void) : _name("undefined"), _grade(_lowestPossibleGrade)
{
	if (DEBUG)
		std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
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
		(void) copy;
	}
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	if (DEBUG)
		std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name)
    : _name(name), _grade(_lowestPossibleGrade)
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

class Bureaucrat::GradeTooHighException : public std::exception
{
  public:
	const char *what() const throw()
	{
		return "Grade too high!";
	};
};

class Bureaucrat::GradeTooLowException : public std::exception
{
  public:
	const char *what() const throw()
	{
		return "Grade too low!";
	};
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
	if (grade < _highestPossibleGrade)
		throw GradeTooHighException();
	if (grade > _lowestPossibleGrade)
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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
	   << ".";
	return os;
}
