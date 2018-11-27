#include "../libraries.h"
#include "../misc.h"
#include "getarg.h"
#include "../cunit/cunit.h"

static int invocation=0;

err_code getarg(float* dropbox){
	assert_gt("\'getarg\' shouldn't be invoked fewer than 0 times",invocation,-1);
	assert_lt("\'getarg\' shouldn't be invoked more than 0 times",invocation,9);
	switch(invocation++){
	//Fail immediately
	case 0:
		return NOARG_ERR;
		break;
	//Fail after 1 success
	case 1:
		return SUCCESS;
		break;
	case 2:
		return BADARG_ERR;
		break;
	//Fail after 2 successes
	case 3:
		return SUCCESS;
		break;
	case 4:
		return SUCCESS;
		break;
	case 5:
		return UNDERFLOW_ERR;
		break;
	//Succees
	case 6:
		return SUCCESS;
		break;
	case 7:
		return SUCCESS;
		break;
	case 8:
		return SUCCESS;
		break;
	}
	return SUCCESS;
}
