/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:17:46 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/13 13:10:30 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("RobotomyRequestForm", RRF_SIGN, RRF_EXEC, "undefined")
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm default constructor called"
		          << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
    : AForm("RobotomyRequestForm", RRF_SIGN, RRF_EXEC, copy.getTarget())
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = copy;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm copy assignment operator called"
		          << std::endl;
	if (this != &copy)
	{
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", RRF_SIGN, RRF_EXEC, target)
{
	if (DEBUG)
		std::cout << "RobotomyRequestForm constructor by target called"
		          << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);

	std::cout << "Buzzzzzzzzzzzzzzzzzzzz...." << std::endl;
	std::cout << "Grrrrrrrrrrrrrrrrrrrrrrrrrrr..." << std::endl;
	std::cout << "VRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR..." << std::endl;

	srand(time(NULL)); // seed
	const short random = rand() % 101;

	if (random <= 50)
	{
		std::cout << getTarget()
		          << " has been robotomized successfully 50\% of the time"
		          << std::endl;
	}
	else
	{
		std::cout << "The robotomy failed " << getTarget() << std::endl;
	}
}
