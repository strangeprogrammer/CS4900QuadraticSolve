#!/bin/bash

RETVAL=1

$PROG &>/dev/null
if [ "$?" != "1" ]; then
	exit 1
fi

$PROG 3 &>/dev/null
if [ "$?" != "1" ]; then
	exit 1
fi

$PROG 3 2 &>/dev/null
if [ "$?" != "1" ]; then
	exit 1
fi

$PROG 3 2 1 &>/dev/null
if [ "$?" == "1" ]; then
	exit 1
fi

$PROG 3 2 1 0 &>/dev/null
if [ "$?" != "1" ]; then
	exit 1
fi

exit 0
