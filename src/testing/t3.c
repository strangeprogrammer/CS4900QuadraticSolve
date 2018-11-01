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
	bool ebool;
	cunit_init();
	x1 = 3.1;
	x2 = 3.3;
	a = 1.0;
	b = -x1 + -x2;	//b=-.6.4
	c = x1 * x2;	//a,b,c values		c=10.23
	ebool = isquad(a, b, c);
	assert_eq("isquad() returns (t)quadratic", ebool, true);

	x1 = (1.1*3.0) - 3.8;		//Test 2
	x2=0;
	a = 0;		//a=1
	b = (1.1*3.0) - 1.3;		//b=2
	c = (1.1*3.0) - 2.3;		//c=1
	bool fbool;
	fbool = isquad(0, 2, 1);
	assert_eq("isquad() returns (f)linear", fbool, false);


	//FEQ TESTS/VARIABLES
	a = 1.1*3.0;		//3.3
	b = (1.1*3.0) - 3.0;		//.3
	bool rbool, sbool, tbool;
	rbool = feq(a, 3.3);
	assert_eq("feq not working right", rbool, 1);
	sbool = feq(b, .3);
	assert_eq("feq not working right", sbool, 1);
	tbool = feq(3, 2);
	assert_eq("feq not working right", tbool, 0);
}
