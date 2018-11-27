#include "../libraries.h"
#include "../misc.h"
#include "getarg.h"
#include "../cunit/cunit.h"

int main(){
	cunit_init();
	
	float dropbox;
	
	assert_eq("Getarg didn't return successfully",getarg(&dropbox),SUCCESS);
	assert_eq("Getarg didn't fail correctly",getarg(&dropbox),NOARG_ERR);
	assert_eq("Getarg didn't fail correctly",getarg(&dropbox),NOARG_ERR);
	
	//What input do we use to make the following type of test?
	//assert_eq("Getarg didn't return successfully",getarg(&dropbox),INTERNAL_ERR);
	
	return 0;
}
