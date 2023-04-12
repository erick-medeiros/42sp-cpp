/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:00:05 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/12 12:10:42 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void)
    : _name("undefined"), _isSigned(false), _gradeToSign(10),
      _gradeToExecute(100)
{
	if (DEBUG)
		std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form &copy)
    : _name(copy.getName()), _isSigned(copy.getIsSigned()),
      _gradeToSign(copy.getGradeToSign()),
      _gradeToExecute(copy.getGradeToExecute())
{
	if (DEBUG)
		std::cout << "Form copy constructor called" << std::endl;
	*this = copy;
}

Form &Form::operator=(const Form &)
{
	if (DEBUG)
		std::cout << "Form copy assignment operator called" << std::endl;
	return *this;
}

Form::~Form(void)
{
	if (DEBUG)
		std::cout << "Form destructor called" << std::endl;
}

Form::Form(const std::string &name, const int &gradeToSign,
           const int &gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < Bureaucrat::highestPossibleGrade)
		throw GradeTooHighException();
	if (_gradeToExecute < Bureaucrat::highestPossibleGrade)
		throw GradeTooHighException();
	if (_gradeToSign > Bureaucrat::lowestPossibleGrade)
		throw GradeTooLowException();
	if (_gradeToExecute > Bureaucrat::lowestPossibleGrade)
		throw GradeTooLowException();
	if (DEBUG)
	{
		std::cout << "Form constructor by name, gradeToSign and gradeToExecute "
		             "called"
		          << std::endl;
	}
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "grade too high!";
};

const char *Form::GradeTooLowException::what() const throw()
{
	return "grade too low!";
};

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const std::string &Form::getName() const
{
	return _name;
}

const bool &Form::getIsSigned() const
{
	return _isSigned;
}

const int &Form::getGradeToSign() const
{
	return _gradeToSign;
}

const int &Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << f.getName() << " form";
	if (f.getIsSigned())
		os << ", is signed";
	else
		os << ", not is signed";
	os << ", grade to sign is " << f.getGradeToSign();
	os << " and grade to execute is " << f.getGradeToExecute();
	return os;
}
