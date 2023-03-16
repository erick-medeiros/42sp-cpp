/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:42:50 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/16 18:53:08 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string  stringVAR("HI THIS IS BRAIN");
	std::string *stringPTR = &stringVAR;
	std::string &stringREF = stringVAR;

	std::cout << "memory address stringVAR: " << &stringVAR << std::endl;
	std::cout << "memory address stringPTR: " << &stringPTR << std::endl;
	std::cout << "memory address stringREF: " << &stringREF << std::endl;
	std::cout << "value of stringVAR: " << stringVAR << std::endl;
	std::cout << "value pointed by stringPTR: " << *stringPTR << std::endl;
	std::cout << "value pointed by stringREF: " << stringREF << std::endl;
}
