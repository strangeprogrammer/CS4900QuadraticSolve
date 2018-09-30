#!/bin/bash

#Test ability to recognize NAN's
$PROG NAN NAN NAN &>/dev/null
if [ "$?" != "$NANARG_ERR" ]; then
	exit 1
fi

#Test ability to recognize NAN's
$PROG 1 1 1 &>/dev/null
if [ "$?" == "$NANARG_ERR" ]; then
	exit 1
fi

exit 0
