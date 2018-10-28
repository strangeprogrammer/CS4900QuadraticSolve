#include "../libraries.h"
#include "quadratic.h"
#include "../fp/ieee.h"
#include "../misc.h"

intercepts quadratic(float a,float b,float c){
	intercepts retval;
	float descrim=b*b-4*a*c;
	//Adjust for how many roots there are
	if(descrim<0){
		retval.numroots=0;
		return retval;
	}else{
		retval.numroots=1;
		retval.low=-b;
	}
	//Adjust numerator if appropriate
	if(!feq(descrim,0)){
		retval.numroots=2;
		retval.low-=sqrtf(descrim);
		retval.high=-b+sqrtf(descrim);
	}
	//Adjust denominator
	retval.low/=2*a;
	if(retval.numroots==2){
		retval.high/=2*a;
	}
	return retval;
}
