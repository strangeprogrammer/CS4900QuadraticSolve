#include "headers.h"

int main(int argc,char* argv[]){
	checkargs(argc);
	float	a=getarg(argv[0]),
		b=getarg(argv[1]),
		c=getarg(argv[2]);
	checknums(a,b,c);
	exit(0);
}
