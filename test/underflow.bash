#!/bin/bash

source ./bashunit.bash

#Shouldn't underflow:	1e-37
#Should underflow:	1e-38

#Active High Tests

assert_returned "1e-256\n1e-256\n1e-256\n" $UNDERFLOW_ERR || exit 1
assert_returned "1e-38\n1e-38\n1e-38\n" $UNDERFLOW_ERR || exit 1

#Active Low Tests

assert_nreturned "1e-1\n1e-1\n1e-1\n" $UNDERFLOW_ERR || exit 1
assert_nreturned "1e-37\n1e-37\n1e-37\n" $UNDERFLOW_ERR || exit 1

exit 0
