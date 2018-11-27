#!/bin/bash
#echo "System Test: "
{
./quadsolve "1" "2" "3"
./quadsolve "1" "-6.4" "10.23"
./quadsolve "1" "10" "25"
./quadsolve "1" "-10" "30"
./quadsolve "-.5" "2" "1"
} > st_actual_output.txt
diff st_actual_output.txt st_expected_output.txt >> system_test_log.txt
if [ $? != 0 ]; then
    echo "SYSTEM TEST FAILED: Check sytem_test_log for more info."
    echo $(date) >> system_test_log.txt
    echo "" >>system_test_log.txt
fi
rm st_actual_output.txt
