#!/bin/bash

#Active Low Test
$PROG NAN NAN NAN &>/dev/null
if [ "$?" != "$NANARG_ERR" ]; then
	exit 1
fi

#Active High Test
$PROG 1 1 1 &>/dev/null
if [ "$?" == "$NANARG_ERR" ]; then
	exit 1
fi

exit 0
