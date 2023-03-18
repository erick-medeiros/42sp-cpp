#!/bin/sh

BIN=./harlFilter.out

EXPECTED=expect.log
OUTPUT=out.log
ERROR=error.log

MSG_DEBUG="[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n"
MSG_INFO="[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger !If you did, I wouldn't be asking for more!\n"
MSG_WARNING="[ WARNING ]\nI think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n"
MSG_ERROR="[ ERROR ]\nThis is unacceptable! I want to speak to the manager now\n"
MSG_INVALID="[ Probably complaining about insignificant problems ]"

echo "DEBUG"
echo -n "" > $EXPECTED
echo -e $MSG_DEBUG >> $EXPECTED
echo -e $MSG_INFO >> $EXPECTED
echo -e $MSG_WARNING >> $EXPECTED
echo -e $MSG_ERROR >> $EXPECTED

./$BIN "DEBUG" > $OUTPUT
diff $EXPECTED $OUTPUT

echo "INFO"
echo -n "" > $EXPECTED
echo -e $MSG_INFO >> $EXPECTED
echo -e $MSG_WARNING >> $EXPECTED
echo -e $MSG_ERROR >> $EXPECTED

./$BIN "INFO" > $OUTPUT
diff $EXPECTED $OUTPUT

echo "WARNING"
echo -n "" > $EXPECTED
echo -e $MSG_WARNING >> $EXPECTED
echo -e $MSG_ERROR >> $EXPECTED

./$BIN "WARNING" > $OUTPUT
diff $EXPECTED $OUTPUT

echo "ERROR"
echo -n "" > $EXPECTED
echo -e $MSG_ERROR >> $EXPECTED

./$BIN "ERROR" > $OUTPUT
diff $EXPECTED $OUTPUT

echo "other"
echo -n "" > $EXPECTED
echo -e $MSG_INVALID >> $EXPECTED

./$BIN "other" > $OUTPUT
diff $EXPECTED $OUTPUT
