/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:08:58 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/12 17:38:23 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "AForm_test.hpp"
#include "Bureaucrat.hpp"

int main()
{
	std::cout << "=== output ===" << std::endl;
	{
		AForm_test f("Sign", 10, 15);
		Bureaucrat b("Bob", 5);
		std::cout << f << std::endl;
		f.beSigned(b);
		std::cout << b << std::endl;
		std::cout << f << std::endl;
	}
	std::cout << "=== exception GradeTooHighException ===" << std::endl;
	{
		try
		{
			AForm_test f("Sign", Bureaucrat::highestPossibleGrade - 1, 10);
		}
		catch (std::exception &e)
		{
			std::cout << "form: error: " << e.what() << std::endl;
		}
	}
	std::cout << "=== exception GradeTooLowException ===" << std::endl;
	{
		try
		{
			AForm_test f("Sign", 1, Bureaucrat::lowestPossibleGrade + 1);
		}
		catch (std::exception &e)
		{
			std::cout << "form: error: " << e.what() << std::endl;
		}
	}
	std::cout << "=== signForm ===" << std::endl;
	{
		AForm_test f1("Sign", 10, 20);
		AForm_test f2(f1);
		AForm_test f3(f1);
		Bureaucrat b1("linus", 5);
		Bureaucrat b2("sam", 15);
		Bureaucrat b3("bob", 25);
		b1.signForm(f1);
		b2.signForm(f2);
		b3.signForm(f3);
	}
	return 0;
}
