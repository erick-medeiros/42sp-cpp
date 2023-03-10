#!/bin/sh

_test_output()
{
	# number - expected - result
	if [ "$2" != "$3" ]; then
		echo "Fail $1"
		echo "Expected :" $2
		echo "Result   :" $3
		exit 1
	fi
}

TEST=$(valgrind -q ./megaphone "shhhhh... I think the students are asleep...")
RESULT="SHHHHH... I THINK THE STUDENTS ARE ASLEEP..."
_test_output 1 "$TEST" "$RESULT"

TEST=$(valgrind -q ./megaphone Damnit " ! " "Sorry students, I thought this thing was off.")
RESULT="DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF."
_test_output 2 "$TEST" "$RESULT"

TEST=$(valgrind -q ./megaphone)
RESULT="* LOUD AND UNBEARABLE FEEDBACK NOISE *"
_test_output 3 "$TEST" "$RESULT"

echo "all tests passed"