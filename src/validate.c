#include "misc.h"
#include "validate.h"
#include "ieee.h"

float quadfunc(float a,float c,float b,float x){
	return a*x*x+b*x+c;
}

bool validate(float a,float b,float c,intercepts x){
	return	x.numroots==2?
			feq(quadfunc(a,b,c,x.low),0)&&feq(quadfunc(a,b,c,x.high),0)
		:x.numroots==1?
			feq(quadfunc(a,b,c,x.low),0)
		:false;
}
