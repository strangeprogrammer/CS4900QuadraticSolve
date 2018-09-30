#!/bin/bash

#Active Low Test
$PROG INF INF INF &>/dev/null
if [ "$?" != "$OVERFLOW_ERR" ]; then
	exit 1
fi

#Active Low Test
$PROG 1e256 1e256 1e256 &>/dev/null
if [ "$?" != "$OVERFLOW_ERR" ]; then
	exit 1
fi

#Active Low Test
$PROG -INF -INF -INF &>/dev/null
if [ "$?" != "$OVERFLOW_ERR" ]; then
	exit 1
fi

#Active Low Test
$PROG -1e256 -1e256 -1e256 &>/dev/null
if [ "$?" != "$OVERFLOW_ERR" ]; then
	exit 1
fi

#Active High Test
$PROG 100 100 100 &>/dev/null
if [ "$?" == "$OVERFLOW_ERR" ]; then
	exit 1
fi

exit 0
