/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:17:37 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/12 20:18:54 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

#ifndef DEBUG
#define DEBUG 0
#endif

#define SCF_SIGN 145
#define SCF_EXEC 137

#define ASCII_TREE \
	"\n\
             # #### #### \n\
           ### \\/#|### |/#### \n\
          ##\\/\\/# \\||/##/_/##/_# \n\
        ###  \\/###|/ \\/ # ### \n\
      ##_\\_\\/#\\_\\# | #/###_/_#### \n\
     ## #### # \\ #| /  #### ##/## \n\
      __#_--###`  |{,###---###-~ \n\
                \\ }{ \n\
                 }}{ \n\
                 }}{ \n\
            ejm  {{} \n\
           , -=-~{ .-^- _ \n\
                 `} \n\
                  { \n\n"

class ShrubberyCreationForm : public AForm
{
  public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm(const std::string &target);

	void execute(Bureaucrat const &executor) const;

  private:
};

#endif /* SHRUBBERYCREATIONFORM_HPP */
