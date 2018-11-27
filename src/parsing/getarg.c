#include "../libraries.h"
#include "../misc.h"
#include "convert.h"
#include "getarg.h"

#define BUFSIZE 1024
static char buffer[BUFSIZE];

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
	
	//This is duplicated since that newline character can mess things up
	if(line<1){
		return NOARG_ERR;
	}
	
	return convert(buffer,line,dropbox);
}
