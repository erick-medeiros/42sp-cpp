/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:53:24 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/29 18:39:50 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

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
		ScavTrap st("st");

		st.attack("tr");
		st.takeDamage(5);
		st.beRepaired(5);
		st.guardGate();
	}
	std::cout << std::endl;
	{
		FragTrap ft("ft");

		ft.attack("tr");
		ft.takeDamage(5);
		ft.beRepaired(5);
		ft.highFivesGuys();
	}
	std::cout << std::endl;
	{
		//
	}
	return (0);
}
