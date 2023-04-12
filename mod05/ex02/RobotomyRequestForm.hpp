/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:17:46 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/12 19:15:40 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>

#ifndef DEBUG
#define DEBUG 0
#endif

#define RRF_SIGN 72
#define RRF_EXEC 45

class RobotomyRequestForm : public AForm
{
  public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
	~RobotomyRequestForm(void);

	RobotomyRequestForm(const std::string &target);

	void execute(Bureaucrat const &executor) const;

  private:
};

#endif /* ROBOTOMYREQUESTFORM_HPP */
