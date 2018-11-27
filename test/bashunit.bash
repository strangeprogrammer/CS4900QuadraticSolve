#!/bin/bash

function assert_returned {
	echo -e "$1" | $PROG &>/dev/null
	local retval="$?"
	[ "$retval" == "$2" ] && return 0
	#https://stackoverflow.com/a/192337
	echo "Error: File \"$(basename $0)\": String \"$1\": \"$retval\" != \"$2\""
	return 1
}

function assert_nreturned {
	echo -e "$1" | $PROG &>/dev/null
	local retval="$?"
	[ "$retval" != "$2" ] && return 0
	#https://stackoverflow.com/a/192337
	echo "Error: File \"$(basename $0)\": String \"$1\": \"$retval\" == \"$2\""
	return 1
}
