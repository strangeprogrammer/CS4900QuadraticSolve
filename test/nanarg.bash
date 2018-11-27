#!/bin/bash

source ./bashunit.bash

#Active High Tests

assert_returned "NAN\nNAN\nNAN\n" $NANARG_ERR || exit 1

#Active Low Tests

assert_nreturned "1\n1\n1\n" $NANARG_ERR || exit 1

exit 0
