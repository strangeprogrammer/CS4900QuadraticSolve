#include "linear.h"
#include "ieee.h"
#include "misc.h"

intercepts linear(float b,float c){
	intercepts retval;
	if(feq(b,0)){
		if(feq(c,0)){
			retval.low=0;
			retval.numroots=1;
		}else{
			retval.numroots=0;
		}
	}else{
		retval.low=-c/b;
		retval.numroots=1;
	}
	return retval;
}
