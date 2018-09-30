#!/bin/bash

#Active Low Test
$PROG 1e-256 1e-256 1e-256 &>/dev/null
if [ "$?" != "$UNDERFLOW_ERR" ]; then
	exit 1
fi

#Active High Test
$PROG 1e-1 1e-1 1e-1 &>/dev/null
if [ "$?" == "$UNDERFLOW_ERR" ]; then
	exit 1
fi

exit 0
