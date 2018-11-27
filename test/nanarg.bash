#!/bin/bash

source ./bashunit.bash

#Active High Tests

echo -e "NAN\nNAN\nNAN\n" | $PROG &>/dev/null
assert_returned "$NANARG_ERR" || exit 1

#Active Low Tests

echo -e "1\n1\n1\n" | $PROG &>/dev/null
assert_nreturned "$NANARG_ERR" || exit 1

exit 0
