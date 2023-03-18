/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:27:50 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/18 15:34:30 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level)
{
	std::string levels[LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcPtr[LEVELS])() = {&Harl::debug, &Harl::info,
	                                   &Harl::warning, &Harl::error};
	size_t i = 0;
	while (i < LEVELS)
	{
		if (level == levels[i])
			return ((this->*funcPtr[i])());
		++i;
	}
	std::cerr << "Invalid level: " << level << std::endl;
}

void Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my "
	             "7XL-double-cheese-triple-pickle-specialketchup burger. I "
	             "really do!"
	          << std::endl;
}

void Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. "
	             "You didn't put enough bacon in my burger !If you did, I "
	             "wouldn't be asking for more!"
	          << std::endl;
}

void Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for "
	             "free. I've been coming for years whereas you started working "
	             "here since last month."
	          << std::endl;
}

void Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now"
	          << std::endl;
}
