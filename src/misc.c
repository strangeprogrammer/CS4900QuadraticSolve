#include "headers.h"

bool isquad(float a,float b,float c){
	//Might have to expand upon this using 'feq' function
	return FP_ZERO!=fp_classify(a);
}
