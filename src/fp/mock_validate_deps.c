#include "../misc.h"
#include "quadfunc.h"
#include "ieee.h"
#include "validate.h"
#include "../cunit/cunit.h"

static int count_feq=0;

float quadfunc(float a,float b,float c,float x){
	//Don't need to provide an actual implementation of this as it turns out
	return 4;//Got this random number from wolfram alpha
}

bool feq(float a,float b){
	bool retval;
	switch(count_feq){
	//TEST NUMROOTS=1
	//Test 3
	case 0:
		retval=true;
		break;
	//Test 4
	case 1:
		retval=false;
		break;
	//Test 5
	case 2:
		retval=true;
		break;
	//Test 6
	case 3:
		retval=true;
		break;
	//Test 7
	case 4:
		retval=false;
		break;
	//TEST NUMROOTS=2
	//Test 8
	case 5:
		retval=true;
		break;
	//Test 8
	case 6:
		retval=true;
		break;
	//Test 9
	case 7:
		retval=true;
		break;
	//Test 9
	case 8:
		retval=true;
		break;
	//Test 10
	case 9:
		retval=false;
		break;
	//Test 10
	case 10:
		retval=false;
		break;
	default:
		cunit_print("Error: feq was called more times than it was supposed to be");
		retval=false;
		break;
	}
	count_feq++;
	return retval;
}
