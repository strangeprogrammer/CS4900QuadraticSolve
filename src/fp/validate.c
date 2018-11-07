#include "../misc.h"
#include "validate.h"
#include "ieee.h"

//Evaluate the function at the given x-value
float quadfunc(float a,float c,float b,float x){
	return a*x*x+b*x+c;
}

bool validate(float a,float b,float c,intercepts x){
	if(x.numroots==2)
		//Check that both roots give a value of 0
		return	feq(quadfunc(a,b,c,x.low),0)
			&&feq(quadfunc(a,b,c,x.high),0);
	else if(x.numroots==1)
		//Check that one root gives a value of 0
		return feq(quadfunc(a,b,c,x.low),0);
	else
		return false;
}
