#include "../libraries.h"
#include "../misc.h"
#include "convert.h"
#include "../cunit/cunit.h"

int main(){
	cunit_init();
	
	float dropbox;
	
	//Active High Tests
	assert_eq("Couldn't convert string successfully",convert("1234",4,&dropbox),SUCCESS);
	assert_feqrerr("Wrong floating point number returned",dropbox,1234,0.00001);
	assert_eq("Couldn't convert string successfully",convert(".56789",6,&dropbox),SUCCESS);
	assert_feqrerr("Wrong floating point number returned",dropbox,.56789,0.00001);
	assert_eq("Couldn't convert string successfully",convert("01234.",6,&dropbox),SUCCESS);
	assert_feqrerr("Wrong floating point number returned",dropbox,1234,0.00001);
	assert_eq("Couldn't convert string successfully",convert("01234.56789",11,&dropbox),SUCCESS);
	assert_feqrerr("Wrong floating point number returned",dropbox,01234.56789,0.00001);
	
	//Active Low Tests
	assert_eq("Couldn't reject string properly",convert("gib ber ish",11,&dropbox),BADARG_ERR);
	assert_eq("Couldn't reject string properly",convert("1e-38",5,&dropbox),UNDERFLOW_ERR);
	assert_eq("Couldn't reject string properly",convert("1e256",5,&dropbox),OVERFLOW_ERR);
	assert_eq("Couldn't reject string properly",convert("inf",3,&dropbox),OVERFLOW_ERR);
	assert_eq("Couldn't reject string properly",convert("nan",3,&dropbox),NANARG_ERR);
	
	return 0;
}
