#!/bin/bash

#Active Low Test
$PROG gib ber ish &>/dev/null
if [ "$?" != "$BADARG_ERR" ]; then
	exit 1
fi

#Active High Test
$PROG 1 2 3 &>/dev/null
if [ "$?" == "$BADARG_ERR" ]; then
	exit 1
fi

exit 0
