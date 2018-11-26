#include "../libraries.h"
#include "../misc.h"
#include "parsing.h"

bool checkargs(int argc){
	if(argc!=4){
		fprintf(stderr,err_str[NUMARG_ERR]);
		return false;
	}
	return true;
}

fpstatus getarg(char arg[]){
	char* end;
	errno=0;
	float parsed=strtof(arg,&end);
	fpstatus retval={.f=0,.e=SUCCESS};
	
	if(parsed==0||fpclassify(parsed)==FP_ZERO){
		if(end==arg){
			retval.e=BADARG_ERR;
		}else if(errno==ERANGE){
			retval.e=UNDERFLOW_ERR;
		}
	}else if(isinf(parsed)){
		retval.e=OVERFLOW_ERR;
	}else if(isnan(parsed)){
		retval.e=NANARG_ERR;
	}
	
	if(retval.e!=SUCCESS)
		fprintf(stderr,err_str[retval.e],arg);
	
	retval.f=parsed;
	
	return retval;
}
