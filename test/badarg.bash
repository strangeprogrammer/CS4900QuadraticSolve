#!/bin/bash

source ./bashunit.bash

#Active High Tests

echo -e "gib\nber\nish\n" | $PROG &>/dev/null
assert_returned "$BADARG_ERR" || exit 1

#Active High Tests

echo -e "1\n2\n3\n" | $PROG &>/dev/null
assert_nreturned "$BADARG_ERR" || exit 1

exit 0
