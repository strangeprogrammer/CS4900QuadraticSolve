#include "../libraries.h"
#include "../misc.h"
#include "convert.h"

//Converts the given string into a float, if possible
//'arg' must be null-terminated for correct functionality
err_code convert(char* arg,int arglen,float* dropbox){
	char* end;
	errno=0;
	*dropbox=strtof(arg,&end);
	
	if(*dropbox==0
	||fpclassify(*dropbox)==FP_ZERO){
		if(end-arg!=arglen){
			return BADARG_ERR;
		}else if(errno==ERANGE//If it's not an overflow yet still out of range
		&&!(*dropbox==HUGE_VALF
		||*dropbox==HUGE_VALL)){
			return UNDERFLOW_ERR;
		}
	}else if(fpclassify(*dropbox)==FP_SUBNORMAL){//Or it's classified as too small
		return UNDERFLOW_ERR;
	}else if(isinf(*dropbox)){
		return OVERFLOW_ERR;
	}else if(isnan(*dropbox)){
		return NANARG_ERR;
	}
	
	return SUCCESS;
}
