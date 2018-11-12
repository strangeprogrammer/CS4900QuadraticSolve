// mock_validate_feq.c
// mock_validate_feq is a mock object for feq()
// This allows:
//   testing of the validate() with a mock object,
//
// First called is:
// mock_setup_validate_feq(): currently allows only one bool value at a time.
//
// Then call :
// feq(): the mock feq() in this module has the same signiture as the usual
//     feq()
//
// Then call
// mock_check_validate_feq():  to check for corectness of
//     the call to the mock feq()
//
// The mock feq() does keep track of the number of times
//    it is called, which should only be 1.

#include "../libraries.h"
#include "mock_validate_feq.h"
#include "ieee.h"
#include "../misc.h"


static float x = -1.0;		//actual argument x passed to  feq()
static float y = -1.0;		//actual argument y passed to feq()
static float ex = -1.0;		//expected argument x to feq()
static float ey = -1.0;		//expected argument y to feq()
static double eps = -1.0;	//absolure error allowed in x
static bool feqxy = false;	//result to return from feq()
static int count = 0;		//actual count of calls feq() made
static int flag = -1;

// initialize to expect 1 call to the mock feq()
// expecting arguement lx within leps absolute error
// return    result    lfeqxy
void mock_setup_validate_feq(float lx, float ly, bool lfeqxy, double leps){
	ex = lx;
	ey = ly;
	eps = leps;
	feqxy = lfeqxy;
	count = 0;
	flag = 0;
}

bool feq(float lx, float ly){
	if(fabs(ex-lx) > eps){
		flag = 1;
	}
	x = lx;
	if(fabs(ey-ly) > eps){
		flag = 1;
	}
	y = ly;
	count++;
	return feqxy;
}

//Returns 0 if the correct argument was passed and only one call was made
//else there was a problem and return 1
int mock_check_validate_feq(int *lcount, float *lx, float *ly){
	int ret;
	*lcount = count;
	*lx = x;
	*ly = y;
	if((flag == 0) && (count == 1)){
		ret = 0;
	}
	else{
		ret = 1;
	}
	return ret;
}

//Tear down for another test
void mock_validate_feq_init(){
	x = -1.0;
	y = -1.0;
	mock_setup_validate_feq(-1.0,-1.0,false,-1.0);
	flag = -1;
	return;
}
