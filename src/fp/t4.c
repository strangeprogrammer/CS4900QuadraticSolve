#include "../cunit/cunit.h"
#include "quadfunc.h"

int main(){
	cunit_init();//Initialize testing framework
    
	assert_feqaerr("Wrong value for quadfunc",quadfunc(0,0,0,0),(double)0,	0.0000000000000000000000000000000000000000000000001);
	assert_feqaerr("Wrong value for quadfunc",quadfunc(1,1,1,1),(double)3,	0.0000000000000000000000000000000000000000000000001);
	assert_feqaerr("Wrong value for quadfunc",quadfunc(1,2,3,4),(double)27,	0.0000000000000000000000000000000000000000000000001);
	assert_feqaerr("Wrong value for quadfunc",quadfunc(4,3,2,1),(double)9,	0.0000000000000000000000000000000000000000000000001);
	assert_feqaerr("Wrong value for quadfunc",quadfunc(-1,-1,-1,-1),(double)-1,	0.0000000000000000000000000000000000000000000000001);
	assert_feqaerr("Wrong value for quadfunc",quadfunc(-1,-2,-3,-4),(double)-11,	0.0000000000000000000000000000000000000000000000001);
	assert_feqaerr("Wrong value for quadfunc",quadfunc(-4,-3,-2,-1),(double)-3,	0.0000000000000000000000000000000000000000000000001);
    return 0;
}
