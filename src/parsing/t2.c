/*
* t2.c
* Unit tests parsing_getarg(char arg[])
* * Check if fpstatus.f(loat), .e(rror code)
*		variable returned from getarg is correct.
*/
#include "../libraries.h"
#include "../misc.h"
#include "../cunit.h"
#include "parsing.h"

//NOTE: There are some compiling warnings that are *really* hard to remove regarding the declaration of 'fdopen' and 'fileno' (though this doesn't impact functionality)

int main(){
	cunit_init();
	
	//Test working functionality
	fpstatus ret1, ret2, ret3, ret4, ret5;
	ret1 = getarg("0");	//Zero
	ret2 = getarg("1");	//int
	ret3 = getarg("-1");	//negative int
	ret4 = getarg("2.00");	//decimal
	ret5 = getarg("-2.00");	//negative decimal
	assert_feqaerr("zero",			ret1.f, 0.0,  0.0000001);
	assert_eq("zero",			ret1.e, SUCCESS);
	assert_feqaerr("int",			ret2.f, 1.0,  0.0000001);
	assert_eq("int",			ret1.e, SUCCESS);
	assert_feqaerr("negative int",		ret3.f, -1.0, 0.0000001);
	assert_eq("negative int",		ret1.e, SUCCESS);
	assert_feqaerr("decimal",		ret4.f, 2.0,  0.0000001);
	assert_eq("decimal",			ret1.e, SUCCESS);
	assert_feqaerr("negative decimal",	ret5.f, -2.0, 0.0000001);
	assert_eq("negative decimal",		ret1.e, SUCCESS);
	
	//Test error handling
	fpstatus ret6, ret7, ret8, ret9;
	//These tests' expected errors are suppressed by sending the output to '/dev/null'
	int old_stderr = dup(fileno(stderr));
	freopen("/dev/null", "w", stderr);
	assert_eq("checkargs not working properly",checkargs(0),false);
	assert_eq("checkargs not working properly",checkargs(1),false);
	assert_eq("checkargs not working properly",checkargs(2),false);
	assert_eq("checkargs not working properly",checkargs(3),false);
	assert_eq("checkargs not working properly",checkargs(4),true);
	assert_eq("checkargs not working properly",checkargs(5),false);
	ret6 = getarg(".00000000000000000000000000000000000000000000043");   //Underflow x
	ret7 = getarg("100000000000000000000000000000000000000000000043");   //Overflow x
	ret8 = getarg("hello");		//Word x
	ret9 = getarg("nan");		//nan x
	//Go back to old output
	fclose(stderr);
	stderr = fdopen(old_stderr, "w");
	//Check err_code values
	assert_eq("underflow",			ret6.e, UNDERFLOW_ERR);
	assert_eq("overflow",			ret7.e, OVERFLOW_ERR);
	assert_eq("word",			ret8.e, BADARG_ERR);
	assert_eq("nan",			ret9.e, NANARG_ERR);
}
