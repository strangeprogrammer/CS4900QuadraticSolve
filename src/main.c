#include "libraries.h"
#include "misc.h"

#include "fp/ieee.h"
#include "fp/validate.h"
#include "parsing/getargs.h"
#include "solver/linear.h"
#include "solver/quadratic.h"

int main(){
	//Disable output buffering
	//https://stackoverflow.com/a/7876756
	setvbuf(stdout,NULL,_IONBF,0);
	
	//Get input values
	float a,b,c;
	err_code argstatus=getargs(&a,&b,&c);
	if(argstatus!=SUCCESS){
		fprintf(stderr,"%s",err_str[argstatus]);
		return argstatus;
	}
	
	//Try to perform quadratic solve
	intercepts x={
		.low=0,
		.high=0,
		.numroots=0
	};
	//Switch upon quadratic/linear
	if(isquad(a,b,c)){
		x=quadratic(a,b,c);
	}else{
		fprintf(stderr,"Warning: The input given is being interpreted as a linear equation instead of a quadratic one.\n");
		x=linear(b,c);
	}
	
	//Give different output based on number of roots
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
	
	//Throw a warning if the solutions aren't accurate enough
	if(x.numroots&&
	!validate(a,b,c,x)){
		fprintf(stderr,"Warning: The input given does not solve the answer with a precision of '0.0001'.\n");
	}
	
	return SUCCESS;
}
