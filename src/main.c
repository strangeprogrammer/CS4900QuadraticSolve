#include "libraries.h"
#include "err_codes.h"
#include "misc.h"
#include "parsing.h"
#include "testing.h"
#include "ieee.h"
#include "quadratic.h"
#include "validate.h"

int main(int argc,char* argv[]){
	checkargs(argc);
	float	a=getarg(argv[1]),
		b=getarg(argv[2]),
		c=getarg(argv[3]);
	intercepts x={
		.low=0,
		.high=0,
		.numroots=0
	};
	if(isquad(a,b,c)){
		x=quadratic(a,b,c);
	}else{
		fprintf(stderr,"Warning: The input given is being interpreted as a linear equation instead of a quadratic one.\n");
		//Treat the input as a line
	}
	switch(x.numroots){
	case 0:
		printf("There are 0 x-intercepts.\n");
	case 1:
		printf("There is 1 x-intercept: %f\n",x.low);
	case 2:
		printf("There are 2 x-intercepts: %f, %f\n",x.low,x.high);
	}
	if(x.numroots&&
	!validate(a,b,c,x)){
		fprintf(stderr,"Warning: The input given does not solve the answer with a precision of '0.0001'.\n");
	}
	exit(SUCCESS);
}
