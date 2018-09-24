#!/bin/bash

TESTSTRING="Error: this program needs 3 arguments exactly."

if [ "$($PROG)" != "$TESTSTRING" ]; then
	echo $ERRSTRING
	exit 1
elif [ "$($PROG 0)" != "$TESTSTRING" ]; then
	echo $ERRSTRING
	exit 1
elif [ "$($PROG 0 1)" != "$TESTSTRING" ]; then
	echo $ERRSTRING
	exit 1
elif [ "$($PROG 0 1 2)" == "$TESTSTRING" ]; then
	echo $ERRSTRING
	exit 1
elif [ "$($PROG 0 1 2 3)" != "$TESTSTRING" ]; then
	echo $ERRSTRING
	exit 1
fi

exit 0
