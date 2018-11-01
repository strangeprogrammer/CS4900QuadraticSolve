/*
* t4.c
* Unit tests for validate_quadfunc(), validate_validate()
*		quadfunc returns float and validate returns bools
*/

#include <stdlib.h>
#include "cunit.h"
#include "../fp/validate.h"

int main(){

	//VALIDATE_VALIDATE TESTS/VARIABLES
	//float a, b, c, x;
	//intercepts x = {x.low=2, x.high=1, x.numroots=1};
	//bool k = validate(2,2,2,x);
	cunit_init();		// initialize the unit testing framework


	//VALIDATE_ISQUAD TESTS/VARIABLES
	float a, b, c, x, x1, x2, ret, ret2;
	cunit_init();		// initialize the unit testing framework
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
