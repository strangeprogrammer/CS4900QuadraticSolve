/*
* t4.c
* Unit tests for quadfunc(), validate()
*		quadfunc returns float and validate returns bools
*/

#include <stdlib.h>
#include "cunit.h"
#include "../fp/validate.h"

int main(){

	//VALIDATE_VALIDATE TESTS/VARIABLES
	cunit_init();		// initialize the unit testing framework
	float a, b, c, x, ret, ret2;
	intercepts y = {y.low=2, y.high=1, y.numroots=1};
	intercepts y2 = {y2.low=0, y2.high=0, y2.numroots=2};

	a=2; b=2; c=2;
	bool k = validate(a,b,c,y);
	assert_eq("ret", k, 0);		//t1

	a=0; b=0; c=-0;
	bool k2 = validate(a, b, c, y2);
	assert_eq("ret", k2, 1);		//t2


	//VALIDATE_ISQUAD TESTS/VARIABLES
	float x1, x2;
	x = 1.0;
	x1 = 3.1;
	x2 = 3.3;		//scratch variables
	a = 1.0;
	b = -x1 + -x2;	//b=-.6.4
	c = x1 * x2;	//a,b,c values		c=10.23
	ret = quadfunc(a, b, c, x);	//4.83
	assert_feqrerr("quadfunc return is not working", ret, 4.83, .000001);

	x1 = (1.1*3.0) - 3.8;		//Test 2
	x2=0;
	a = 0;		//a=1
	b = (1.1*3.0) - 1.3;		//b=2
	c = (1.1*3.0) - 2.3;		//c=1
	ret2 = quadfunc(a, b, c, x);
	assert_feqrerr("quadfunc return is not working", ret2, 3.00, .000001);
}
