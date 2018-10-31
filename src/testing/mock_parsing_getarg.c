// mock_parsing_getarg.c
// mock_parsing is a mock object for getarg()
// This allows:	--MODIFICATION HERE - everything below
//
// First called is:
// mock_setup_getarg():  currently allows only one x value at a time.
//
// Them call:
// getarg():  the mock_getarg() in this module.
//  It has the same signiture as the usual
//     getarg()
//
// Then call:
// mock_check_getarg():  to check for corectness of
//     the call to the mock_getarg()
//
// The mock getarg() does keep track of the number of times
//    it is called, which should only be 1.

#include "mock_parsing_getarg.h"
#include "../libraries.h"

static char arg[1];		//Actual arguments passed to getarg()
static char earg[1];		//Expected argument a to getarg()
static fpstatus getargAns = {.f=0,.e=SUCCESS};		//Expected return form getarg()
static int count = 0;		//Actual count of calls getarg() made
static int flag = -1;
static float epsilon = -1;		//For prcision checking


//Initialize and expect one call to mock_getarg()
//Expecting argument tgetargAns all to be within 1epsilon fo absolute error
//return result = getargAns of type fpstatus
void mock_setup_getarg(char targ[], float tepsilon, fpstatus tgetargAns){
    earg[0] = arg[0];		//Set expected argument array equal to arf[]
    epsilon = tepsilon;
    getargAns.f = tgetargAns.f;		//fpstatus structs - f->float, e->errarg
    count = 0;
    flag = 0;
}


//Compares if expected values are within one epsilon of test values.
//If one of them are not the flag is set.
fpstatus getarg(char targ[]){
    if(labs(earg - targ) > epsilon) {        //Check if expected a is within 1 epsilon
        flag=1;       //If it is set the flag bit
    }
    arg[0] = targ[0];		//Set arg to targ inputted by user
    count++;        //Increment function call counter
    return getargAns;   //Return from getarg()
}


// Returns 0 if the correct argument was passed and only one call was made.
// else there was a problem and retun 1.
int mock_check_getarg(int *tcount, char *targ){
    int	ret;        //initiate return value
    *tcount = count;    //Point tcount to count
		targ[0]=arg[0];		//Set targ to arg
    if((flag == 0) && (count==1)) {     //If no flag and the function was called
        ret = 0;      //WEre good
    } else {
        ret = 1;      //PROBLEM
    }
    return ret;
}


//Restore vars to default values
void mock_teardown_getarg(){
    earg[0] = -1.0;
    epsilon = -1.0;
    getargAns.f = -1.0;
    count = 0;
    flag  = -1;
    return ;
}
