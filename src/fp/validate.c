#include "../misc.h"
#include "validate.h"
#include "ieee.h"

//Evaluate the function at the given x-value
float quadfunc(float a,float c,float b,float x){
	return a*x*x+b*x+c;
}

//Check that the intercepts are solutions for the quadratic
bool validate(float a,float b,float c,intercepts x){
	//Check that both roots give a value of 0
	if(x.numroots==2)
		return	feq(quadfunc(a,b,c,x.low),0)
			&&feq(quadfunc(a,b,c,x.high),0);
	//Check that one root gives a value of 0
	else if(x.numroots==1)
		return feq(quadfunc(a,b,c,x.low),0);
	//No roots? No problem! No solutions!
	else
		return false;
}
