#include "../libraries.h"
#include "../misc.h"

bool feq(float a,float b){
	if(fabsf(a-b)<0.0001){//Might have to change this constant
		return true;
	}
	return false;
}

bool isquad(float a,float b,float c){
	return fpclassify(a)!=FP_ZERO;
}
