#include "headers.h"

void checkargs(int argc){
	if(argc!=4){
		fprintf(stderr,"Error: this program needs 3 arguments exactly.\n");
		exit(NUMARG_ERR);
	}
}

float getarg(char* arg){
	char** endptr;
	float retval=strtof(arg,endptr);
	if(retval==0||fplassify(retval)==FP_ZERO){
		if(*endptr==arg){
			fprintf(stderr,"Error: could not convert argument '%s' to a float.\n",arg);
			exit(BADARG_ERR);
		}else if(errno==ERANGE){
			fprintf(stderr,"Error: argument '%s' causes underflow.\n",arg);
			exit(UNDERFLOW_ERR);
		}
	}
	if(isinf(retval)==1){
		fprintf(stderr,"Error: argument '%s' causes positive overflow.\n",arg);
		exit(OVERFLOW_ERR);
	}else if(isnan(retval)){
		fprintf(stderr,"Error: argument '%s' is not a number.\n",arg);
		exit(NANARG_ERR);
	}
	return retval;
}
