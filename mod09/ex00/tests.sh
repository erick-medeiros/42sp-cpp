#!/bin/sh

# config
BIN=btc
ERROR_USAGE_MSG="Usage: btc <input_file>"
ERROR_OPEN_MSG="Error: could not open file:" # + filename
ERROR_NOTFILE_MSG="Error: filename is not a file:" # + filename

# aux
cp input.txt input.log
INPUT_FILE=input.log
EXPECT_FILE=expect.log
OUTPUT_FILE=output.log
ERROR_FILE=error.log
LOG_FILE=log.log

# setup
echo -n > $LOG_FILE

# test empty
echo "test1" >> $LOG_FILE
./$BIN 1>$OUTPUT_FILE 2>$ERROR_FILE
echo $ERROR_USAGE_MSG > $EXPECT_FILE
diff $EXPECT_FILE $ERROR_FILE || exit

# test mult
echo "test2" >> $LOG_FILE
./$BIN 1>$OUTPUT_FILE 2>$ERROR_FILE $INPUT_FILE $INPUT_FILE $INPUT_FILE
echo $ERROR_USAGE_MSG > $EXPECT_FILE
diff $EXPECT_FILE $ERROR_FILE || exit

# test perm
echo "test3" >> $LOG_FILE
chmod 000 $INPUT_FILE
./$BIN 1>$OUTPUT_FILE 2>$ERROR_FILE $INPUT_FILE
chmod 644 $INPUT_FILE
echo "$ERROR_OPEN_MSG $INPUT_FILE" > $EXPECT_FILE
diff $EXPECT_FILE $ERROR_FILE || exit

# test notfound
echo "test4" >> $LOG_FILE
./$BIN 1>$OUTPUT_FILE 2>$ERROR_FILE _not_found_
echo "$ERROR_OPEN_MSG _not_found_" > $EXPECT_FILE
diff $EXPECT_FILE $ERROR_FILE || exit

# test dir
echo "test5" >> $LOG_FILE
./$BIN 1>$OUTPUT_FILE 2>$ERROR_FILE .
echo "$ERROR_NOTFILE_MSG ." > $EXPECT_FILE
diff $EXPECT_FILE $ERROR_FILE || exit

# rm
rm -r $EXPECT_FILE $OUTPUT_FILE $ERROR_FILE $LOG_FILE $INPUT_FILE