#include "libraries.h"
#include "misc.h"

bool isquad(float a,float b,float c){
	//Might have to expand upon this using 'feq' function
	return FP_ZERO!=fpclassify(a);
}
