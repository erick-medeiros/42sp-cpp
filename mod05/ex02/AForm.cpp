/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:00:05 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/12 17:43:13 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void)
    : _target("undefined"), _name("undefined"), _isSigned(false),
      _gradeToSign(10), _gradeToExecute(100)
{
	if (DEBUG)
		std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm &copy)
    : _target(copy.getTarget()), _name(copy.getName()),
      _isSigned(copy.getIsSigned()), _gradeToSign(copy.getGradeToSign()),
      _gradeToExecute(copy.getGradeToExecute())
{
	if (DEBUG)
		std::cout << "AForm copy constructor called" << std::endl;
	*this = copy;
}

AForm &AForm::operator=(const AForm &)
{
	if (DEBUG)
		std::cout << "AForm copy assignment operator called" << std::endl;
	return *this;
}

AForm::~AForm(void)
{
	if (DEBUG)
		std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(const std::string &name, const int &gradeToSign,
             const int &gradeToExecute, const std::string &target)
    : _target(target), _name(name), _isSigned(false), _gradeToSign(gradeToSign),
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
		std::cout << "AForm constructor by name, gradeToSign and "
		             "gradeToExecute called"
		          << std::endl;
	}
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "grade too high!";
};

const char *AForm::GradeTooLowException::what() const throw()
{
	return "grade too low!";
};

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const std::string &AForm::getName() const
{
	return _name;
}

const bool &AForm::getIsSigned() const
{
	return _isSigned;
}

const int &AForm::getGradeToSign() const
{
	return _gradeToSign;
}

const int &AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
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

const std::string &AForm::getTarget() const
{
	return _target;
}
