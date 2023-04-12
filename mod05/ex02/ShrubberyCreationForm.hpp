/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:17:37 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/12 17:24:05 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

#ifndef DEBUG
#define DEBUG 0
#endif

#define SCF_SIGN 145
#define SCF_EXEC 137

class ShrubberyCreationForm : public AForm
{
  public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm(const std::string &target);

	void execute(Bureaucrat const &executor);

  private:
};

#endif /* SHRUBBERYCREATIONFORM_HPP */
