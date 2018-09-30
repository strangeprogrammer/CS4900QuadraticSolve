#include "headers.h"

int main(int argc,char* argv[]){
	checkargs(argc);
	float	a=getarg(argv[0]),
		b=getarg(argv[1]),
		c=getarg(argv[2]);
	if(isquad(a,b,c)){
		//Treat the input as a quadratic
	}else{
		fprintf(stderr,"Warning: The input given is being interpreted as a linear equation instead of a quadratic one.\n");
		//Treat the input as a line
	}
	exit(SUCCESS);
}
