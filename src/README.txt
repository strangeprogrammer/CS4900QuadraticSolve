Directory containing all the program source files and tests.



CONTENTS:

file		//DESCRIPTION

cunit/		//Cunit testing suite
fp/		//Stuff relating to the floating point internals, not the actual solver
libraries.h	//Includes all system libraries
main.c		//The main program
makefile	//Used to build and test the program; instructions below
make.i		//Auxilliary makefile for common functions and misc.
misc.h		//Contains some useful typedefs
parsing/	//Parses the given input and returns an error if it's invalid
README.txt	//You're reading me right now!
solver/		//The actual quadratic equation solver
input/		//Retrieves raw user input and converts it to a,b, and c values
st_expected_output.txt/		//Ouput compared to actual ouput for system test
system_test_log/		//Logs the errors which arise from system tests
system_test_script.sh		//Script which runs the system tests



MAKE INSTRUCTIONS:

To make the program, type 'make' or 'make quadsolve'.
The name of the program will be 'quadsolve'.

To make all the tests and run them, type 'make test'.

To remove all object files recursively, type 'make clean'.

To remove all object files and binary files recursively, type 'make squeaky'.
