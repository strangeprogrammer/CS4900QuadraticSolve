#!/bin/bash

#Active Low Test
$PROG &>/dev/null
if [ "$?" != "$NUMARG_ERR" ]; then
	exit 1
fi

#Active Low Test
$PROG 3 &>/dev/null
if [ "$?" != "$NUMARG_ERR" ]; then
	exit 1
fi

#Active Low Test
$PROG 3 2 &>/dev/null
if [ "$?" != "$NUMARG_ERR" ]; then
	exit 1
fi

#Active High Test
$PROG 3 2 1 &>/dev/null
if [ "$?" == "$NUMARG_ERR" ]; then
	exit 1
fi

#Active Low Test
$PROG 3 2 1 0 &>/dev/null
if [ "$?" != "$NUMARG_ERR" ]; then
	exit 1
fi

exit 0
