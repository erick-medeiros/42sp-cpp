#!/bin/sh

EXPECT="expect.log"
RESULT="result.log"
COMMAND=""

echo -n > $RESULT
echo -n > $EXPECT

COMMAND="./convert 0"

echo $COMMAND >> $EXPECT
echo $COMMAND >> $RESULT
$COMMAND >> $RESULT
echo "char: Non displayable
int: 0
float: 0.0f
double: 0.0" >> $EXPECT

COMMAND="./convert nan"

echo $COMMAND >> $EXPECT
echo $COMMAND >> $RESULT
$COMMAND >> $RESULT
echo "char: impossible
int: impossible
float: nanf
double: nan" >> $EXPECT

COMMAND="./convert 42.0f"

echo $COMMAND >> $EXPECT
echo $COMMAND >> $RESULT
$COMMAND >> $RESULT
echo "char: '*'
int: 42
float: 42.0f
double: 42.0" >> $EXPECT

COMMAND="./convert 1f.1"

echo $COMMAND >> $EXPECT
echo $COMMAND >> $RESULT
$COMMAND >> $RESULT
echo "char: impossible
int: impossible
float: impossible
double: impossible" >> $EXPECT

COMMAND="./convert nanf"

echo $COMMAND >> $EXPECT
echo $COMMAND >> $RESULT
$COMMAND >> $RESULT
echo "char: impossible
int: impossible
float: nanf
double: nan" >> $EXPECT


COMMAND="./convert nan"

echo $COMMAND >> $EXPECT
echo $COMMAND >> $RESULT
$COMMAND >> $RESULT
echo "char: impossible
int: impossible
float: nanf
double: nan" >> $EXPECT


COMMAND="./convert -inff"

echo $COMMAND >> $EXPECT
echo $COMMAND >> $RESULT
$COMMAND >> $RESULT
echo "char: impossible
int: impossible
float: -inff
double: -inf" >> $EXPECT

COMMAND="./convert +inff"

echo $COMMAND >> $EXPECT
echo $COMMAND >> $RESULT
$COMMAND >> $RESULT
echo "char: impossible
int: impossible
float: inff
double: inf" >> $EXPECT


COMMAND="./convert +inf"

echo $COMMAND >> $EXPECT
echo $COMMAND >> $RESULT
$COMMAND >> $RESULT
echo "char: impossible
int: impossible
float: inff
double: inf" >> $EXPECT

COMMAND="./convert -inf"

echo $COMMAND >> $EXPECT
echo $COMMAND >> $RESULT
$COMMAND >> $RESULT
echo "char: impossible
int: impossible
float: -inff
double: -inf" >> $EXPECT


COMMAND="./convert +42"

echo $COMMAND >> $EXPECT
echo $COMMAND >> $RESULT
$COMMAND >> $RESULT
echo "char: '*'
int: 42
float: 42.0f
double: 42.0" >> $EXPECT


COMMAND="./convert 1239120381023921739"

echo $COMMAND >> $EXPECT
echo $COMMAND >> $RESULT
$COMMAND >> $RESULT
echo "char: impossible
int: impossible
float: impossible
double: impossible" >> $EXPECT


diff $EXPECT $RESULT