/*
* t4.c
* Unit tests for quadfunc(), validate()
*		quadfunc returns float and validate returns bools
*/

#include "../libraries.h"
#include "../cunit.h"
#include "validate.h"
#include "mock_validate_feq.h"

int main(){
	cunit_init();// initialize the unit testing framework
	
	//VALIDATE_VALIDATE TESTS/VARIABLES
	float a, b, c, x, z;
	intercepts y = {y.low=2, y.high=1, y.numroots=1};
	intercepts y2 = {y2.low=0, y2.high=0, y2.numroots=1};
	char	str[100];// message for assert()
	int count = 0;
	
	x=y.high; z=0;
	mock_setup_validate_feq(x, z, false, .0001);
	
	a=2; b=2; c=2;
	bool k = validate(a,b,c,y);
	assert_eq("ret", k, 0);		//t1
	
	mock_check_validate_feq(&count, &x, &z);	//Store count in count etc.
	snprintf(str, 99, "count k = %d, x =%20.61e", k, x);	//Store str
	assert_eq(str, k , 0);		//Check k is false
	
	//Mock object is set to neccesary values
	x=0; z=0;
	mock_setup_validate_feq(x, z, true, .0001);	//Validate should return true
	
	a=0; b=0; c=-0;
	bool k2 = validate(a, b, c, y2);		//validate should = true
	assert_eq("ret", k2, 1);
	
	mock_check_validate_feq(&count, &x, &z);	//Store count in count etc.
	snprintf(str, 99, "count k2 = %d, x =%20.61e", k2, x);	//Store str
	assert_eq(str, k2 , 1);		//Check k2 is true
}
