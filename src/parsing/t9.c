#include "../libraries.h"
#include "../misc.h"
#include "getargs.h"
#include "../cunit/cunit.h"

int main(){
	cunit_init();
	
	float	dummya,
		dummyb,
		dummyc;
	
	assert_eq("\'getargs\' should've failed",getargs(&dummya,&dummyb,&dummyc),NOARG_ERR);
	assert_eq("\'getargs\' should've failed",getargs(&dummya,&dummyb,&dummyc),BADARG_ERR);
	assert_eq("\'getargs\' should've failed", getargs(&dummya,&dummyb,&dummyc),UNDERFLOW_ERR);
	assert_eq("\'getargs\' should've succeeded", getargs(&dummya,&dummyb,&dummyc),SUCCESS);
	
	return 0;
}
