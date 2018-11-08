#include "../libraries.h"
#include "quadratic.h"
#include "../fp/ieee.h"
#include "../misc.h"

//Returns intercept values and number of roots (yes, I could've coded this much more legibly)
intercepts quadratic(float a,float b,float c){
	intercepts retval;
	float descrim=b*b-4*a*c;
	//Adjust for how many roots there are
	if(descrim<0){//Negative Radical
		retval.numroots=0;
		return retval;
	}else{//Otherwise
		retval.numroots=1;
		retval.low=-b;//This is the only part of the numerator if there's only 1 root (at the vertex), so more math means less accuracy here
	}
	//Adjust numerator if appropriate
	if(!feq(descrim,0)){//More than 2 quadroots since there are 2 square roots for any positive, nonzero number
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
