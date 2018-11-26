/*
* t3.c
* Unit tests for ieee_isquad(), ieee_feq()
*		Both return bools
*/

#include "../cunit/cunit.h"
#include "ieee.h"

int main(){
	cunit_init();
    cunit_open("../cunit/cunitLog.txt");
	
	//ISQUAD TESTS/VARIABLES
	//The following single test has roots x1 = 3.1 and x2 = 3.3
	assert_eq("isquad doesn't return quadratic",	isquad(1.0, -6.4, 10.23),true);
	assert_eq("isquad doesn't return linear",	isquad(0, 2, 1),false);
	
	//FEQ TESTS/VARIABLES
	assert_eq("feq not working right", feq((1.1*5) - 2.2,	3.3),true);
	assert_eq("feq not working right", feq((1.1*3) - 3,	.3),true);
	assert_eq("feq not working right", feq(3,2),false);
    
    cunit_close;
	return 0;
}
