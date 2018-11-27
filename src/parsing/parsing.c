#include "../libraries.h"
#include "../misc.h"
#include "parsing.h"

#define BUFSIZE 1024
static char buffer[BUFSIZE];

//Print out a dumb prompt
bool prompt(int argnum){
	printf("Enter argument (default: 0) %d: ",argnum);
	return true;//Does this since it's used in 'getargs'
}

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

//Get a line from standard input, mess with it a little bit, and try to convert it to a float
err_code getarg(float* dropbox){
	//Get a line of input and make sure something was actually given
	if(!fgets(buffer,BUFSIZE,stdin)){
		return INTERNAL_ERR;
	}
	
	int line=strlen(buffer);
	if(line<1){
		return NOARG_ERR;
	}
	
	//Needed by 'convert'
	if(buffer[line-1]=='\n'){
		line--;
	}
	
	if(line<1){
		return NOARG_ERR;
	}
	
	return convert(buffer,line,dropbox);
}

err_code getargs(float* a,float* b,float* c){
	err_code passup;
	
	//Takes advantage of short-circuit evaluation
	//If any one of the 'getargs' doesn't work properly, return its error
	if((prompt(1)&&(passup=getarg(a))!=SUCCESS)
	||(prompt(2)&&(passup=getarg(b))!=SUCCESS)
	||(prompt(3)&&(passup=getarg(c))!=SUCCESS)){
		return passup;
	}
	
	return SUCCESS;
}
