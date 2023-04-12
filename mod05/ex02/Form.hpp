/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:00:05 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/12 09:52:48 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

#ifndef DEBUG
#define DEBUG 0
#endif

class Bureaucrat;

class Form
{
  public:
	Form(void);
	Form(const Form &copy);
	Form &operator=(const Form &copy);
	~Form(void);

	Form(const std::string &name, const int &gradeToSign,
	     const int &gradeToExecute);

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

	void beSigned(const Bureaucrat &b);

	const std::string &getName() const;
	const bool        &getIsSigned() const;
	const int         &getGradeToSign() const;
	const int         &getGradeToExecute() const;

  private:
	const std::string _name;
	bool              _isSigned;
	const int         _gradeToSign;
	const int         _gradeToExecute;
};

std::ostream &operator<<(std::ostream &, const Form &);

#endif /* FORM_HPP */
