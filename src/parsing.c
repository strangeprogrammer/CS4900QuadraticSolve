#include "headers.h"

void checkargs(int argc){
	if(argc!=4){
		printf("Error: this program needs 3 arguments exactly.");
		exit(1);
	}
}

float getarg(char* arg){
	char** endptr;
	float retval=strtof(arg,endptr);
	if(retval==0){
		if(errno==ERANGE){
			printf("Error: float '%s' causes underflow.",arg);
			exit(2);
		}else if(*endptr==arg){
			printf("Error: could not convert string '%s' to a float.",arg);
			exit(3);
		}
	}
	if(retval==HUGE_VALF){
		printf("Error: float '%s' causes positive overflow.",arg);
		exit(4);
	}else if(retval==HUGE_VALL){
		printf("Error: float '%s' causes negative overflow.",arg);
		exit(5);
	}
	return retval;
}
