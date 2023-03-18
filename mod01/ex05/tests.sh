#!/bin/sh

BIN=./harl.out

EXPECTED=expect.log
OUTPUT=out.log

MSG_DEBUG="DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
MSG_INFO="INFO: I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger !If you did, I wouldn't be asking for more!"
MSG_WARNING="WARNING: I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
MSG_ERROR="ERROR: This is unacceptable! I want to speak to the manager now"
MSG_INVALID="Invalid level: "

echo "all"
echo -n "" > $EXPECTED
echo $MSG_DEBUG >> $EXPECTED
echo $MSG_INFO >> $EXPECTED
echo $MSG_WARNING >> $EXPECTED
echo $MSG_ERROR >> $EXPECTED

./$BIN > $OUTPUT
diff $EXPECTED $OUTPUT

echo "DEBUG"
echo $MSG_DEBUG > $EXPECTED
./$BIN DEBUG > $OUTPUT
diff $EXPECTED $OUTPUT

echo "INFO"
echo $MSG_INFO > $EXPECTED
./$BIN INFO > $OUTPUT
diff $EXPECTED $OUTPUT

echo "WARNING"
echo $MSG_WARNING > $EXPECTED
./$BIN WARNING > $OUTPUT
diff $EXPECTED $OUTPUT

echo "ERROR"
echo $MSG_ERROR > $EXPECTED
./$BIN ERROR > $OUTPUT
diff $EXPECTED $OUTPUT

echo "invalid"
echo "$MSG_INVALID"invalid > $EXPECTED
./$BIN invalid > $OUTPUT
diff $EXPECTED $OUTPUT

echo "invalid2"
echo "$MSG_INVALID"invalid2 > $EXPECTED
./$BIN invalid2 > $OUTPUT
diff $EXPECTED $OUTPUT