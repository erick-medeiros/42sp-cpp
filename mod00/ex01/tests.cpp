#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include "Contact.hpp"
#include "doctest.h"

TEST_CASE("saving information in class Contact")
{
	Contact ct;

	ct.setFirstName("John");
	ct.setLastName("Carmack");
	ct.setNickname("Genius");
	ct.setPhoneNumber("42");
	ct.setDarkestSecret("Wolfenstein 3D");
	CHECK_EQ(ct.getFirstName(), "John");
	CHECK_EQ(ct.getLastName(), "Carmack");
	CHECK_EQ(ct.getNickname(), "Genius");
	CHECK_EQ(ct.getPhoneNumber(), "42");
	CHECK_EQ(ct.getDarkestSecret(), "Wolfenstein 3D");

	Contact ct_full("John", "Carmack", "Genius", "42", "Wolfenstein 3D");

	CHECK_EQ(ct_full.getFirstName(), "John");
	CHECK_EQ(ct_full.getLastName(), "Carmack");
	CHECK_EQ(ct_full.getNickname(), "Genius");
	CHECK_EQ(ct_full.getPhoneNumber(), "42");
	CHECK_EQ(ct_full.getDarkestSecret(), "Wolfenstein 3D");
}

TEST_CASE("checking if all of the Contact class have been filled in")
{
	Contact ct;

	ct.setFirstName("John");
	CHECK_FALSE(ct.isCompleted());
	ct.setLastName("Carmack");
	CHECK_FALSE(ct.isCompleted());
	ct.setNickname("Genius");
	CHECK_FALSE(ct.isCompleted());
	ct.setPhoneNumber("42");
	CHECK_FALSE(ct.isCompleted());
	ct.setDarkestSecret("Wolfenstein 3D");
	CHECK(ct.isCompleted());
}