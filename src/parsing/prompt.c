#include "../libraries.h"
#include "../misc.h"
#include "prompt.h"

//Print out a dumb prompt
bool prompt(int argnum){
	printf("Enter argument (default: 0) %d: ",argnum);
	return true;//Does this since it's used in 'getargs'
}
