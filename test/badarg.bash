#!/bin/bash

source ./bashunit.bash

#Active High Tests

assert_returned "gib\nber\nish\n" $BADARG_ERR || exit 1

#Active High Tests

assert_nreturned "1\n2\n3\n" "$BADARG_ERR" || exit 1

exit 0
