#include "libraries.h"
#include "err_codes.h"
#include "misc.h"
#include "parsing.h"
#include "testing.h"
#include "ieee.h"

int main(int argc,char* argv[]){
	checkargs(argc);
	float	a=getarg(argv[1]),
		b=getarg(argv[2]),
		c=getarg(argv[3]);
	if(isquad(a,b,c)){
		//Treat the input as a quadratic
	}else{
		fprintf(stderr,"Warning: The input given is being interpreted as a linear equation instead of a quadratic one.\n");
		//Treat the input as a line
	}

	//tests
	testGetArg();
	testCheckArgs();
	testFeq();
	testIsQuad();
	exit(SUCCESS);
}
