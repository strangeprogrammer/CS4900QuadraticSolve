// mock_linear.c
// mock_linear is a mock object for linear()
// This allows:	--MODIFICATION HERE - everything below
//
// First called is:
// mock_setup_linear():  currently allows only one x value at a time.
//
// Them call:
// linear():  the mock linear() in this module.
//  It has the same signiture as the usual
//     linear()
//
// Then call:
// mock_check_linear():  to check for corectness of
//     the call to the mock_linear()
//
// The mock linear() does keep track of the number of times
//    it is called, which should only be 1.

#include <math.h>
#include "mock_linear.h"
#include "linear.h"
#include "../libraries.h"
#include "../fp/ieee.h"
#include "../misc.h"

static float b = -1;		//Actual arguments passed to linear()
static float c = -1;		//Actual arguments passed to linear()

static float eb = -1;		//Expected argument b to linear()
static float ec = -1;		//Expected argument c to linear()
static intercepts linAns;		//Expected return form linear()

static int count = 0;		//Actual count of calls linear() made
static int flag = -1;
static float epsilon = -1;		//For prcision checking


//Initialize and expect one call to linear()
//Expecting argument 1b, 1c all to be within 1epsilon fo absolute error
//return result = linAns of type intercept
void mock_setup_linear(float tb, float tc, float tepsilon, intercepts tlinAns){
		eb = b;
		ec = c;
		epsilon = tepsilon;
		linAns = tlinAns;		//intercepts structs *
		count = 0;
		flag = 0;
}


//Compares if expected values are within one epsilon of test values.
//If one of them are not the flag is set.
intercepts linear(float tb, float tc){
		if(fabs(eb - tb) > epsilon) {        //Check if expected b is within 1 epsilon
				flag=1;       //If it is set the flag bit
		}
		b = tb;     //Set b to tb inputted by user
		if(fabs(ec - tc) > epsilon) {        //Check if expected c is within 1 epsilon
				flag=1;       //If it is set the flag bit
		}
		c = tc;     //Set c to tc inputted by user

		count++;        //Increment function call counter
		return linAns;   //Return from qsolve_sqrt(
}


// Returns 0 if the correct argument was passed and only one call was made.
// else there was a problem and retun 1.
int mock_check_linear(int *tcount, float *tb, float *tc){
		int	ret;        //initiate return value
		*tcount = count;    //Point tcount to count
		*tb = b;        //Point ta to b
		*tc = c;        //Point tc to c
		if((flag == 0) && (count==1)) {     //If no flag and the function was called
	  		ret = 0;      //WEre good
		} else {
	  		ret = 1;      //PROBLEM
		}
		return ret;
}


//Restore vars to default values
void mock_teardown_linear(){
		eb = -1;
		ec = -1;
		epsilon = -1.0;
		//linAns = -1.0;
		count = 0;
		flag  = -1;
		return ;
}
