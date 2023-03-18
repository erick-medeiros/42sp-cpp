/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:27:50 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/18 15:13:49 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level)
{
	void (Harl::*functionPointer)();

	if (level == "DEBUG")
		functionPointer = &Harl::debug;
	else if (level == "INFO")
		functionPointer = &Harl::info;
	else if (level == "WARNING")
		functionPointer = &Harl::warning;
	else if (level == "ERROR")
		functionPointer = &Harl::error;
	else
	{
		std::cout << "Invalid level: " << level << std::endl;
		return;
	}
	(this->*functionPointer)();
}

void Harl::debug()
{
	std::cout << "DEBUG: I love having extra bacon for my "
	             "7XL-double-cheese-triple-pickle-specialketchup burger. I "
	             "really do!"
	          << std::endl;
}

void Harl::info()
{
	std::cout << "INFO: I cannot believe adding extra bacon costs more money. "
	             "You didn't put enough bacon in my burger !If you did, I "
	             "wouldn't be asking for more!"
	          << std::endl;
}

void Harl::warning()
{
	std::cout << "WARNING: I think I deserve to have some extra bacon for "
	             "free. I've been coming for years whereas you started working "
	             "here since last month."
	          << std::endl;
}

void Harl::error()
{
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager "
	             "now"
	          << std::endl;
}
