/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:17:52 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/12 19:15:52 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>

#ifndef DEBUG
#define DEBUG 0
#endif

#define PPF_SIGN 25
#define PPF_EXEC 5

class PresidentialPardonForm : public AForm
{
  public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
	~PresidentialPardonForm(void);

	PresidentialPardonForm(const std::string &target);

	void execute(Bureaucrat const &executor) const;

  private:
};

#endif /* PRESIDENTIALPARDONFORM_HPP */
