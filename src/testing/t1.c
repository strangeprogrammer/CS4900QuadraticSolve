/*
* t1.c
* Unit tests quadratic() and linear()
* solves a * x^2 + b x + c = 0 or mx + b = 0
*   (respectively) for the roots
* intercepts.low and intercepts.high
*
*/

#include <stdlib.h>
#include "cunit.h"
#include "../solver/quadratic.h"
#include "../solver/linear.h"
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
    assert_feqrerr("Wrong value for the high root", ret.high, x2, .000001);
    assert_feqrerr("Wrong value for the low root", ret.low, x1, .000001);


    //LINEAR TESTS/VARIABLES
    numroots = 1;
    x1 = (1.1*3.0) - 3.8;
    x2=0;
    a = 1.0;		//a=1
    b = (1.1*3.0) - 1.3;		//b=2
    c = (1.1*3.0) - 2.3;		//c=1
    ret2 = linear(b, c);
    assert_eq("Wrong number of roots",ret2.numroots, numroots);
    assert_feqrerr("Wrong value for the low root", ret2.low, x1, .000001);

}
