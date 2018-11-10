/*
* t1.c
* Unit tests quadratic_quadratic() and linear_linear().
* Calculates the roots and number of roots
*   (respectively) for  intercepts.low and intercepts.high
*/

#include <stdlib.h>
#include "../cunit.h"
#include "quadratic.h"
#include "linear.h"
#include "../misc.h"


int main() {		//Need to check intercept values and number of roots value

    //QUADRATIC TESTS/VARIABLES
    float x1, x2, a, b, c;
    intercepts ret, ret2;
    int numroots = 2;
    cunit_init();		// initialize the unit testing framework
    x1 = 3.1;
    x2 = 3.3;		//scratch variables
    a = 1.0;
    b = -x1 + -x2;	//b=-.6.4
    c = x1 * x2;	//a,b,c values		c=10.23
    ret = quadratic(a, b, c);
    assert_eq("Wrong number of roots",ret.numroots, numroots);
    assert_feqaerr("Wrong value for the high root", ret.high, x2, .0001);
    assert_feqaerr("Wrong value for the low root", ret.low, x1, .0001);


    //LINEAR TESTS/VARIABLES
    numroots = 1;
    x1 = -0.5;
    x2 = 0;
    a = 1.0;		//a=1
    b = 2.0;		//b=2
    c = 1.0;		//c=1
    ret2 = linear(b, c);
    assert_eq("Wrong number of roots",ret2.numroots, numroots);
    assert_feqaerr("Wrong value for the low root", ret2.low, x1, .000001);
}
