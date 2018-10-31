// mock_validate_quadfunc.c
// mock_quadfunc is a mock object for quadfunc()
// This allows:	--MODIFICATION HERE - everything below
//
// First called is:
// mock_setup_quadrati():  currently allows only one x value at a time.
//
// Them call:
// quadfunc():  the mock quadric() in this module.
//  It has the same signiture as the usual
//     quadfunc()
//
// Then call:
// mock_check_quadfunc():  to check for corectness of
//     the call to the mock_quadfunc()
//
// The mock quadfunc() does keep track of the number of times
//    it is called, which should only be 1.

#include "mock_validate_quadfunc.h"
#include "../libraries.h"

static float a = -1;		//Actual arguments passed to quadfunc()
static float b = -1;
static float c = -1;
static float x = -1;

static float ea = -1;		//Expected argument a to quadfunc()
static float eb = -1;
static float ec = -1;
static float ex = -1;
static float quadfuncAns = -1;		//Expected return form quadfunc()

static int count = 0;		//Actual count of calls quadfunc() made
static int flag = -1;
static float epsilon = -1;		//For prcision checking


//Initialize and expect one call to mock_quadfunc()
//Expecting argument ta, tb, tc, tx all to be within 1epsilon fo absolute error
//return result = quadfuncAns of type float
void mock_setup_quadfunc(float ta, float tb, float tc, float tx, float tepsilon, float tquadfuncAns{
    ea = a;
    eb = b;
    ec = c;
    ex = x;
    epsilon = tepsilon;
    quadfuncAns = tquadfuncAns;
    count = 0;
    flag = 0;
}


//Compares if expected values are within one epsilon of test values.
//If one of them are not the flag is set.
float quadfunc(float ta, float tb, float tc, float tx){
    if(fabs(ea - ta) > epsilon) {        //Check if expected a is within 1 epsilon
        flag=1;       //If it is set the flag bit
    }
    a = ta;     //Set a to ta inputted by user
    if(fabs(eb - tb) > epsilon) {        //Check if expected b is within 1 epsilon
        flag=1;       //If it is set the flag bit
    }
    b = tb;     //Set b to tb inputted by user
    if(fabs(ec - tc) > epsilon) {        //Check if expected c is within 1 epsilon
        flag=1;       //If it is set the flag bit
    }
    c = tc;     //Set c to tc inputted by user
    if(fabs(ex - tx) > epsilon) {        //Check if expected c is within 1 epsilon
        flag=1;       //If it is set the flag bit
    }
    x = tx;     //Set x to tx inputted by user

    count++;        //Increment function call counter
    return quadfuncAns;   //Return from qsolve_sqrt(
}


// Returns 0 if the correct argument was passed and only one call was made.
// else there was a problem and retun 1.
int mock_check_quadfunc(int *tcount, float *ta, float *tb, float *tc, float *tx){
    int	ret;        //initiate return value
    *tcount = count;    //Point tcount to count
    *ta = a;        //Point ta to a
    *tb = b;
    *tc = c;        
		*tx = x;
    if((flag == 0) && (count==1)) {     //If no flag and the function was called
        ret = 0;      //WEre good
    } else {
        ret = 1;      //PROBLEM
    }
    return ret;
}


//Restore vars to default values
void mock_teardown_quadfunc(){
    ea = -1.0;
    eb = -1;
    ec = -1;
    ex = -1;
    epsilon = -1.0;
    quadfuncAns = -1;
    count = 0;
    flag  = -1;
    return ;
}
