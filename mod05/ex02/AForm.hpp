/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:00:05 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/12 17:21:54 by eandre-f         ###   ########.fr       */
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

class AForm
{
  public:
	AForm(void);
	AForm(const AForm &copy);
	AForm &operator=(const AForm &copy);
	~AForm(void);

	AForm(const std::string &name, const int &gradeToSign,
	      const int &gradeToExecute, const std::string &target);

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

	const std::string &getTarget() const;

	virtual void execute(Bureaucrat const &executor) = 0;

  protected:
	const std::string _target;

  private:
	const std::string _name;
	bool              _isSigned;
	const int         _gradeToSign;
	const int         _gradeToExecute;
};

std::ostream &operator<<(std::ostream &, const AForm &);

#endif /* AFORM_HPP */
