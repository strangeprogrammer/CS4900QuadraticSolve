#!/bin/bash

source ./bashunit.bash

#Active High Tests

echo -e "\n" | $PROG &>/dev/null
assert_returned "$NOARG_ERR" || exit 1

echo -e "1\n\n" | $PROG &>/dev/null
assert_returned "$NOARG_ERR" || exit 1

echo -e "1\n2\n\n" | $PROG &>/dev/null
assert_returned "$NOARG_ERR" || exit 1

#Active Low Tests

echo -e "1\n2\n3\n" | $PROG &>/dev/null
assert_nreturned "$NOARG_ERR" || exit 1

exit 0
