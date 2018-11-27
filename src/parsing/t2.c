/*
* t2.c
* Unit tests parsing_getarg(char arg[])
* * Check if fpstatus.f(loat), .e(rror code)
*		variable returned from getarg is correct.
*/
#include "../libraries.h"
#include "../misc.h"
#include "../cunit/cunit.h"
#include "parsing.h"

struct fpstatus{
	float f;
	err_code e;
} fpstatus;

//NOTE: There are some compiling warnings that are *really* hard to remove regarding the declaration of 'fdopen' and 'fileno' (though this doesn't impact functionality)

int main(){
	cunit_init();
	
	//Test working functionality
	fpstatus ret1, ret2, ret3, ret4, ret5;
	ret1.e = getarg("0",&ret1.f);		//Zero
	ret2.e = getarg("1",&ret2.f);		//int
	ret3.e = getarg("-1",&ret3.f);		//negative int
	ret4.e = getarg("2.00",&ret4.f);	//decimal
	ret5.e = getarg("-2.00",&ret5.f);	//negative decimal
	assert_feqaerr("zero",ret1.f, 0.0, 0.0000001);
	assert_eq("zero",ret1.e, SUCCESS);
	assert_feqaerr("int",ret2.f, 1.0, 0.0000001);
	assert_eq("int",ret1.e, SUCCESS);
	assert_feqaerr("negative int",ret3.f, -1.0, 0.0000001);
	assert_eq("negative int",ret1.e, SUCCESS);
	assert_feqaerr("decimal",ret4.f, 2.0, 0.0000001);
	assert_eq("decimal",ret1.e, SUCCESS);
	assert_feqaerr("negative decimal",ret5.f, -2.0, 0.0000001);
	assert_eq("negative decimal",ret1.e, SUCCESS);
	
	//Test error handling
	//These tests' expected errors are suppressed by sending the output to '/dev/null'
	int old_stderr = dup(fileno(stderr));
	freopen("/dev/null", "w", stderr);
	assert_eq("checkargs not working properly",checkargs(0),false);
	assert_eq("checkargs not working properly",checkargs(1),false);
	assert_eq("checkargs not working properly",checkargs(2),false);
	assert_eq("checkargs not working properly",checkargs(3),false);
	assert_eq("checkargs not working properly",checkargs(4),true);
	assert_eq("checkargs not working properly",checkargs(5),false);
	fpstatus ret6, ret7, ret8, ret9;
	ret6.e = getarg(".00000000000000000000000000000000000000000000043",&ret6.f);   //Underflow x
	ret7.e = getarg("100000000000000000000000000000000000000000000043",&ret7.f);   //Overflow x
	ret8.e = getarg("hello",&ret8.f);		//Word x
	ret9.e = getarg("nan",,&ret9.f);		//nan x
	//Go back to old output
	fclose(stderr);
	stderr = fdopen(old_stderr, "w");
	//Check err_code values
	assert_eq("underflow",ret6.e, UNDERFLOW_ERR);
	assert_eq("overflow",ret7.e, OVERFLOW_ERR);
	assert_eq("word",ret8.e, BADARG_ERR);
	assert_eq("nan",ret9.e, NANARG_ERR);
}
