/*
* t2.c
* Unit tests parsing_getarg(char arg[])
* * Check if fpstatus.f(loat), .e(rror code)
*		variable returned from getarg is correct.
*/
#include <stdlib.h>
#include "../cunit.h"
#include "parsing.h"
#include <unistd.h>

int main() {

	int old_stdout = dup(1);
	fpstatus ret1, ret2, ret3, ret4, ret5, ret6, ret7, ret8, ret9;
	cunit_init();
	ret1 = getarg("0");		//Zero
	ret2 = getarg("1");		//int
	ret3 = getarg("-1");	//negative int
	ret4 = getarg("2.00");		//decimal
	ret5 = getarg("-2.00");		//negative decimal

	//ERRORS: (THEY PRINT AN ERROR MESSAGE THAT CANT BE SIPRESSED :(
	freopen ("/dev/null", "w", stderr); // Expected errors - send output(stderr) to devnull
	ret6 = getarg(".00000000000000000000000000000000000000000000043");   //Underflow x
	ret7 = getarg("100000000000000000000000000000000000000000000043");   //Overflow x
	ret8 = getarg("hello");    //Word x
	ret9 = getarg("nan");    //nan x
	fclose(stdout);
	stdout = fdopen(old_stdout, "w");	//Go back to old output

	assert_feqaerr("Zero", ret1.f, 0.0, 0.0000001);
	assert_feqaerr("int", ret2.f, 1.0, 0.0000001);
	assert_feqaerr("negative int", ret3.f, -1.0, 0.0000001);
	assert_feqaerr("decimal", ret4.f, 2.0, 0.0000001);
	assert_feqaerr("negative decimal", (double) ret5.f, -2.0, 0.0000001);
	assert_feqaerr("underflow", (double) ret6.e, 3.0, 0.0000001);
	assert_feqaerr("overflow", (double) ret7.e, 4.0, 0.0000001);
	assert_feqaerr("word", (double) ret8.e, 2.0, 0.0000001);
	assert_feqaerr("nan", (double) ret9.e, 5.0, 0.0000001);
}
