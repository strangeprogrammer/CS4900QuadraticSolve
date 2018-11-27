#!/bin/bash

source ./bashunit.bash

#Active High Tests

assert_returned "\n" $NOARG_ERR || exit 1
assert_returned "1\n\n" $NOARG_ERR || exit 1
assert_returned "1\n2\n\n" $NOARG_ERR || exit 1

#Active Low Tests

assert_nreturned "1\n2\n3\n" $NOARG_ERR || exit 1

exit 0
