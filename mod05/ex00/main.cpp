/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:08:58 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/10 11:11:28 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	{ // output
		Bureaucrat b("bureaucrat", 10);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
	}
	std::cout << std::endl;
	{ // exception GradeTooHighException
		try
		{
			Bureaucrat b("bureaucrat", 0);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Bureaucrat b("bureaucrat", 1);
			b.incrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat b("bureaucrat", 151);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Bureaucrat b("bureaucrat", 150);
			b.decrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
