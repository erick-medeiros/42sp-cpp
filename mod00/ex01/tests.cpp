#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include "Contact.hpp"
#include "PhoneBook.hpp"
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

	Contact ct_empty("", "", "", "", "");
	CHECK_FALSE(ct_empty.isCompleted());
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

TEST_CASE("check the maximum limit of eight contacts in the phonebook")
{
	PhoneBook phonebook;

	CHECK_EQ(phonebook.getSize(), 0);
	phonebook.add((Contact("1", "1", "1", "1", "1")));
	CHECK_EQ(phonebook.getSize(), 1);
	phonebook.add((Contact("2", "2", "2", "2", "2")));
	CHECK_EQ(phonebook.getSize(), 2);
	phonebook.add((Contact("3", "3", "3", "3", "3")));
	CHECK_EQ(phonebook.getSize(), 3);
	phonebook.add((Contact("4", "4", "4", "4", "4")));
	CHECK_EQ(phonebook.getSize(), 4);
	phonebook.add((Contact("5", "5", "5", "5", "5")));
	CHECK_EQ(phonebook.getSize(), 5);
	phonebook.add((Contact("6", "6", "6", "6", "6")));
	CHECK_EQ(phonebook.getSize(), 6);
	phonebook.add((Contact("7", "7", "7", "7", "7")));
	CHECK_EQ(phonebook.getSize(), 7);
	phonebook.add((Contact("8", "8", "8", "8", "8")));
	CHECK_EQ(phonebook.getSize(), 8);
	phonebook.add((Contact("9", "9", "9", "9", "9")));
	CHECK_EQ(phonebook.getSize(), 8);
}

TEST_CASE("check incomplete contact save")
{
	PhoneBook phonebook;
	Contact   contact;

	CHECK_EQ(phonebook.getSize(), 0);
	//
	phonebook.add(contact);
	CHECK_EQ(phonebook.getSize(), 0);
	//
	contact.setFirstName("first name");
	phonebook.add(contact);
	CHECK_EQ(phonebook.getSize(), 0);
	//
	contact.setLastName("last name");
	phonebook.add(contact);
	CHECK_EQ(phonebook.getSize(), 0);
	//
	contact.setNickname("nickname");
	phonebook.add(contact);
	CHECK_EQ(phonebook.getSize(), 0);
	//
	contact.setPhoneNumber("phone number");
	phonebook.add(contact);
	CHECK_EQ(phonebook.getSize(), 0);
	//
	contact.setDarkestSecret("darknest secret");
	phonebook.add(contact);
	CHECK_EQ(phonebook.getSize(), 1);
}
