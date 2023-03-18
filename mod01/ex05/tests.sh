#!/bin/sh

BIN=./harl.out

EXPECTED=expect.log
OUTPUT=out.log
ERROR=error.log

MSG_DEBUG="[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
MSG_INFO="[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger !If you did, I wouldn't be asking for more!"
MSG_WARNING="[ WARNING ]\nI think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
MSG_ERROR="[ ERROR ]\nThis is unacceptable! I want to speak to the manager now"
MSG_INVALID="Invalid level: "

echo "all"
echo -n "" > $EXPECTED
echo -e $MSG_DEBUG >> $EXPECTED
echo -e $MSG_INFO >> $EXPECTED
echo -e $MSG_WARNING >> $EXPECTED
echo -e $MSG_ERROR >> $EXPECTED

./$BIN > $OUTPUT
diff $EXPECTED $OUTPUT

echo "DEBUG"
echo -e $MSG_DEBUG > $EXPECTED
./$BIN DEBUG > $OUTPUT
diff $EXPECTED $OUTPUT

echo "INFO"
echo -e $MSG_INFO > $EXPECTED
./$BIN INFO > $OUTPUT
diff $EXPECTED $OUTPUT

echo "WARNING"
echo -e $MSG_WARNING > $EXPECTED
./$BIN WARNING > $OUTPUT
diff $EXPECTED $OUTPUT

echo "ERROR"
echo -e $MSG_ERROR > $EXPECTED
./$BIN ERROR > $OUTPUT
diff $EXPECTED $OUTPUT

echo "invalid"
echo "$MSG_INVALID"invalid > $EXPECTED
./$BIN invalid > $OUTPUT &> $ERROR
diff $EXPECTED $ERROR

echo "invalid2"
echo "$MSG_INVALID"invalid2 > $EXPECTED
./$BIN invalid2 > $OUTPUT &> $ERROR
diff $EXPECTED $ERROR