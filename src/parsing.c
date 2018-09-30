#include "libraries.h"
#include "err_codes.h"
#include "parsing.h"

void checkargs(int argc){
	if(argc!=4){
		fprintf(stderr,"Error: this program needs 3 arguments exactly.\n");
		exit(NUMARG_ERR);
	}
}

float getarg(char arg[]){
	char* end;
	errno=0;
	float retval=strtof(arg,&end);
	if(retval==0||fpclassify(retval)==FP_ZERO){
		if(end==arg){
			fprintf(stderr,"Error: could not convert argument '%s' to a float.\n",arg);
			exit(BADARG_ERR);
		}else if(errno==ERANGE){
			fprintf(stderr,"Error: argument '%s' causes underflow.\n",arg);
			exit(UNDERFLOW_ERR);
		}
	}
	if(isinf(retval)){
		fprintf(stderr,"Error: argument '%s' causes overflow.\n",arg);
		exit(OVERFLOW_ERR);
	}else if(isnan(retval)){
		fprintf(stderr,"Error: argument '%s' is not a number.\n",arg);
		exit(NANARG_ERR);
	}
	return retval;
}
