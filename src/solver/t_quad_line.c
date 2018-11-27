/*
* t_quad_line.c
* Unit tests quadratic_quadratic() and linear_linear().
* Calculates the roots and number of roots
*   (respectively) for  intercepts.low and intercepts.high
*/

#include "../libraries.h"
#include "../cunit/cunit.h"
#include "quadratic.h"
#include "linear.h"
#include "../misc.h"


int main(){//Need to check intercept values and number of roots value
	cunit_init();//Initialize the unit testing framework
	//All values have been calculated in advance on paper to test the program against
	
	//QUADRATIC TESTS/VARIABLES
	//Test with 2 zeroes
	float x1, x2, a, b, c;
	intercepts ret;
	x1 = 3.1;
	x2 = 3.3;
	a = 1.0;
	b = -6.4;
	c = 10.23;
	ret = quadratic(a, b, c);
	assert_eq("Wrong number of roots",ret.numroots, 2);
	assert_feqaerr("Wrong value for the low root", ret.low, x1, .0001);
	assert_feqaerr("Wrong value for the high root", ret.high, x2, .0001);
	
	//Test with 1 zero
	x1 = -5;
	a = 1;
	b = 10;
	c = 25;
	ret = quadratic(a, b, c);
	assert_eq("Wrong number of roots",ret.numroots, 1);
	assert_feqaerr("Wrong value for the only root", ret.low, x1, .0001);
	
	//Test with 0 zeroes
	a = 1;
	b = -10;
	c = 30;
	ret = quadratic(a, b, c);
	assert_eq("Wrong number of roots",ret.numroots, 0);
	
	//LINEAR TESTS/VARIABLES
	//Test a regular line
	x1 = -0.5;
	b = 2.0;
	c = 1.0;
	ret = linear(b, c);
	assert_eq("Wrong number of roots",ret.numroots, 1);
	assert_feqaerr("Wrong value for the low root", ret.low, x1, .000001);
	
	//Test a horizontal line with 0 intercepts
	b = 0;
	c = 1.0;
	ret = linear(b, c);
	assert_eq("Wrong number of roots",ret.numroots, 0);
	assert_feqaerr("Wrong value for the low root", ret.low, x1, .000001);
	
	//Test a horizontal line with infinite intercepts
	x1 = 0;//The default return value for infinite intercepts
	b = 0;
	c = 0;
	ret = linear(b, c);
	assert_eq("Wrong number of roots",ret.numroots, 1);
	assert_feqaerr("Wrong value for the low root", ret.low, x1, .000001);
}
