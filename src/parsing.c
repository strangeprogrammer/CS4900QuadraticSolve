#include "headers.h"

void checkargs(int argc){
	if(argc!=4){
		fprintf(stderr,"Error: this program needs 3 arguments exactly.");
		exit(1);
	}
}

float getarg(char* arg){
	char** endptr;
	float retval=strtof(arg,endptr);
	if(retval==0||fplassify(retval)==FP_ZERO){
		if(errno==ERANGE){
			fprintf(stderr,"Error: argument '%s' causes underflow.",arg);
			exit(2);
		}else if(*endptr==arg){
			fprintf(stderr,"Error: could not convert argument '%s' to a float.",arg);
			exit(3);
		}
	}
	if(retval==HUGE_VALF||isinf(retval)==1){
		fprintf(stderr,"Error: argument '%s' causes positive overflow.",arg);
		exit(4);
	}else if(retval==HUGE_VALL||isinf(retval)==-1){
		fprintf(stderr,"Error: argument '%s' causes negative overflow.",arg);
		exit(5);
	}else if(isnan(retval)){
		fprintf(stderr,"Error: argument '%s' is not a number.",arg);
		exit(6);
	}
	return retval;
}
