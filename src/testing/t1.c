/*
* t1.c
* Unit tests quadratic()
* solves a * x^2 + b x + c = 0
*   for the roots
* x1 and x2
* *
* This uses the quadratic() function
*/

#include <stdlib.h>
#include "cunit.h"
#include "../solver/quadratic.h"
#include "../misc.h"


int main() {		//Need to check intercept values and number of roots value

//        intercepts icepts;  //Holds 2 floats and an int number of roots - low, high, numroots
//        float  a, b, c; //scratch variables
//        float  x1, x2;  //scratch variables

		cunit_init();		// initialize the unit testing framework
		quadratic(4, 3, 4);
    assert_eq("str", 3, 4);

		//A "good" unit test, need to allow for round off! qsolve_roots() passes this one. ;-)
		//This allows about one base 10 least significant digit of error (x - x1)*(x - x2) = 0
//        x1 = 3.1;
//        x2 = 3.3;
//        a = 1.0;
//        b = -x1 + -x2;
//        c = x1 * x2;
//        icepts = quadratic(a, b, c);
//        assert_eq("Wrong number of roots",icepts.numroots,2);        //Should be 2 roots
//        assert_feqrerr("low intercept",icepts.low, x2, 10.0*cunit_dmacheps );
//        assert_feqrerr("high intercept",icepts.high, x1, 10.0*cunit_dmacheps );
          exit(0);
}
