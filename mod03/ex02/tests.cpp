/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:04:54 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/29 14:55:16 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "doctest.h"

TEST_CASE("Default")
{
	ClapTrap ct;

	CHECK_EQ(ct.getName(), "mascot");
	CHECK_EQ(ct.getHitPoints(), 10);
	CHECK_EQ(ct.getEnergyPoints(), 10);
	CHECK_EQ(ct.getAttackDamage(), 0);

	ct.setEnergyPoints(15);
	CHECK_EQ(ct.getEnergyPoints(), 15);

	ct = ClapTrap("namedd");

	CHECK_EQ(ct.getName(), "namedd");
	CHECK_EQ(ct.getHitPoints(), 10);
	CHECK_EQ(ct.getEnergyPoints(), 10);
	CHECK_EQ(ct.getAttackDamage(), 0);
}

TEST_CASE("ClapTrap attacks")
{
	SUBCASE("Decreasing energy")
	{
		ClapTrap ct;
		CHECK_EQ(ct.getHitPoints(), 10);
		CHECK_EQ(ct.getEnergyPoints(), 10);
		CHECK_EQ(ct.getAttackDamage(), 0);
		ct.attack("tr");
		CHECK_EQ(ct.getHitPoints(), 10);
		CHECK_EQ(ct.getEnergyPoints(), 9);
		CHECK_EQ(ct.getAttackDamage(), 0);
		ct.attack("tr");
		CHECK_EQ(ct.getEnergyPoints(), 8);
		ct.attack("tr");
		CHECK_EQ(ct.getEnergyPoints(), 7);
		ct.attack("tr");
		CHECK_EQ(ct.getEnergyPoints(), 6);
		ct.attack("tr");
		CHECK_EQ(ct.getEnergyPoints(), 5);
		ct.attack("tr");
		CHECK_EQ(ct.getEnergyPoints(), 4);
		ct.attack("tr");
		CHECK_EQ(ct.getEnergyPoints(), 3);
		ct.attack("tr");
		CHECK_EQ(ct.getEnergyPoints(), 2);
		ct.attack("tr");
		CHECK_EQ(ct.getEnergyPoints(), 1);
		ct.attack("tr");
		CHECK_EQ(ct.getEnergyPoints(), 0);
		ct.attack("tr");
		CHECK_EQ(ct.getEnergyPoints(), 0);
	}
}

TEST_CASE("ClapTrap take damage")
{
	SUBCASE("subzero")
	{
		ClapTrap ct;
		CHECK_EQ(ct.getHitPoints(), 10);
		ct.takeDamage(5);
		CHECK_EQ(ct.getHitPoints(), 5);
		ct.takeDamage(10);
		CHECK_EQ(ct.getHitPoints(), 0);
	}
}

TEST_CASE("ClapTrap be Repaired")
{
	SUBCASE("energy")
	{
		ClapTrap ct;
		CHECK_EQ(ct.getHitPoints(), 10);
		CHECK_EQ(ct.getEnergyPoints(), 10);
		ct.beRepaired(5);
		CHECK_EQ(ct.getHitPoints(), 15);
		CHECK_EQ(ct.getEnergyPoints(), 9);
		ct.beRepaired(5);
		CHECK_EQ(ct.getHitPoints(), 20);
		CHECK_EQ(ct.getEnergyPoints(), 8);
		ct.beRepaired(5);
		CHECK_EQ(ct.getHitPoints(), 25);
		CHECK_EQ(ct.getEnergyPoints(), 7);
		ct.beRepaired(5);
		CHECK_EQ(ct.getHitPoints(), 30);
		CHECK_EQ(ct.getEnergyPoints(), 6);
		ct.beRepaired(5);
		CHECK_EQ(ct.getHitPoints(), 35);
		CHECK_EQ(ct.getEnergyPoints(), 5);
		ct.beRepaired(5);
		CHECK_EQ(ct.getHitPoints(), 40);
		CHECK_EQ(ct.getEnergyPoints(), 4);
		ct.beRepaired(5);
		CHECK_EQ(ct.getHitPoints(), 45);
		CHECK_EQ(ct.getEnergyPoints(), 3);
		ct.beRepaired(5);
		CHECK_EQ(ct.getHitPoints(), 50);
		CHECK_EQ(ct.getEnergyPoints(), 2);
		ct.beRepaired(5);
		CHECK_EQ(ct.getHitPoints(), 55);
		CHECK_EQ(ct.getEnergyPoints(), 1);
		ct.beRepaired(5);
		CHECK_EQ(ct.getHitPoints(), 60);
		CHECK_EQ(ct.getEnergyPoints(), 0);
		ct.beRepaired(5);
		CHECK_EQ(ct.getHitPoints(), 60);
		CHECK_EQ(ct.getEnergyPoints(), 0);
	}
}

// FragTrap

TEST_CASE("FragTrap")
{
	SUBCASE("Init")
	{
		FragTrap ft;

		CHECK_EQ(ft.getName(), "mascot");
		CHECK_EQ(ft.getHitPoints(), 100);
		CHECK_EQ(ft.getEnergyPoints(), 100);
		CHECK_EQ(ft.getAttackDamage(), 30);

		FragTrap ft2;

		ft2.setName("st2");
		ft2.setHitPoints(5);
		ft2.setEnergyPoints(15);
		ft2.setAttackDamage(25);

		CHECK_EQ(ft2.getName(), "st2");
		CHECK_EQ(ft2.getHitPoints(), 5);
		CHECK_EQ(ft2.getEnergyPoints(), 15);
		CHECK_EQ(ft2.getAttackDamage(), 25);

		ft = ft2;

		CHECK_EQ(ft.getName(), "st2");
		CHECK_EQ(ft.getHitPoints(), 5);
		CHECK_EQ(ft.getEnergyPoints(), 15);
		CHECK_EQ(ft.getAttackDamage(), 25);
	}

	SUBCASE("Attack")
	{
		FragTrap ft;

		CHECK_EQ(ft.getName(), "mascot");
		CHECK_EQ(ft.getHitPoints(), 100);
		CHECK_EQ(ft.getEnergyPoints(), 100);
		CHECK_EQ(ft.getAttackDamage(), 30);

		ft.attack("tr");

		CHECK_EQ(ft.getName(), "mascot");
		CHECK_EQ(ft.getHitPoints(), 100);
		CHECK_EQ(ft.getEnergyPoints(), 99);
		CHECK_EQ(ft.getAttackDamage(), 30);
	}
}
