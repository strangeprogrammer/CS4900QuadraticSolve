// mock_ieee_feq.c
// mock_ieee_feq is a mock object for feq()
// This allows:	--MODIFICATION HERE - everything below
//
// First called is:
// mock_setup_ieee_feq():  currently allows only one x value at a time.
//
// Them call:
// feq():  the mock feq() in this module.
//  It has the same signiture as the usual
//     feq()
//
// Then call:
// mock_check_ieee_feq():  to check for corectness of
//     the call to the mock_ieee_feq()
//
// The mock feq() does keep track of the number of times
//    it is called, which should only be 1.

#include "../libraries.h"
#include "../misc.h"
#include "mock_ieee_feq.h"

static float b = -1;		//Actual arguments passed to feq(
static float c = -1;

static float eb = -1;		//Expected argument b to feq()
static float ec = -1;
static bool feqAns = false;		//Expected return form feq()

static int count = 0;		//Actual count of calls feq() made
static int flag = -1;
static float epsilon = -1;		//For prcision checking


//Initialize and expect one call to feq()
//Expecting argument 1b, 1c all to be within 1epsilon fo absolute error
//return result = linAns of type intercept
void mock_setup_feq(float tb, float tc, float tepsilon, bool tfeqAns){
    eb = b;
    ec = c;
    epsilon = tepsilon;
    feqAns = tfeqAns;
    count = 0;
    flag = 0;
}


//Compares if expected values are within one epsilon of test values.
//If one of them are not the flag is set.
bool feq(float tb, float tc){
    if(fabs(eb - tb) > epsilon) {        //Check if expected b is within 1 epsilon
        flag=1;       //If it is set the flag bit
    }
    b = tb;     //Set b to tb inputted by user
    if(fabs(ec - tc) > epsilon) {        //Check if expected c is within 1 epsilon
        flag=1;       //If it is set the flag bit
    }
    c = tc;     //Set c to tc inputted by user

    count++;        //Increment function call counter
    return feqAns;   //Return from qsolve_sqrt(
}


// Returns 0 if the correct argument was passed and only one call was made.
// else there was a problem and retun 1.
int mock_check_feq(int *tcount, float *tb, float *tc){
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
void mock_teardown_feq(){
    eb = -1;
    ec = -1;
    epsilon = -1.0;
    feqAns = false;
    count = 0;
    flag  = -1;
    return ;
}
