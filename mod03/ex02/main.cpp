/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:53:24 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/29 11:22:46 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	{
		ClapTrap ct("ct");

		ct.attack("tr");
		ct.takeDamage(5);
		ct.beRepaired(5);
	}
	std::cout << std::endl;
	{
		FragTrap ft("ft");

		ft.attack("tr");
		ft.takeDamage(5);
		ft.beRepaired(5);
		ft.highFivesGuys();
	}
	return (0);
}
