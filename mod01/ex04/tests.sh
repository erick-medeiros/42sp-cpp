BIN=replace.out
INFILE=tests.log
EXPECTED=expected.log
OUTFILE=$INFILE.replace

echo "test 1"
echo "one two three" > $INFILE
echo "two two three" > $EXPECTED
./$BIN $INFILE one two
diff $EXPECTED $OUTFILE

echo "test 2"
echo "oone two three" > $INFILE
echo "otwo two three" > $EXPECTED
./$BIN $INFILE one two
diff $EXPECTED $OUTFILE

echo "test 3"
echo "the recursion module caused automatic race condition" > $INFILE
echo "the recursoin module caused automatic race conditoin" > $EXPECTED
./$BIN $INFILE io oi
diff $EXPECTED $OUTFILE

echo "test 4"
echo "usage: replace [FILENAME] [SEARCH] [REPLACE]" > $EXPECTED
./$BIN > $OUTFILE
diff $EXPECTED $OUTFILE

echo "test 5"
echo "few arguments" > $EXPECTED
./$BIN $INFILE &> $OUTFILE
diff $EXPECTED $OUTFILE

echo "test 6"
echo "pull request from SCRUM caused polymorphism bug" > $INFILE
echo "pullrequestfromSCRUMcausedpolymorphismbug" > $EXPECTED
./$BIN $INFILE " " ""
diff $EXPECTED $OUTFILE

echo "test 7"
echo "uffbuffbuffbuffbuffbuf" > $INFILE
echo "ufferbufferbufferbufferbufferbuf" > $EXPECTED
./$BIN $INFILE "ff" "ffer"
diff $EXPECTED $OUTFILE

echo "test 8"
echo "aiAiAIaiAiaI" > $INFILE
echo "AIAiAIAIAiaI" > $EXPECTED
./$BIN $INFILE "ai" "AI"
diff $EXPECTED $OUTFILE

echo "test 9"
echo "loop race" > $INFILE
echo "loop race" > $EXPECTED
./$BIN $INFILE "abc" "bca"
diff $EXPECTED $OUTFILE

echo "test 10"
echo "Sed is for losers" > $INFILE
echo "Replace is for winners" > $EXPECTED
./$BIN $INFILE "Sed is for losers" "Replace is for winners"
diff $EXPECTED $OUTFILE

echo "test 11"
echo "Sed is for losers" > $INFILE
echo "Replace is for winners" > $EXPECTED
./$BIN $INFILE "Sed is for losers" "Replace is for winners"
diff $EXPECTED $OUTFILE

echo "test 12"
echo "none" > $INFILE
echo "none" > $EXPECTED
./$BIN $INFILE "none" "none"
diff $EXPECTED $OUTFILE

echo "test 13"
echo "err" > $INFILE
echo "Error opening: err$INFILE" > $EXPECTED
./$BIN err$INFILE "1" "2" &>$OUTFILE
diff $EXPECTED $OUTFILE

echo "test 14"
echo "err" > $INFILE
echo "Error opening: $INFILE" > $EXPECTED
chmod 000 $INFILE
./$BIN $INFILE "1" "2" &>$OUTFILE
chmod 644 $INFILE
diff $EXPECTED $OUTFILE

echo "test 15"
echo "clean" > $INFILE
echo "clean" > $EXPECTED
./$BIN $INFILE "cleaned" "err" &>$OUTFILE
diff $EXPECTED $OUTFILE

echo "test 16"
echo "barra abc" > $INFILE
echo "barra	abc" > $EXPECTED
./$BIN $INFILE " " "	"
diff $EXPECTED $OUTFILE

echo "test 17"
echo "barra abc" > $INFILE
echo "barra\tabc" > $EXPECTED
./$BIN $INFILE " " "\t"
diff $EXPECTED $OUTFILE

echo "test 18"
echo "ccccccccccccccccccccccccccccccc" > $INFILE
echo "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" > $EXPECTED
./$BIN $INFILE "c" "x"
diff $EXPECTED $OUTFILE

echo "test 19"
echo "ccccccccccccccccccccccccccccccc" > $INFILE
echo "" > $EXPECTED
./$BIN $INFILE "c" ""
diff $EXPECTED $OUTFILE

echo "test 20"
echo "ccccccccccccccccccccccccccccccc" > $INFILE
echo "ccccccccccccccccccccccccccccccc" > $EXPECTED
./$BIN $INFILE "" "c"
diff $EXPECTED $OUTFILE