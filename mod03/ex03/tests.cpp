/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:04:54 by eandre-f          #+#    #+#             */
/*   Updated: 2023/03/30 14:23:11 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "doctest.h"

TEST_CASE("Default")
{
	ClapTrap ct;

	CHECK_EQ(ct.getName(), "mascot");
	CHECK_EQ(ct.getHitPoints(), 10);
	CHECK_EQ(ct.getEnergyPoints(), 10);
	CHECK_EQ(ct.getAttackDamage(), 0);

	ct.attack("cr");

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

// ScavTrap

TEST_CASE("ScavTrap")
{
	SUBCASE("Init")
	{
		ScavTrap st;

		CHECK_EQ(st.getName(), "mascot");
		CHECK_EQ(st.getHitPoints(), 100);
		CHECK_EQ(st.getEnergyPoints(), 50);
		CHECK_EQ(st.getAttackDamage(), 20);

		ScavTrap st2("st2");

		st2.attack("tr");

		CHECK_EQ(st2.getEnergyPoints(), 49);

		st = st2;

		CHECK_EQ(st.getName(), "st2");
		CHECK_EQ(st.getHitPoints(), 100);
		CHECK_EQ(st.getEnergyPoints(), 49);
		CHECK_EQ(st.getAttackDamage(), 20);
	}

	SUBCASE("Attack")
	{
		ScavTrap st;

		CHECK_EQ(st.getName(), "mascot");
		CHECK_EQ(st.getHitPoints(), 100);
		CHECK_EQ(st.getEnergyPoints(), 50);
		CHECK_EQ(st.getAttackDamage(), 20);

		st.attack("tr");

		CHECK_EQ(st.getName(), "mascot");
		CHECK_EQ(st.getHitPoints(), 100);
		CHECK_EQ(st.getEnergyPoints(), 49);
		CHECK_EQ(st.getAttackDamage(), 20);
	}

	SUBCASE("guard Gate")
	{
		ScavTrap st("st");
		st.guardGate();
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

		FragTrap ft2("ft2");

		ft2.attack("tr");
		CHECK_EQ(ft2.getEnergyPoints(), 99);

		ft = ft2;

		CHECK_EQ(ft.getName(), "ft2");
		CHECK_EQ(ft.getHitPoints(), 100);
		CHECK_EQ(ft.getEnergyPoints(), 99);
		CHECK_EQ(ft.getAttackDamage(), 30);
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

	SUBCASE("high fives guys")
	{
		FragTrap ft("ft");

		ft.highFivesGuys();
	}
}

// FragTrap

TEST_CASE("DiamondTrap")
{
	SUBCASE("Init")
	{
		DiamondTrap dt;

		CHECK_EQ(dt.getName(), "mascot");
		CHECK_EQ(dt.getHitPoints(), 100);
		CHECK_EQ(dt.getEnergyPoints(), 50);
		CHECK_EQ(dt.getAttackDamage(), 30);

		DiamondTrap dt2("dt2");

		dt2.attack("tr");

		CHECK_EQ(dt2.getEnergyPoints(), 49);

		dt = dt2;

		CHECK_EQ(dt.getName(), "dt2");
		CHECK_EQ(dt.getHitPoints(), 100);
		CHECK_EQ(dt.getEnergyPoints(), 49);
		CHECK_EQ(dt.getAttackDamage(), 30);
	}

	SUBCASE("Attack")
	{
		DiamondTrap dt;

		CHECK_EQ(dt.getName(), "mascot");
		CHECK_EQ(dt.getHitPoints(), 100);
		CHECK_EQ(dt.getEnergyPoints(), 50);
		CHECK_EQ(dt.getAttackDamage(), 30);

		dt.attack("tr");

		CHECK_EQ(dt.getName(), "mascot");
		CHECK_EQ(dt.getHitPoints(), 100);
		CHECK_EQ(dt.getEnergyPoints(), 49);
		CHECK_EQ(dt.getAttackDamage(), 30);
	}
}
