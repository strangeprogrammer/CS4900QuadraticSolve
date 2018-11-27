#!/bin/bash

source ./bashunit.bash

#Active High Tests

assert_returned "INF\nINF\nINF\n"		$OVERFLOW_ERR || exit 1
assert_returned "1e256\n1e256\n1e256\n"		$OVERFLOW_ERR || exit 1
assert_returned "-INF\n-INF\n-INF\n"		$OVERFLOW_ERR || exit 1
assert_returned "-1e256\n-1e256\n-1e256\n"	$OVERFLOW_ERR || exit 1

#Active Low Tests

assert_nreturned "100\n100\n100\n"		$OVERFLOW_ERR || exit 1

exit 0
