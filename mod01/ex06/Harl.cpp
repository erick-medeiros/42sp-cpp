/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:27:50 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/18 17:26:16 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level)
{
	std::string levels[LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcPtr[LEVELS])() = {&Harl::debug, &Harl::info,
	                                   &Harl::warning, &Harl::error};
	size_t num = 0;
	while (num < LEVELS && level != levels[num])
		++num;
	switch (num)
	{
	case 0:
		(this->*funcPtr[num++])();
		std::cout << std::endl;
		// fallthrough
	case 1:
		(this->*funcPtr[num++])();
		std::cout << std::endl;
		// fallthrough
	case 2:
		(this->*funcPtr[num++])();
		std::cout << std::endl;
		// fallthrough
	case 3:
		(this->*funcPtr[num++])();
		std::cout << std::endl;
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]"
		          << std::endl;
		break;
	}
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
