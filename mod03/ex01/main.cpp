/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:53:24 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/28 18:52:23 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	{
		ClapTrap ct("ct");

		ct.attack("tr");
		ct.takeDamage(5);
		ct.beRepaired(5);
	}
	{
		ScavTrap st("st");

		st.attack("tr");
		st.takeDamage(5);
		st.beRepaired(5);
	}
	return (0);
}
