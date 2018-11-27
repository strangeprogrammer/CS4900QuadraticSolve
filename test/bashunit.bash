#!/bin/bash

function assert_streq {
	[ "$1" == "$2" ] && return 0
	return 1
}

function assert_strneq {
	[ "$1" != "$2" ] && return 0
	return 1
}

function assert_returned {
	return $(assert_streq "$?" "$1")
}

function assert_nreturned {
	return $(assert_strneq "$?" "$1")
}
