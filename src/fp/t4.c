/*
* t4.c
* Unit tests for quadfunc(), validate()
*		quadfunc returns float and validate returns bools
*/

#include "../libraries.h"
#include "../cunit.h"
#include "validate.h"

int main(){

	//validate_validate tests
	cunit_init();		// initialize the unit testing framework
	float a, b, c, x;
	intercepts y = {y.low=2, y.high=1, y.numroots=1};
	intercepts y2 = {y2.low=0, y2.high=0, y2.numroots=1};

	a=2; b=2; c=2;
	bool k = validate(a,b,c,y);
	assert_eq("ret", k, 0);		//t1

	a=0; b=0; c=-0;
	bool k2 = validate(a, b, c, y2);
	assert_eq("ret", k2, 1);		//t2


	//validate_isquad tests
	x = 1.0;
	a = 1.0;
	b = -6.4;
	c = 10.23;
	assert_feqrerr("quadfunc return is not working", quadfunc(a, b, c, x), 4.83, .000001);

	a = 0;
	b = 2.0;
	c = 1.0;
	assert_feqrerr("quadfunc return is not working", quadfunc(a, b, c, x), 3.00, .000001);

}
