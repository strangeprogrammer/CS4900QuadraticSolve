#!/bin/bash

source ./bashunit.bash

#Shouldn't overflow:	1e-37
#Should overflow:	1e-38

#Active High Tests

echo -e "1e-256\n1e-256\n1e-256\n" | $PROG &>/dev/null
assert_returned "$UNDERFLOW_ERR" || exit 1

echo -e "1e-38\n1e-38\n1e-38\n" | $PROG &>/dev/null
assert_returned "$UNDERFLOW_ERR" || exit 1

#Active Low Tests

echo -e "1e-1\n1e-1\n1e-1\n" | $PROG &>/dev/null
assert_nreturned "$UNDERFLOW_ERR" || exit 1

echo -e "1e-37\n1e-37\n1e-37\n" | $PROG &>/dev/null
assert_nreturned "$UNDERFLOW_ERR" || exit 1

exit 0
