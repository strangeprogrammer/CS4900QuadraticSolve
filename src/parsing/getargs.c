#include "../misc.h"
#include "getarg.h"
#include "prompt.h"
#include "getargs.h"

//Get all the arguments from standard input for the program
err_code getargs(float* a,float* b,float* c){
	err_code passup;
	
	//Takes advantage of short-circuit evaluation
	//If any one of the 'getargs' doesn't work properly, return its error
	if((prompt(1)&&(passup=getarg(a))!=SUCCESS)
	||(prompt(2)&&(passup=getarg(b))!=SUCCESS)
	||(prompt(3)&&(passup=getarg(c))!=SUCCESS)){
		return passup;
	}
	
	return SUCCESS;
}
