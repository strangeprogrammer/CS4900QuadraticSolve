/*
* t1.c
* Unit tests for quad_roots()
* solves a * x^2 + b x + c = 0
*   for the roots
* x1 and x2
* *
* This uses the qsolve_sqrt() which calls the system sqrt()
*/

#include <stdlib.h>
#include "cunit.h"
#include "../solver/quadratic.h"
#include "../misc.h"


int main() {		//Need to check intercept values and number of roots value

		//Coef	coefs;   //a, b and c for the quadratic eqaution
		//Root	roots;   //Root struct with x1 and x1
		intercepts icepts;  //Holds 2 floats and an int number of roots - low, high, numroots
		float  a, b, c; //scratch variables
		float  x1, x2;  //scratch variables


		// initialize the unit testing framework
		cunit_init();



		// A "good" unit test, need to allow for round off!
		// qsolve_roots() passes this one. ;-)
		// This allows about one base 10 least significant digit of error
		// (x - x1)*(x - x2) = 0

		//roots are answers and coefs are the values input by user

		x1 = 3.1;
		x2 = 3.3;
		// coefs.a = 1.0;
		a = 1.0;
		// coefs.b = -x1 + -x2;
		b = -x1 + -x2;
		// coefs.c = x1*x2;
		c = x1 * x2;
		// ret = qsolve_roots(&coefs, &roots);
		icepts = quadratic(a, b, c);
		assert_eq("ret",icepts.numroots,2);		//Should be 2 roots
		assert_feqrerr("x1",icepts.low, x2, 10.0*cunit_dmacheps );
		assert_feqrerr("x2",icepts.high, x1, 10.0*cunit_dmacheps );
		// exit(0);
}
