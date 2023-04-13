#!/bin/sh

# class: Orthodox Canonical Form

#info
LOGIN="eandre-f"
EMAIL="eandre-f@student.42sp.org.br"

if [ $# -eq 0 ]; then
	echo "usage: script [CLASS]"
	exit 1
fi

ARG1=$1

#config
CLASS=$(echo "$ARG1" | awk '{print toupper(substr($0,1,1)) substr($0,2)}')
CLASS_UPPER=$(echo "$CLASS" | tr '[:lower:]' '[:upper:]')
FILE_CPP=$CLASS.cpp
FILE_HPP=$CLASS.hpp
FILE_TEST="$CLASS"_test.cpp
DATE=$(date +"%Y/%m/%d %H:%M:%S")

# fn_header <file>
fn_header ()
{
	_FILL="                                             "
	_FILE=$(printf "%.45s" "$1$_FILL")
	_BY=$(printf "%.45s" "By: $LOGIN <$EMAIL>$_FILL")
	_CREATED=$(printf "Created: %s by %.13s" "$DATE" "$LOGIN$_FILL")
	_UPDATED=$(printf "Updated: %s by %.13s" "$DATE" "$LOGIN$_FILL")

	HEADER="/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   $_FILE      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   $_BY  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   $_CREATED     #+#    #+#             */
/*   $_UPDATED    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */"

	echo "$HEADER"
}

fn_header $FILE_HPP > $FILE_HPP
fn_header $FILE_CPP > $FILE_CPP
fn_header $FILE_TEST > $FILE_TEST

echo "
#ifndef "$CLASS_UPPER"_HPP
#define "$CLASS_UPPER"_HPP

#include <iostream>

#ifndef DEBUG
#define DEBUG 0
#endif

class $CLASS
{
  public:
	$CLASS(void);
	$CLASS(const $CLASS &copy);
	$CLASS &operator=(const $CLASS &copy);
	~$CLASS(void);

  private:
};

#endif /* "$CLASS_UPPER"_HPP */" >> $FILE_HPP

echo "
#include "'"'$FILE_HPP'"'"

"$CLASS"::"$CLASS"(void)
{
	if (DEBUG)
		std::cout << \"$CLASS default constructor called\" << std::endl;
}

$CLASS::$CLASS(const $CLASS &copy)
{
	if (DEBUG)
		std::cout << \"$CLASS copy constructor called\" << std::endl;
	*this = copy;
}

$CLASS &$CLASS::operator=(const $CLASS &copy)
{
	if (DEBUG)
		std::cout << \"$CLASS copy assignment operator called\" << std::endl;
	if (this != &copy)
	{
	}
	return *this;
}

"$CLASS"::~"$CLASS"(void)
{
	if (DEBUG)
		std::cout << \"$CLASS destructor called\" << std::endl;
}" >> $FILE_CPP


echo "
#include \"$FILE_HPP\"
#include \"doctest.h\"

TEST_SUITE(\"Class $CLASS\")
{
	TEST_CASE(\"Orthodox Canonical Form\")
	{
		$CLASS obj1;
		$CLASS obj2(obj1);
		$CLASS obj3 = obj2;
	}
}" >> $FILE_TEST