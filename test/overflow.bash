#!/bin/bash

source ./bashunit.bash

#Active High Tests

echo -e "INF\nINF\nINF\n" | $PROG &>/dev/null
assert_returned "$OVERFLOW_ERR" || exit 1

echo -e "1e256\n1e256\n1e256\n" | $PROG &>/dev/null
assert_returned "$OVERFLOW_ERR" || exit 1

echo -e "-INF\n-INF\n-INF\n" | $PROG &>/dev/null
assert_returned "$OVERFLOW_ERR" || exit 1

echo -e "-1e256\n-1e256\n-1e256\n" | $PROG &>/dev/null
assert_returned "$OVERFLOW_ERR" || exit 1

#Active Low Tests

echo -e "100\n100\n100\n" | $PROG &>/dev/null
assert_nreturned "$OVERFLOW_ERR" || exit 1

exit 0
