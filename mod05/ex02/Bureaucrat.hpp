/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:13:35 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/12 14:40:17 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <string>

#ifndef DEBUG
#define DEBUG 0
#endif

class AForm;

class Bureaucrat
{
  public:
	Bureaucrat(void);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);
	~Bureaucrat(void);

	Bureaucrat(const std::string &name);
	Bureaucrat(const std::string &name, const int &grade);

	class GradeTooHighException : public std::exception
	{
	  public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	  public:
		const char *what() const throw();
	};

	const std::string &getName() const;
	const int         &getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void signForm(AForm &AForm);

	static const int highestPossibleGrade;
	static const int lowestPossibleGrade;

  private:
	const std::string _name;
	int               _grade;

	void _setGrade(const int &_grade);
};

std::ostream &operator<<(std::ostream &, const Bureaucrat &);

#endif /* BUREAUCRAT_HPP */
