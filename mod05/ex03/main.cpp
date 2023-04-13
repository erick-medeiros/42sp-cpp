/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:08:58 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/13 18:17:00 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "=== ShrubberyCreationForm ===" << std::endl;
	{
		Intern i;
		AForm *f;
		f = i.makeForm("shrubbery creation", "home");
		std::cout << "name: " << f->getName() << std::endl;
		delete f;
	}
	std::cout << "=== RobotomyRequestForm ===" << std::endl;
	{
		Intern i;
		AForm *f;
		f = i.makeForm("robotomy request", "home");
		std::cout << "name: " << f->getName() << std::endl;
		delete f;
	}
	std::cout << "=== PresidentialPardonForm ===" << std::endl;
	{
		Intern i;
		AForm *f;
		f = i.makeForm("presidential pardon", "home");
		std::cout << "name: " << f->getName() << std::endl;
		delete f;
	}
	std::cout << "=== Error ===" << std::endl;
	{
		try
		{
			Intern i;
			AForm *f = i.makeForm("", "target");
			delete f;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
