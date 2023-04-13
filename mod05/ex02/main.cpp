/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:08:58 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/13 13:08:40 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "AForm_test.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>

int main()
{
	std::cout << "=== ShrubberyCreationForm ===" << std::endl;
	{
		std::cout << std::endl << "=== sign error ===" << std::endl;
		{
			ShrubberyCreationForm f("home");
			Bureaucrat            b("bob", SCF_SIGN + 1);
			b.signForm(f);
		}
		std::cout << std::endl << "=== executor error ===" << std::endl;
		{
			ShrubberyCreationForm f("home");
			Bureaucrat            b("bob", SCF_EXEC + 1);
			b.signForm(f);
			b.executeForm(f);
		}
		std::cout << std::endl << "=== executor ===" << std::endl;
		{
			ShrubberyCreationForm f("home");
			Bureaucrat            b("bob", 1);
			b.signForm(f);
			b.executeForm(f);
			std::string filename = f.getTarget() + "_shrubbery";
			std::cout << "Open file: " << filename << std::endl;
			std::ifstream file(filename.c_str());
			if (!file.is_open())
			{
				std::cout << "File open failed" << std::endl;
				return 1;
			}
			std::string line;
			while (std::getline(file, line))
				std::cout << line << std::endl;
		}
	}
	std::cout << "=== RobotomyRequestForm ===" << std::endl;
	{
		std::cout << std::endl << "=== sign error ===" << std::endl;
		{
			RobotomyRequestForm f("home");
			Bureaucrat          b("bob", RRF_SIGN + 1);
			b.signForm(f);
		}
		std::cout << std::endl << "=== executor error ===" << std::endl;
		{
			RobotomyRequestForm f("home");
			Bureaucrat          b("bob", RRF_EXEC + 1);
			b.signForm(f);
			b.executeForm(f);
		}
		std::cout << std::endl << "=== executor ===" << std::endl;
		{
			RobotomyRequestForm f("home");
			Bureaucrat          b("bob", 1);
			b.signForm(f);
			b.executeForm(f);
		}
	}
	std::cout << "=== PresidentialPardonForm ===" << std::endl;
	{
		std::cout << std::endl << "=== sign error ===" << std::endl;
		{
			PresidentialPardonForm f("home");
			Bureaucrat             b("bob", PPF_SIGN + 1);
			b.signForm(f);
		}
		std::cout << std::endl << "=== executor error ===" << std::endl;
		{
			PresidentialPardonForm f("home");
			Bureaucrat             b("bob", PPF_EXEC + 1);
			b.signForm(f);
			b.executeForm(f);
		}
		std::cout << std::endl << "=== executor ===" << std::endl;
		{
			PresidentialPardonForm f("home");
			Bureaucrat             b("bob", 1);
			b.signForm(f);
			b.executeForm(f);
		}
	}
	return 0;
}
