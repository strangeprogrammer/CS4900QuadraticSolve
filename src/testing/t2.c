/*
* t2.c
* Unit tests getarg(char arg[])
* * Check if fpstatus.f(loat), .e(rror code)
*		variable returned from getarg is correct.
*/

#include <stdlib.h>
#include "cunit.h"
#include "../parsing/parsing.h"

int main() {

	fpstatus ret1, ret2, ret3, ret4, ret5, ret6, ret7, ret8, ret9;
	cunit_init();
	ret1 = getarg("0");		//Zero
	ret2 = getarg("1");		//int
	ret3 = getarg("-1");	//negative int
	ret4 = getarg("2.00");		//decimal
	ret5 = getarg("-2.00");		//negative decimal
	//ERRORS: (THEY PRINT AN ERROR MESSAGE THAT CANT BE SIPRESSED :(
	ret6 = getarg(".00000000000000000000000000000000000000000000043");   //Underflow x
	ret7 = getarg("100000000000000000000000000000000000000000000043");   //Overflow x
	ret8 = getarg("hello");    //Word x
	ret9 = getarg("nan");          //nan x

	assert_feqrerr("Zero", ret1.f, 0.0, 0.0000001);
	assert_feqrerr("int", ret2.f, 1.0, 0.0000001);
	assert_feqrerr("negative int", ret3.f, -1.0, 0.0000001);
	assert_feqrerr("decimal", ret4.f, 2.0, 0.0000001);
	assert_feqrerr("negative decimal", ret5.f, -2.0, 0.0000001);
	assert_feqrerr("underflow", ret6.f, 0.0, 0.0000001);
	assert_feqrerr("overflow", ret7.f, 0.0, 0.0000001);
	assert_feqrerr("word", ret8.f, 0.0, 0.0000001);
	assert_feqrerr("nan", ret9.f, 0.0, 0.0000001);

	printf("\nIF T2 RAN CORRECTLY THERE SHOULD BE 4 ERROR MESSAGES^^^^\n");	//NO AVOIDING

}
