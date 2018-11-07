/*
* t3.c
* Unit tests for ieee_isquad(), ieee_feq()
*		Both return bools
*/

#include <stdlib.h>
#include "cunit.h"
#include "../fp/ieee.h"

int main() {

	//ISQUAD TESTS/VARIABLES
	float a, b, c, x1, x2;	//Test 1
	cunit_init();
	x1 = 3.1;
	x2 = 3.3;
	a = 1.0;
	b = -6.4;	//b=-.6.4
	c = 10.23;	//a,b,c values		c=10.23
	assert_eq("isquad() returns (t)quadratic", isquad(a, b, c), true);
	assert_eq("isquad() returns (f)linear", isquad(0, 2, 1), false);

	//FEQ TESTS/VARIABLES
	a = 3.3;		//3.3
	b = 0.3;		//.3
	assert_eq("feq not working right", feq(a, 3.3), 1);
	assert_eq("feq not working right", feq(b, .3), 1);
	assert_eq("feq not working right", feq(3, 2), 0);
}
