#include "../libraries.h"
#include "../misc.h"
#include "prompt.h"
#include "../cunit/cunit.h"

int main(){
	cunit_init();
	
	prompt(0);
	if(fputc('\n',stdout)==EOF)
		return 2;
	prompt(1);
	if(fputc('\n',stdout)==EOF)
		return 3;
	prompt(-1);
	if(fputc('\n',stdout)==EOF)
		return 4;
	
	return 0;
}
