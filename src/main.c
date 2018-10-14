#include "libraries.h"
#include "misc.h"
#include "parsing.h"
#include "ieee.h"
#include "linear.h"
#include "quadratic.h"
#include "validate.h"

int main(int argc,char* argv[]){
	if(!checkargs(argc)){
		return NUMARG_ERR;
	}
	fpstatus a=getarg(argv[1]);
	if(a.e)
		return a.e;
	fpstatus b=getarg(argv[2]);
	if(b.e)
		return b.e;
	fpstatus c=getarg(argv[3]);
	if(c.e)
		return c.e;
	intercepts x={
		.low=0,
		.high=0,
		.numroots=0
	};
	if(isquad(a.f,b.f,c.f)){
		x=quadratic(a.f,b.f,c.f);
	}else{
		fprintf(stderr,"Warning: The input given is being interpreted as a linear equation instead of a quadratic one.\n");
		x=linear(b.f,c.f);
	}
	switch(x.numroots){
	case 0:
		printf("There are 0 x-intercepts.\n");
		break;
	case 1:
		printf("There is 1 x-intercept: %f\n",x.low);
		break;
	case 2:
		printf("There are 2 x-intercepts: %f, %f\n",x.low,x.high);
		break;
	}
	if(x.numroots&&
	!validate(a.f,b.f,c.f,x)){
		fprintf(stderr,"Warning: The input given does not solve the answer with a precision of '0.0001'.\n");
	}
	return SUCCESS;
}
