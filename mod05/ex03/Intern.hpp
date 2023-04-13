/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:23:00 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/13 17:59:51 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>
#include <string>

#ifndef DEBUG
#define DEBUG 0
#endif

class Intern
{
  public:
	Intern(void);
	Intern(const Intern &copy);
	Intern &operator=(const Intern &copy);
	~Intern(void);

	class FormDoesNotExist : public std::exception
	{
		const char *what() const throw();
	};

	AForm *makeForm(const std::string &form, const std::string &target) const;

  private:
	static AForm *_newPresidentialPardonForm(const std::string &target);
	static AForm *_newRobotomyRequestForm(const std::string &target);
	static AForm *_newShrubberyCreationForm(const std::string &target);
};

#endif /* INTERN_HPP */
