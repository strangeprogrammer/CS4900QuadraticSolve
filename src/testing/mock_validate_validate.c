// mock_validate_validate.c
// mock_validate is a mock object for validate()
// This allows:	--MODIFICATION HERE - everything below
//
// First called is:
// mock_setup_validate():  currently allows only one x value at a time.
//
// Them call:
// validate():  the mock validate() in this module.
//  It has the same signiture as the usual
//     validate()
//
// Then call:
// mock_check_validate():  to check for corectness of
//     the call to the mock_validate()
//
// The mock validate() does keep track of the number of times
//    it is called, which should only be 1.

#include "mock_validate_validate.h"
#include "../libraries.h"

static float a = -1;		//Actual arguments passed to validate()
static float b = -1;
static float c = -1;
static intercepts x = {.low=-1, .high=-1, .numroots=-1};

static float ea = -1;		//Expected argument a to validate()
static float eb = -1;
static float ec = -1;
static intercepts ex = {.low=-1, .high=-1, .numroots=-1};
static bool validateAns= false;		//Expected return form validate()

static int count = 0;		//Actual count of calls validate() made
static int flag = -1;
static float epsilon = -1;		//For prcision checking


//Initialize and expect one call to mock_validate()
//Expecting argument ta, tb, tc all to be within 1epsilon fo absolute error
//return result = quadAns of type intercept
void mock_setup_validate(float ta, float tb, float tc, intercepts tx, float tepsilon, bool tvalidateAns){
    ea = a;
    eb = b;
    ec = c;
    ex.low = x.low;
    ex.high = x.high;
    ex.numroots = x.numroots;
    epsilon = tepsilon;
    validateAns = tvalidateAns;
    count = 0;
    flag = 0;
}


//Compares if expected values are within one epsilon of test values.
//If one of them are not the flag is set.
bool validate(float ta, float tb, float tc, intercepts tx){
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
    if(fabs(ex.low - tx.low) > epsilon)
        flag=1;
    x.low = tx.low;
    if(fabs(ex.high - tx.high) > epsilon)
        flag=1;
    x.high = tx.high;
    if((ex.numroots - tx.numroots) > epsilon)
        flag=1;
    x.numroots = tx.numroots;
    count++;        //Increment function call counter
    return validateAns;   //Return from qsolve_sqrt(
}


// Returns 0 if the correct argument was passed and only one call was made.
// else there was a problem and retun 1.
int mock_check_validate(int *tcount, float *ta, float *tb, float *tc, intercepts *tx){
    int	ret;        //initiate return value
    *tcount = count;    //Point tcount to count
    *ta = a;        //Point ta to a
    *tb = b;        //Point ta to b
    *tc = c;        //Point tc to c
    tx->low = x.low;
    tx->high = x.high;
    tx->numroots = x.numroots;
    if((flag == 0) && (count==1)) {     //If no flag and the function was called
        ret = 0;      //WEre good
    } else {
        ret = 1;      //PROBLEM
    }
    return ret;
}


//Restore vars to default values
void mock_teardown_validate(){
    ea = -1.0;
    eb = -1;
    ec = -1;
    ex.low = -1;
    ex.high = -1;
    ex.numroots = -1;
    epsilon = -1.0;
    validateAns = false;
    count = 0;
    flag  = -1;
    return ;
}
