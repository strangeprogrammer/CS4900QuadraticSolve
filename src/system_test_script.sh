#!/bin/bash

{
	echo -e "1\n2\n3\n"		| ./quadsolve
	echo -e "1\n-6.4\n10.23\n"	| ./quadsolve
	echo -e "1\n10\n25\n"		| ./quadsolve
	echo -e "1\n-10\n30\n"		| ./quadsolve
	echo -e "-.5\n2\n1\n"		| ./quadsolve
} > st_actual_output.txt

diff st_actual_output.txt st_expected_output.txt >> system_test_log.txt
if [ $? != 0 ]; then
	echo "SYSTEM TEST FAILED: Check sytem_test_log for more info."
	echo $(date) >> system_test_log.txt
	echo "" >>system_test_log.txt
fi

rm st_actual_output.txt
