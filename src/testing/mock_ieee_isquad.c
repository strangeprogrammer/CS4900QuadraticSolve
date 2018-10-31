// mock_ieee_isquad.c
// mock_isquad is a mock object for isquad()
// This allows:	--MODIFICATION HERE - everything below
//
// First called is:
// mock_setup_isquad():  currently allows only one x value at a time.
//
// Them call:
// isquad():  the mock isquad() in this module.
//  It has the same signiture as the usual
//     isquad()
//
// Then call:
// mock_check_isquad():  to check for corectness of
//     the call to the mock_isquad()
//
// The mock isquad() does keep track of the number of times
//    it is called, which should only be 1.

#include "mock_ieee_isquad.h"
#include "../libraries.h"

static float a = -1;		//Actual arguments passed to isquad()
static float b = -1;
static float c = -1;

static float ea = -1;		//Expected argument a to isquad()
static float eb = -1;
static float ec = -1;
static bool isquadAns= false;		//Expected return form isquad()

static int count = 0;		//Actual count of calls isquad() made
static int flag = -1;
static float epsilon = -1;		//For prcision checking


//Initialize and expect one call to mock_isquad()
//Expecting argument ta, tb, tc all to be within 1epsilon fo absolute error
//return result = quadAns of type intercept
void mock_setup_isquad(float ta, float tb, float tc, float tepsilon, bool tisquadAns){
    ea = a;
    eb = b;
    ec = c;
    epsilon = tepsilon;
    isquadAns = tisquadAns;
    count = 0;
    flag = 0;
}


//Compares if expected values are within one epsilon of test values.
//If one of them are not the flag is set.
bool isquad(float ta, float tb, float tc){
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

    count++;        //Increment function call counter
    return isquadAns;   //Return from qsolve_sqrt(
}


// Returns 0 if the correct argument was passed and only one call was made.
// else there was a problem and retun 1.
int mock_check_isquad(int *tcount, float *ta, float *tb, float *tc){
    int	ret;        //initiate return value
    *tcount = count;    //Point tcount to count
    *ta = a;        //Point ta to a
    *tb = b;        
    *tc = c;
    if((flag == 0) && (count==1)) {     //If no flag and the function was called
        ret = 0;      //WEre good
    } else {
        ret = 1;      //PROBLEM
    }
    return ret;
}


//Restore vars to default values
void mock_teardown_isquad(){
    ea = -1.0;
    eb = -1;
    ec = -1;
    epsilon = -1.0;
    isquadAns = false;
    count = 0;
    flag  = -1;
    return ;
}
