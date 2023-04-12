/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm_test.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:17:13 by eandre-f          #+#    #+#             */
/*   Updated: 2023/04/12 18:21:10 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class AForm_test : public AForm
{
  public:
	AForm_test() : AForm() {}
	AForm_test(const std::string &name, const int &gradeToSign,
	           const int &gradeToExecute)
	    : AForm(name, gradeToSign, gradeToExecute, "target")
	{
	}
	void execute(Bureaucrat const &b)
	{
		AForm::execute(b);
	}
};
